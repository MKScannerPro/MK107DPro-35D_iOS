
typedef NS_ENUM(NSInteger, mk_sd_centralConnectStatus) {
    mk_sd_centralConnectStatusUnknow,                                           //未知状态
    mk_sd_centralConnectStatusConnecting,                                       //正在连接
    mk_sd_centralConnectStatusConnected,                                        //连接成功
    mk_sd_centralConnectStatusConnectedFailed,                                  //连接失败
    mk_sd_centralConnectStatusDisconnect,
};

typedef NS_ENUM(NSInteger, mk_sd_centralManagerStatus) {
    mk_sd_centralManagerStatusUnable,                           //不可用
    mk_sd_centralManagerStatusEnable,                           //可用状态
};


typedef NS_ENUM(NSInteger, mk_sd_wifiSecurity) {
    mk_sd_wifiSecurity_personal,
    mk_sd_wifiSecurity_enterprise,
};

typedef NS_ENUM(NSInteger, mk_sd_eapType) {
    mk_sd_eapType_peap_mschapv2,
    mk_sd_eapType_ttls_mschapv2,
    mk_sd_eapType_tls,
};

typedef NS_ENUM(NSInteger, mk_sd_connectMode) {
    mk_sd_connectMode_TCP,                                          //TCP
    mk_sd_connectMode_CASignedServerCertificate,                    //SSL.Do not verify the server certificate.
    mk_sd_connectMode_CACertificate,                                //SSL.Verify the server's certificate
    mk_sd_connectMode_SelfSignedCertificates,                       //SSL.Two-way authentication
};

//Quality of MQQT service
typedef NS_ENUM(NSInteger, mk_sd_mqttServerQosMode) {
    mk_sd_mqttQosLevelAtMostOnce,      //At most once. The message sender to find ways to send messages, but an accident and will not try again.
    mk_sd_mqttQosLevelAtLeastOnce,     //At least once.If the message receiver does not know or the message itself is lost, the message sender sends it again to ensure that the message receiver will receive at least one, and of course, duplicate the message.
    mk_sd_mqttQosLevelExactlyOnce,     //Exactly once.Ensuring this semantics will reduce concurrency or increase latency, but level 2 is most appropriate when losing or duplicating messages is unacceptable.
};

typedef NS_ENUM(NSInteger, mk_sd_filterRelationship) {
    mk_sd_filterRelationship_null,
    mk_sd_filterRelationship_mac,
    mk_sd_filterRelationship_advName,
    mk_sd_filterRelationship_rawData,
    mk_sd_filterRelationship_advNameAndRawData,
    mk_sd_filterRelationship_macAndadvNameAndRawData,
    mk_sd_filterRelationship_advNameOrRawData,
    mk_sd_filterRelationship_advNameAndMacData,
};


@protocol mk_sd_centralManagerScanDelegate <NSObject>

/// Scan to new device.
/// @param deviceModel device
- (void)mk_sd_receiveDevice:(NSDictionary *)deviceModel;

@optional

/// Starts scanning equipment.
- (void)mk_sd_startScan;

/// Stops scanning equipment.
- (void)mk_sd_stopScan;

@end
