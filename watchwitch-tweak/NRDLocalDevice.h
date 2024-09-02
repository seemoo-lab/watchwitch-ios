/*
* This header is generated by classdump-dyld 1.0
* on Friday, May 5, 2023 at 3:05:04 PM Central European Summer Time
* Operating System: Version 14.8 (Build 18H17)
* Image Source: /usr/libexec/terminusd
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

@class NSUUID, NRDLDKeys, NSData, NSString, NSDate;

@interface NRDLocalDevice : NSObject <NSCopying, NSSecureCoding> {

	BOOL _isRegistered;
	BOOL _isEnabled;
	BOOL _hasConfirmedClassDKeys;
	BOOL _hasConfirmedClassCKeys;
	BOOL _hasConfirmedClassAKeys;
	BOOL _usesSPPLink;
	BOOL _wasInitiallySetupUsingIDSPairing;
	BOOL _isAltAccountDevice;
	BOOL _lastSeenAlwaysOnWiFiSupported;
	BOOL _isEmptyPairing;
	BOOL _hasSavedClassCKeysInKeychain;
	BOOL _hasSavedClassAKeysInKeychain;
	unsigned short _lastSeenInnerLinkVersionHBO;
	NSUUID* _nrUUID;
	NSUUID* _bluetoothUUID;
	NRDLDKeys* _classDKeys;
	NRDLDKeys* _classCKeys;
	NSData* _receivedProxyNotifyPayload;
	NSData* _outOfBandKey;
	NSData* _bluetoothMACAddress;
	NSString* _lastSeenName;
	NSString* _lastSeenBuildVersion;
	long long _pairingProtocolVersion;
	NSDate* _dateCreated;
	NSDate* _dateRegistered;
	NSDate* _dateEnabled;
	NRDLDKeys* _classAKeys;
	NSData* _localInnerIPv6AddressBytesClassD;
	NSData* _remoteInnerIPv6AddressBytesClassD;
	NSData* _localInnerIPv6AddressBytesClassC;
	NSData* _remoteInnerIPv6AddressBytesClassC;

}

@property (nonatomic,retain) NSUUID * nrUUID;                                         //@synthesize nrUUID=_nrUUID - In the implementation block
@property (nonatomic,retain) NSUUID * bluetoothUUID;                                  //@synthesize bluetoothUUID=_bluetoothUUID - In the implementation block
@property (assign,nonatomic) BOOL isRegistered;                                       //@synthesize isRegistered=_isRegistered - In the implementation block
@property (assign,nonatomic) BOOL isEnabled;                                          //@synthesize isEnabled=_isEnabled - In the implementation block
@property (assign,nonatomic) BOOL isEmptyPairing;                                     //@synthesize isEmptyPairing=_isEmptyPairing - In the implementation block
@property (assign,nonatomic) long long pairingProtocolVersion;                        //@synthesize pairingProtocolVersion=_pairingProtocolVersion - In the implementation block
@property (assign,nonatomic) BOOL wasInitiallySetupUsingIDSPairing;                   //@synthesize wasInitiallySetupUsingIDSPairing=_wasInitiallySetupUsingIDSPairing - In the implementation block
@property (assign,nonatomic) BOOL isAltAccountDevice;                                 //@synthesize isAltAccountDevice=_isAltAccountDevice - In the implementation block
@property (assign,nonatomic) unsigned short lastSeenInnerLinkVersionHBO;              //@synthesize lastSeenInnerLinkVersionHBO=_lastSeenInnerLinkVersionHBO - In the implementation block
@property (nonatomic,retain) NSString * lastSeenName;                                 //@synthesize lastSeenName=_lastSeenName - In the implementation block
@property (nonatomic,retain) NSString * lastSeenBuildVersion;                         //@synthesize lastSeenBuildVersion=_lastSeenBuildVersion - In the implementation block
@property (assign,nonatomic) BOOL lastSeenAlwaysOnWiFiSupported;                      //@synthesize lastSeenAlwaysOnWiFiSupported=_lastSeenAlwaysOnWiFiSupported - In the implementation block
@property (assign,nonatomic) BOOL usesSPPLink;                                        //@synthesize usesSPPLink=_usesSPPLink - In the implementation block
@property (nonatomic,retain) NSDate * dateCreated;                                    //@synthesize dateCreated=_dateCreated - In the implementation block
@property (nonatomic,retain) NSDate * dateRegistered;                                 //@synthesize dateRegistered=_dateRegistered - In the implementation block
@property (nonatomic,retain) NSDate * dateEnabled;                                    //@synthesize dateEnabled=_dateEnabled - In the implementation block
@property (nonatomic,retain) NRDLDKeys * classDKeys;                                  //@synthesize classDKeys=_classDKeys - In the implementation block
@property (nonatomic,retain) NRDLDKeys * classCKeys;                                  //@synthesize classCKeys=_classCKeys - In the implementation block
@property (nonatomic,retain) NRDLDKeys * classAKeys;                                  //@synthesize classAKeys=_classAKeys - In the implementation block
@property (assign,nonatomic) BOOL hasSavedClassCKeysInKeychain;                       //@synthesize hasSavedClassCKeysInKeychain=_hasSavedClassCKeysInKeychain - In the implementation block
@property (assign,nonatomic) BOOL hasSavedClassAKeysInKeychain;                       //@synthesize hasSavedClassAKeysInKeychain=_hasSavedClassAKeysInKeychain - In the implementation block
@property (assign,nonatomic) BOOL hasConfirmedClassDKeys;                             //@synthesize hasConfirmedClassDKeys=_hasConfirmedClassDKeys - In the implementation block
@property (assign,nonatomic) BOOL hasConfirmedClassCKeys;                             //@synthesize hasConfirmedClassCKeys=_hasConfirmedClassCKeys - In the implementation block
@property (assign,nonatomic) BOOL hasConfirmedClassAKeys;                             //@synthesize hasConfirmedClassAKeys=_hasConfirmedClassAKeys - In the implementation block
@property (nonatomic,retain) NSData * outOfBandKey;                                   //@synthesize outOfBandKey=_outOfBandKey - In the implementation block
@property (nonatomic,retain) NSData * bluetoothMACAddress;                            //@synthesize bluetoothMACAddress=_bluetoothMACAddress - In the implementation block
@property (nonatomic,retain) NSData * localInnerIPv6AddressBytesClassD;               //@synthesize localInnerIPv6AddressBytesClassD=_localInnerIPv6AddressBytesClassD - In the implementation block
@property (nonatomic,retain) NSData * remoteInnerIPv6AddressBytesClassD;              //@synthesize remoteInnerIPv6AddressBytesClassD=_remoteInnerIPv6AddressBytesClassD - In the implementation block
@property (nonatomic,retain) NSData * localInnerIPv6AddressBytesClassC;               //@synthesize localInnerIPv6AddressBytesClassC=_localInnerIPv6AddressBytesClassC - In the implementation block
@property (nonatomic,retain) NSData * remoteInnerIPv6AddressBytesClassC;              //@synthesize remoteInnerIPv6AddressBytesClassC=_remoteInnerIPv6AddressBytesClassC - In the implementation block
@property (nonatomic,retain) NSData * receivedProxyNotifyPayload;                     //@synthesize receivedProxyNotifyPayload=_receivedProxyNotifyPayload - In the implementation block
@property (nonatomic,readonly) BOOL isEnabledAndHasCompletedPairing; 
@property (nonatomic,readonly) BOOL hasCompletedPairing; 
@property (nonatomic,readonly) BOOL hasOutOfBandKey; 
+(void)initializeLocalDeviceDatabaseIfNecessary;
+(void)loadClassAKeys;
+(void)saveClassAKeysWithCompletion:(/*^block*/id)arg1 ;
+(void)saveAllDevicesToDisk;
+(void)saveAllDevicesToDiskWithClassA;
+(id)copyStatusString;
+(BOOL)supportsSecureCoding;
+(id)newLocalDeviceWithRandomNRUUID;
+(id)copyLocalDeviceForNRUUID:(id)arg1 ;
+(id)copyLocalDeviceForNRUUID:(id)arg1 shouldCreate:(BOOL)arg2 ;
+(id)copyLocalDeviceForBluetoothUUID:(id)arg1 ;
+(id)copyNRUUIDForBluetoothUUID:(id)arg1 ;
+(void)addAnalyticsForNRUUID:(id)arg1 nrUUID:(id)arg2 ;
+(id)getAnalyticsForNRUUID:(id)arg1 ;
+(void)removeAnalyticsForNRUUID:(id)arg1 ;
+(void)registerDeviceWithNRUUID:(id)arg1 pairingProtocolVersion:(long long)arg2 wasInitiallySetupUsingIDSPairing:(BOOL)arg3 outOfBandKey:(id)arg4 pairWithSPPLink:(BOOL)arg5 isAltAccountPairing:(BOOL)arg6 bluetoothMACAddress:(id)arg7 completionBlock:(/*^block*/id)arg8 ;
+(void)confirmKeysForClass:(unsigned char)arg1 nrUUID:(id)arg2 ;
+(void)reportRegistrationFailureCode:(long long)arg1 errorDescription:(id)arg2 forNRUUID:(id)arg3 ;
+(void)unregisterDeviceWithNRUUID:(id)arg1 completionBlock:(/*^block*/id)arg2 ;
+(void)unregisterAllDevicesWithCompletionBlock:(/*^block*/id)arg1 ;
+(void)enableDeviceWithNRUUID:(id)arg1 completionBlock:(/*^block*/id)arg2 ;
+(void)disableDeviceWithNRUUID:(id)arg1 completionBlock:(/*^block*/id)arg2 ;
+(id)copyDeviceListString;
+(BOOL)hasEnabledDevice;
+(id)copyEnabledNRUUIDs;
+(id)copyEnabledAndCompletedPairingNRUUIDs;
+(id)copyEnabledBluetoothUUIDs;
+(BOOL)hasEnabledBluetoothDevice;
+(id)copyBestTestingNRUUID;
+(id)copyEnabledSPPNRUUIDs;
+(id)copyEnabledSPPBluetoothMACAddresses;
+(BOOL)isEnabledSPPDeviceForMACAddress:(id)arg1 ;
+(id)copyLocalDeviceForSPPMACAddress:(id)arg1 ;
+(id)copySPPMACAddressForNRUUID:(id)arg1 ;
+(BOOL)hasEnabledSPPDevice;
+(void)queryPairingKeysForNRUUID:(id)arg1 minDataProtectionClass:(unsigned char)arg2 completionBlock:(/*^block*/id)arg3 ;
+(void)queryPairingFromIDSKeysForNRUUID:(id)arg1 minDataProtectionClass:(unsigned char)arg2 completionBlock:(/*^block*/id)arg3 ;
+(void)ingestRemoteClassDKeys:(id)arg1 nrUUID:(id)arg2 deviceCompletionBlock:(/*^block*/id)arg3 ;
+(void)ingestRemoteClassCKeys:(id)arg1 nrUUID:(id)arg2 deviceCompletionBlock:(/*^block*/id)arg3 ;
+(void)ingestRemoteClassAKeys:(id)arg1 nrUUID:(id)arg2 deviceCompletionBlock:(/*^block*/id)arg3 ;
+(void)ingestRemoteClassDKeysEncryptedWithIDS:(id)arg1 nrUUID:(id)arg2 deviceCompletionBlock:(/*^block*/id)arg3 ;
+(void)ingestRemoteClassCKeysEncryptedWithIDS:(id)arg1 nrUUID:(id)arg2 deviceCompletionBlock:(/*^block*/id)arg3 ;
+(void)ingestRemoteClassAKeysEncryptedWithIDS:(id)arg1 nrUUID:(id)arg2 deviceCompletionBlock:(/*^block*/id)arg3 ;
+(void)updateLastSeenInnerLinkVersionHBO:(unsigned short)arg1 nrUUID:(id)arg2 ;
+(void)updateLastSeenName:(id)arg1 nrUUID:(id)arg2 ;
+(void)updateLastSeenBuildVersion:(id)arg1 nrUUID:(id)arg2 ;
+(void)updateLastSeenAlwaysOnWiFiSupported:(BOOL)arg1 nrUUID:(id)arg2 ;
+(void)updateReceivedProxyNotifyPayload:(id)arg1 nrUUID:(id)arg2 ;
+(void)updateIsAltAccountDevice:(BOOL)arg1 nrUUID:(id)arg2 ;
+(id)createEndpointFromAddrData:(id)arg1 portString:(id)arg2 ;
+(id)createNewLocalClassDAddrData;
+(id)createNewRemoteClassDAddrData;
+(id)createTerminusPrefixEndpoint;
-(BOOL)hasCompletedPairing;
-(BOOL)isEnabledAndHasCompletedPairing;
-(id)copyKeys:(unsigned char)arg1 ;
-(NRDLDKeys *)classAKeys;
-(BOOL)hasOutOfBandKey;
-(BOOL)fillInClassDKeys;
-(void)fillInKeysForCurrentlyUnlockedWithForceClassA:(BOOL)arg1 ;
-(void)fillInClassCKeysWithCompletion:(/*^block*/id)arg1 ;
-(void)fillInClassAKeysWithCompletion:(/*^block*/id)arg1 ;
-(id)initWithNRUUID:(id)arg1 ;
-(id)description;
-(id)copyLongDescription;
-(id)copyWithZone:(NSZone*)arg1 ;
-(id)initWithCoder:(id)arg1 ;
-(void)encodeWithCoder:(id)arg1 ;
-(BOOL)hasReceivedRemoteClassDInnerAddress;
-(BOOL)hasReceivedRemoteClassCInnerAddress;
-(id)copyLocalClassDInnerEndpointWithPort:(id)arg1 ;
-(id)copyLocalClassCInnerEndpointWithPort:(id)arg1 ;
-(id)copyRemoteClassDInnerEndpointWithPort:(id)arg1 ;
-(id)copyRemoteClassCInnerEndpointWithPort:(id)arg1 ;
-(id)copyLocalClassDInnerEndpoint;
-(id)copyLocalClassCInnerEndpoint;
-(id)copyRemoteClassDInnerEndpoint;
-(id)copyRemoteClassCInnerEndpoint;
-(id)copyLocalClassDAddressString;
-(id)copyLocalClassCAddressString;
-(id)copyRemoteClassDAddressString;
-(id)copyRemoteClassCAddressString;
-(id)copyRemoteAddressStrings;
-(id)copyLocalInnerEndpointLinkLocal;
-(id)copyLocalLinkLocalAddressString;
-(id)copyLocalInnerAddresses;
-(void)reportEvent:(int)arg1 details:(id)arg2 ;
-(void)reportEvent:(int)arg1 detailsFormat:(id)arg2 ;
-(void)reportEvent:(int)arg1 ;
-(NSUUID *)nrUUID;
-(void)setNrUUID:(NSUUID *)arg1 ;
-(NSUUID *)bluetoothUUID;
-(void)setBluetoothUUID:(NSUUID *)arg1 ;
-(BOOL)isRegistered;
-(void)setIsRegistered:(BOOL)arg1 ;
-(BOOL)isEnabled;
-(void)setIsEnabled:(BOOL)arg1 ;
-(NRDLDKeys *)classDKeys;
-(void)setClassDKeys:(NRDLDKeys *)arg1 ;
-(NRDLDKeys *)classCKeys;
-(void)setClassCKeys:(NRDLDKeys *)arg1 ;
-(BOOL)hasConfirmedClassDKeys;
-(void)setHasConfirmedClassDKeys:(BOOL)arg1 ;
-(BOOL)hasConfirmedClassCKeys;
-(void)setHasConfirmedClassCKeys:(BOOL)arg1 ;
-(BOOL)hasConfirmedClassAKeys;
-(void)setHasConfirmedClassAKeys:(BOOL)arg1 ;
-(NSData *)receivedProxyNotifyPayload;
-(void)setReceivedProxyNotifyPayload:(NSData *)arg1 ;
-(NSData *)outOfBandKey;
-(void)setOutOfBandKey:(NSData *)arg1 ;
-(BOOL)usesSPPLink;
-(void)setUsesSPPLink:(BOOL)arg1 ;
-(NSData *)bluetoothMACAddress;
-(void)setBluetoothMACAddress:(NSData *)arg1 ;
-(BOOL)wasInitiallySetupUsingIDSPairing;
-(void)setWasInitiallySetupUsingIDSPairing:(BOOL)arg1 ;
-(BOOL)isAltAccountDevice;
-(void)setIsAltAccountDevice:(BOOL)arg1 ;
-(unsigned short)lastSeenInnerLinkVersionHBO;
-(void)setLastSeenInnerLinkVersionHBO:(unsigned short)arg1 ;
-(NSString *)lastSeenName;
-(void)setLastSeenName:(NSString *)arg1 ;
-(NSString *)lastSeenBuildVersion;
-(void)setLastSeenBuildVersion:(NSString *)arg1 ;
-(BOOL)lastSeenAlwaysOnWiFiSupported;
-(void)setLastSeenAlwaysOnWiFiSupported:(BOOL)arg1 ;
-(BOOL)isEmptyPairing;
-(void)setIsEmptyPairing:(BOOL)arg1 ;
-(long long)pairingProtocolVersion;
-(void)setPairingProtocolVersion:(long long)arg1 ;
-(NSDate *)dateCreated;
-(void)setDateCreated:(NSDate *)arg1 ;
-(NSDate *)dateRegistered;
-(void)setDateRegistered:(NSDate *)arg1 ;
-(NSDate *)dateEnabled;
-(void)setDateEnabled:(NSDate *)arg1 ;
-(void)setClassAKeys:(NRDLDKeys *)arg1 ;
-(BOOL)hasSavedClassCKeysInKeychain;
-(void)setHasSavedClassCKeysInKeychain:(BOOL)arg1 ;
-(BOOL)hasSavedClassAKeysInKeychain;
-(void)setHasSavedClassAKeysInKeychain:(BOOL)arg1 ;
-(NSData *)localInnerIPv6AddressBytesClassD;
-(void)setLocalInnerIPv6AddressBytesClassD:(NSData *)arg1 ;
-(NSData *)remoteInnerIPv6AddressBytesClassD;
-(void)setRemoteInnerIPv6AddressBytesClassD:(NSData *)arg1 ;
-(NSData *)localInnerIPv6AddressBytesClassC;
-(void)setLocalInnerIPv6AddressBytesClassC:(NSData *)arg1 ;
-(NSData *)remoteInnerIPv6AddressBytesClassC;
-(void)setRemoteInnerIPv6AddressBytesClassC:(NSData *)arg1 ;
@end
