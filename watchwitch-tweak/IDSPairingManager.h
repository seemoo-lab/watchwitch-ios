@interface IDSPairingManager: NSObject

@property (readonly, nonatomic) NSSet * allPairedUniqueIDs;
@property (readonly, nonatomic) bool isPaired;
@property (readonly, nonatomic) NSDictionary * localDevice;
@property (readonly, nonatomic) NSDictionary * pairedDevice;
@property (readonly, nonatomic) unsigned int pairedDeviceMaxCompatibilityVersion;
@property (readonly, nonatomic) unsigned int pairedDeviceMinCompatibilityVersion;
@property (readonly, nonatomic) unsigned int pairedDevicePairingProtocolVersion;
@property (readonly, nonatomic) NSDictionary * pairedDevicePrivateData;
@property (readonly, nonatomic) NSData * pairedDevicePublicClassAKey;
@property (readonly, nonatomic) NSData * pairedDevicePublicClassCKey;
@property (readonly, nonatomic) NSData * pairedDevicePublicKey;
@property (readonly, nonatomic) NSData * pairedDevicePushToken;
@property (readonly, nonatomic) unsigned short pairedDeviceServiceMinCompatibilityVersion;
@property (readonly, nonatomic) NSString * pairedDeviceUUIDString;
@property (readonly, nonatomic) NSString * pairedDeviceUniqueID;


// Class Methods
+ (id)sharedInstance;


// Instance Methods
- (id)_activePairedDeviceCBUUID;
- (id)_cbuuidsWithIsPairingValue:(bool)arg0;
- (bool)_hasAllEncryptionKeys;
- (bool)_hasPairedDeviceCapabilityFlags;
- (unsigned long long)_hasRegeneratedSecuredEncryptionKeys;
- (bool)_isPairedToDevice:(id)arg0;
- (void)_loadPairedDevicePropertiesIfNeeded;
- (id)_localDevicePrivateData;
- (bool)_markSecuredEncryptionKeysAsRegenerated:(bool)arg0;
- (long long)_migrateSecuredEncryptionKeys;
- (void)_notifyDelegatesDevicePairedToDevice:(id)arg0;
- (void)_notifyDelegatesDeviceUnpairedFromDevice:(id)arg0;
- (void)_notifyDelegatesWithBlock:(id /* block */)arg0;
- (unsigned long long)_pairedDeviceCapabilityFlags;
- (bool)_purgeSecuredEncryptionKeysForAllPairedDevices;
- (void)_regenerateSecuredEncryptionKeys;
- (void)_regenerateSecuredEncryptionKeysWithCapabilityFlags:(unsigned long long)arg0;
- (void)_requestPairedDeviceInfo;
- (void)_requestPairedDeviceInfoAfterDelay:(double)arg0;
- (void)_setPairedDeviceCapabilityFlags:(unsigned long long)arg0;
- (long long)_statusOfSecuredEncryptionKeyRegenerationWithCapabilityFlags:(unsigned long long)arg0;
- (void)_suspendOTRSessionsWithProtectionClass:(unsigned int)arg0;
- (void)_updateActiveStateForAllPairedDevices;
- (void)_updateActiveStateForAllPairedDevices:(bool)arg0;
- (void)_updatePairedState:(bool)arg0;
- (long long)activatePairedDeviceWithCBUUID:(id)arg0;
- (void)addDelegate:(id)arg0;
- (bool)addLocalPairedDevice:(id)arg0;
- (id)allPairedUniqueIDs;
- (id)cbuuidsOfPairedDevices;
- (id)cbuuidsOfPairingDevices;
- (void)deactivatePairedDevices;
- (void)dealloc;
- (id)description;
- (void)ensureCommunicationWithActivePairedDeviceIsPossible;
- (void)gatherLocalDeviceInfoWithCompletionBlock:(id /* block */)arg0;
- (id)init;
- (bool)isCurrentDevicePairedOrPairing;
- (bool)isMissingAnyPublicKeyForPairedDeviceWithCBUUID:(id)arg0;
- (bool)isPaired;
- (id)localDevice;
- (id)pairedDevice;
- (id)pairedDeviceBuildVersion;
- (id)pairedDeviceForUniqueID:(id)arg0;
- (unsigned int)pairedDeviceMaxCompatibilityVersion;
- (unsigned int)pairedDeviceMinCompatibilityVersion;
- (unsigned int)pairedDevicePairingProtocolVersion;
- (id)pairedDevicePrivateData;
- (id)pairedDeviceProductName;
- (id)pairedDeviceProductVersion;
- (id)pairedDevicePublicClassAKey;
- (id)pairedDevicePublicClassCKey;
- (id)pairedDevicePublicKey;
- (id)pairedDevicePushToken;
- (unsigned short)pairedDeviceServiceMinCompatibilityVersion;
- (id)pairedDeviceUUIDString;
- (id)pairedDeviceUniqueID;
- (void)refreshPairedDeviceEncryptionKeys;
- (void)removeDelegate:(id)arg0;
- (bool)removeLocalPairedDevice:(id)arg0;
- (void)savedGeneratedClassKeys:(id)arg0;
- (bool)setPairedDeviceInfo:(id)arg0;
- (void)systemDidLeaveDataProtectionLock;
- (void)systemDidLeaveFirstDataProtectionLock;

@end