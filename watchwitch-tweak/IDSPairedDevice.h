@interface IDSPairedDevice: NSObject

@property (readonly, nonatomic) NSString * buildVersion;
@property (readonly, nonatomic) unsigned long long capabilityFlags;
@property (readonly, nonatomic) NSString * cbuuid;
@property (readonly, nonatomic) NSDictionary * dictionaryRepresentation;
@property (readonly, nonatomic) bool hasAllPublicKeys;
@property (readonly, nonatomic) bool hasCapabilityFlags;
@property (readonly, nonatomic) bool isActive;
@property (readonly, nonatomic) bool isPairing;
@property (readonly, nonatomic) unsigned int maxCompatibilityVersion;
@property (readonly, nonatomic) unsigned int minCompatibilityVersion;
@property (readonly, nonatomic) unsigned int pairingProtocolVersion;
@property (readonly, nonatomic) NSDictionary * privateData;
@property (readonly, nonatomic) NSString * productName;
@property (readonly, nonatomic) NSString * productVersion;
@property (readonly, nonatomic) NSData * publicClassAKey;
@property (readonly, nonatomic) NSData * publicClassCKey;
@property (readonly, nonatomic) NSData * publicClassDKey;
@property (readonly, nonatomic) NSData * pushToken;
@property (readonly, nonatomic) unsigned int serviceMinCompatibilityVersion;
@property (readonly, nonatomic) NSString * shortDescription;
@property (readonly, nonatomic) NSString * uniqueID;


// Class Methods


// Instance Methods
- (id)buildVersion;
- (unsigned long long)capabilityFlags;
- (id)cbuuid;
- (id)description;
- (id)dictionaryRepresentation;
- (bool)hasAllPublicKeys;
- (bool)hasCapabilityFlags;
- (id)initWithCBUUID:(id)arg0;
- (id)initWithPairedDevice:(id)arg0 capabilityFlags:(unsigned long long)arg1;
- (id)initWithPairedDevice:(id)arg0 deviceInfoPayload:(id)arg1;
- (id)initWithPairedDevice:(id)arg0 deviceUniqueID:(id)arg1 pairingProtocolVersion:(unsigned int)arg2 minCompatibilityVersion:(unsigned int)arg3 maxCompatibilityVersion:(unsigned int)arg4 serviceMinCompatibilityVersion:(unsigned short)arg5 privateData:(id)arg6;
- (id)initWithPairedDevice:(id)arg0 isActive:(bool)arg1;
- (id)initWithProperties:(id)arg0;
- (id)initWithProperties:(id)arg0 pairingProtocolVersion:(id)arg1 minCompatibilityVersion:(id)arg2 maxCompatibilityVersion:(id)arg3 serviceMinCompatibilityVersion:(id)arg4 capabilityFlags:(id)arg5;
- (bool)isActive;
- (bool)isPairing;
- (unsigned int)maxCompatibilityVersion;
- (unsigned int)minCompatibilityVersion;
- (id)pairedDeviceWithoutSecuredEncryptionKeys;
- (unsigned int)pairingProtocolVersion;
- (id)persistedProperties;
- (id)privateData;
- (id)productName;
- (id)productVersion;
- (id)publicClassAKey;
- (id)publicClassCKey;
- (id)publicClassDKey;
- (id)pushToken;
- (unsigned int)serviceMinCompatibilityVersion;
- (id)shortDescription;
- (id)uniqueID;

@end