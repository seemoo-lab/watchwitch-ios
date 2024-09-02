@interface IDSRegistrationKeyManager: NSObject

// Class Methods
+ (bool)setupKeys;
+ (id)sharedInstance;

// Instance Methods
- (struct MPFullIdentity *)latestCopyMessageProtectionIdentityForDataProtectionClass:(unsigned int)arg0;


@end