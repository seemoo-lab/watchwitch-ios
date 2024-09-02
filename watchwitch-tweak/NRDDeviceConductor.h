@interface NRDDeviceConductor : NSObject
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *queue;
@property(nonatomic) BOOL preferWiFiRequest;
@property(nonatomic) BOOL isEnabled;
@property(nonatomic) BOOL disablePreferWiFi;
@property(retain, nonatomic) NRLink *primaryLink;
@property(retain, nonatomic) NSMutableSet <NRLink *>*availableLinks;
@property(nonatomic) BOOL bringUpWiFiImmediately;
@property(nonatomic) BOOL hasPhoneCallRelayRequest;
@property (nonatomic,retain) NSUUID * nrUUID;
- (void)setPreferWiFiAllowedForTesting:(BOOL)arg1;
- (void)addSuspendBluetoothRequestWhenWiFiAvailable;
- (void)updatePrimaryLink;
- (void)setIPTunnelPolicyForLink:(id)arg1;
- (void)forceWoWMode;
- (void)suspendLinkOfType:(unsigned char)arg1;
- (void)resumeLinkOfType:(unsigned char)arg1;
- (void)setBringUpWiFiImmediatelyInner:(BOOL)arg1 timeout:(unsigned short)arg2 addSuspendBTRequest:(BOOL)arg3;
- (BOOL)sendPreferWiFiRequest:(BOOL)arg1 immediately:(BOOL)arg2 removeIfFailed:(BOOL)arg3 preferLinkType:(unsigned char)arg4 isAck:(BOOL)arg5 completion:(id /*block*/)arg6;
- (void)linkIsAvailable:(id)arg1;
- (void)sendHelloWithPreferredLink:(id)arg1 forced:(BOOL)arg2;
- (id)copyLinkOfType:(unsigned char)arg1;
- (id)copyPrimaryLink;
-(void)spoofWifiEndpointToWatch;
-(void)linkDidReceiveData:(id)arg1 data:(id)arg2;
@end
