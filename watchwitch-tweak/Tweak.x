#import <Cephei/HBPreferences.h>
#import <NetworkExtension/NWHostEndpoint.h>
#import <objc/runtime.h>
#import "LinkDirectorMessage.h"
#import "NRDDeviceConductor.h"
#import "NRLinkDirector.h"
#import "NWAddressEndpoint.h"
#import "NRLink.h"
#import "NRDLocalDevice.h"
#import "NRDLDKeys.h"
#import "IDSPairingManager.h"
#import "IDSPairedDevice.h"
#import "IDSRegistrationKeyManager.h"

HBPreferences *preferences;
BOOL rerouteEnabled;
BOOL startupComplete = false;
BOOL keyExtractStartupComplete = false;
NSInteger spoofTrigger = 0;
unsigned int targetIP = 0;
unsigned int keyUpdateTrigger = 0;

int stringendswith(const char *s, const char *t) {
    size_t slen = strlen(s);
    size_t tlen = strlen(t);
    if (tlen > slen) return 1;
    return strcmp(s + slen - tlen, t) == 0;
}

%ctor {

    preferences = [[HBPreferences alloc] initWithIdentifier:@"net.rec0de.ios.watchwitch"];
    
    // main tweak functionality is in terminusd
    if(stringendswith(argv[0], "terminusd")){
        NSLog(@"WWitch: starting terminusd component");

        [preferences registerDefaults:@{
            @"targetIP": @0u
        }];

        // communicate tweak start time to companion app
        NSDate *date = [NSDate date];
        double timestamp = date.timeIntervalSince1970;
        NSLog(@"WWitch: start time %f", timestamp);
        [preferences setDouble: timestamp forKey:@"tweakStarted"];

        [preferences registerBool:&rerouteEnabled default:NO forKey:@"reroute"];
        NSLog(@"WWitch: Rerouting enabled? %i", rerouteEnabled);

        // trigger preference sync
        NSString *notificationName = @"net.rec0de.ios.watchwitch/ReloadPrefs";
        CFNotificationCenterPostNotification(CFNotificationCenterGetDarwinNotifyCenter(), (CFNotificationName) notificationName, nil, nil, true);

        // we have to run NRDDeviceConductor code from an appropriate queue for it to work
        // this block will be called when we manually send a wifi address update
        dispatch_block_t manualSpoofBlock = dispatch_block_create(DISPATCH_BLOCK_INHERIT_QOS_CLASS, ^{
            NRLinkDirector *director = [objc_getClass("NRLinkDirector") copySharedLinkDirector];

            for (NRDDeviceConductor *conductor in director.conductors.allValues){
                [conductor spoofWifiEndpointToWatch];
            }
        });

        // when we want to manually send an update, the companion app will update the spoofTrigger preference, which triggers this block
        [preferences registerPreferenceChangeBlockForKey:@"spoofTrigger" block:^(NSString *key, id<NSCopying> _Nullable value){
            // observer block is triggered once on startup, we'll want to ignore that
            if (!startupComplete){
                startupComplete = true;
                return;
            }

            NSLog(@"WWitch: spoofTrigger");
            NRLinkDirector *director = [objc_getClass("NRLinkDirector") copySharedLinkDirector];
            dispatch_async([director queue], manualSpoofBlock);
        }];

        // log changes to target ip setting, not really necessary
        [preferences registerPreferenceChangeBlockForKey:@"targetIP" block:^(NSString *key, id<NSCopying> _Nullable value){
            NSLog(@"WWitch: Target IP %#010x", (unsigned int) [preferences unsignedIntegerForKey:@"targetIP"]);
        }];

        // we call this block to load key material into the preferences to be read by the companion app
        dispatch_block_t extractKeysBlock = dispatch_block_create(DISPATCH_BLOCK_INHERIT_QOS_CLASS, ^{
            NRLinkDirector *director = [objc_getClass("NRLinkDirector") copySharedLinkDirector];

            NSUUID *uuid = nil;
      
            // idk why there can be multiple directors but let's just get one UUID for now
            for (NRDDeviceConductor *conductor in director.conductors.allValues){
                uuid = conductor.nrUUID;
            }

            NRDLocalDevice *device = [objc_getClass("NRDLocalDevice") copyLocalDeviceForNRUUID:uuid];
                
            NRDLDKeys *classAKeys = [device copyKeys:0x01];
            NRDLDKeys *classCKeys = [device copyKeys:0x03];
            NRDLDKeys *classDKeys = [device copyKeys:0x04];

            NSData *publicClassA = (NSData *) [classAKeys remotePublicKey];
            NSData *publicClassC = (NSData *) [classCKeys remotePublicKey];
            NSData *publicClassD = (NSData *) [classDKeys remotePublicKey];

            NSData *privateClassA = (NSData *) [classAKeys localPrivateKey];
            NSData *privateClassC = (NSData *) [classCKeys localPrivateKey];
            NSData *privateClassD = (NSData *) [classDKeys localPrivateKey];

            NSString *localAddressClassC = (NSString *) [device copyLocalClassCAddressString];
            NSString *localAddressClassD = (NSString *) [device copyLocalClassDAddressString];

            NSString *remoteAddressClassC = (NSString *) [device copyRemoteClassCAddressString];
            NSString *remoteAddressClassD = (NSString *) [device copyRemoteClassDAddressString];

            NSLog(@"WWitch: local class C address %@", localAddressClassC);
            NSLog(@"WWitch: local class D address %@", localAddressClassD);
            NSLog(@"WWitch: remote class C address %@", remoteAddressClassC);
            NSLog(@"WWitch: remote class D address %@", remoteAddressClassD);

            [preferences setObject: publicClassA forKey:@"publicClassA"];
            [preferences setObject: publicClassC forKey:@"publicClassC"];
            [preferences setObject: publicClassD forKey:@"publicClassD"];

            [preferences setObject: privateClassA forKey:@"privateClassA"];
            [preferences setObject: privateClassC forKey:@"privateClassC"];
            [preferences setObject: privateClassD forKey:@"privateClassD"];

            [preferences setObject: localAddressClassC forKey:@"localAddressClassC"];
            [preferences setObject: localAddressClassD forKey:@"localAddressClassD"];
            [preferences setObject: remoteAddressClassC forKey:@"remoteAddressClassC"];
            [preferences setObject: remoteAddressClassD forKey:@"remoteAddressClassD"];

            keyUpdateTrigger++;
            [preferences setUnsignedInteger: keyUpdateTrigger forKey:@"keysupdated"];
            NSLog(@"WWitch: set keysupdated to %u", keyUpdateTrigger);


            NSString *notificationName = @"net.rec0de.ios.watchwitch/ReloadPrefs";
            CFNotificationCenterPostNotification(CFNotificationCenterGetDarwinNotifyCenter(), (CFNotificationName) notificationName, nil, nil, true);
        });

        [preferences registerPreferenceChangeBlockForKey:@"keyExtractTrigger" block:^(NSString *key, id<NSCopying> _Nullable value){
            // observer block is triggered once on startup, we'll want to ignore that
            if (!keyExtractStartupComplete){
                keyExtractStartupComplete = true;
                return;
            }

            NSLog(@"WWitch: terminus key extract");
            NRLinkDirector *director = [objc_getClass("NRLinkDirector") copySharedLinkDirector];
            dispatch_async([director queue], extractKeysBlock);
        }];
    }
    // we only hook identityservices to extract device UID and keys
    else if(stringendswith(argv[0], "identityservicesd")) {
        NSLog(@"WWitch: starting identityservicesd component");

        // trigger preference sync
        NSString *notificationName = @"net.rec0de.ios.watchwitch/ReloadPrefs";
        CFNotificationCenterPostNotification(CFNotificationCenterGetDarwinNotifyCenter(), (CFNotificationName) notificationName, nil, nil, true);

        [preferences registerPreferenceChangeBlockForKey:@"keyExtractTrigger" block:^(NSString *key, id<NSCopying> _Nullable value){
            // observer block is triggered once on startup, we'll want to ignore that
            if (!keyExtractStartupComplete){
                keyExtractStartupComplete = true;
                return;
            }

            NSLog(@"WWitch: IDS key extract");

            IDSPairingManager *pairingManager = [objc_getClass("IDSPairingManager") sharedInstance];
            //NSSet *allPairedUUIDs = [pairingManager allPairedUniqueIDs];
            NSDictionary *localDevice = [pairingManager localDevice];
            NSDictionary *pairedDevice = [pairingManager pairedDevice];

            NSString *localUUID = localDevice[@"ids-identifier"];
            NSLog(@"WWitch: local UUID %@", localUUID);
            [preferences setObject: localUUID forKey:@"idsLocalUUID"];
            


            IDSRegistrationKeyManager *keyManager = [objc_getClass("IDSRegistrationKeyManager") sharedInstance];

            // Class A: 1, Class C: 0, Class D: 2
            void *fi = [keyManager latestCopyMessageProtectionIdentityForDataProtectionClass:1];

            SecKeyRef *ecdsaPriv = (SecKeyRef *) (fi+0x18);
            SecKeyRef *rsaPriv = (SecKeyRef *) (fi+0x28);
            NSData *ecdsaPrivExported = CFBridgingRelease(SecKeyCopyExternalRepresentation(*ecdsaPriv, 0));
            NSData *rsaPrivExported = CFBridgingRelease(SecKeyCopyExternalRepresentation(*rsaPriv, 0));
            NSLog(@"WWitch: ecdsaPriv %@", ecdsaPrivExported);
            NSLog(@"WWitch: rsaPriv %@", rsaPrivExported);
            [preferences setObject: ecdsaPrivExported forKey:@"idsLocalClassAEcdsa"];
            [preferences setObject: rsaPrivExported forKey:@"idsLocalClassARsa"];


            if(pairedDevice == 0) {
                NSLog(@"WWitch: pairedDevice is null, are you connected to an apple watch?");
            }
            else {
                NSLog(@"WWitch: got paired device");
                NSString *pairedUUID = pairedDevice[@"ids-identifier-override"];
                IDSPairedDevice *pairedDeviceObj = [pairingManager pairedDeviceForUniqueID:pairedUUID];
                NSLog(@"WWitch: paired UUID %@", pairedUUID);
                //NSLog(@"WWitch: paired device obj %@", pairedDeviceObj);
                NSString *encodedClassAPublic = [[pairedDeviceObj publicClassAKey] base64EncodedStringWithOptions:0];
                NSLog(@"WWitch: paired classA %@", encodedClassAPublic);
                [preferences setObject: encodedClassAPublic forKey:@"idsRemoteClassA"];
            }

            NSString *notificationName = @"net.rec0de.ios.watchwitch/ReloadPrefs";
            CFNotificationCenterPostNotification(CFNotificationCenterGetDarwinNotifyCenter(), (CFNotificationName) notificationName, nil, nil, true);
        }];
    }
}

// extend NRDDeviceConductor to add wifi address spoofing method
%hook NRDDeviceConductor

%new
-(void)spoofWifiEndpointToWatch {
	NSLog(@"WWitch: Attempting to spoof WiFi endpoint to watch");

	struct sockaddr_in sadr;
	memset(&sadr, 0, sizeof(sadr));
	sadr.sin_len = sizeof(sadr);
	sadr.sin_family = AF_INET;
	sadr.sin_addr.s_addr = htonl((unsigned int) [preferences unsignedIntegerForKey:@"targetIP"]);

	NWHostEndpoint *endpoint = [objc_getClass("NWAddressEndpoint") endpointWithAddress:(const struct sockaddr*)&sadr];

	NRLinkDirectorMessage *msg = [[objc_getClass("NRLinkDirectorMessage") alloc] initOutgoingDirectorMessageWithNRUUID:self.nrUUID];
	[msg addUpdateWiFiAddressEndpoint:(id)endpoint portHBO:(unsigned short)0x1388];
	[msg send];
}

%end


// overwrite original wifi address in legitimate update packets
%hook NRLinkDirectorMessage

-(void)addUpdateWiFiAddressEndpoint:(id)endpoint portHBO:(unsigned short)port {
	// hijack organic address updates to carry our IP instead
	if(rerouteEnabled) {
		NSLog(@"WWitch: Overriding legitimate WiFi Address Update");
		port = 0x1388;
		NWAddressEndpoint *nwe = (NWAddressEndpoint *) endpoint;
		struct sockaddr_in *adr = (struct sockaddr_in *) [nwe address];
		adr->sin_addr.s_addr = htonl((unsigned int) [preferences unsignedIntegerForKey:@"targetIP"]);
	}
	return %orig;
}

%end