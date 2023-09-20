

typedef NS_ENUM(NSInteger, mk_sd_taskOperationID) {
    mk_sd_defaultTaskOperationID,
    
#pragma mark - Read
    mk_sd_taskReadDeviceModelOperation,        //读取产品型号
    mk_sd_taskReadFirmwareOperation,           //读取固件版本
    mk_sd_taskReadHardwareOperation,           //读取硬件类型
    mk_sd_taskReadSoftwareOperation,           //读取软件版本
    mk_sd_taskReadManufacturerOperation,       //读取厂商信息
    
#pragma mark - 自定义协议读取
    mk_sd_taskReadDeviceNameOperation,         //读取设备名称
    mk_sd_taskReadDeviceMacAddressOperation,    //读取MAC地址
    mk_sd_taskReadDeviceWifiSTAMacAddressOperation, //读取WIFI STA MAC地址
    mk_sd_taskReadNTPServerHostOperation,       //读取NTP服务器域名
    mk_sd_taskReadTimeZoneOperation,            //读取时区
    
#pragma mark - Wifi Params
    mk_sd_taskReadWIFISecurityOperation,        //读取设备当前wifi的加密模式
    mk_sd_taskReadWIFISSIDOperation,            //读取设备当前的wifi ssid
    mk_sd_taskReadWIFIPasswordOperation,        //读取设备当前的wifi密码
    mk_sd_taskReadWIFIEAPTypeOperation,         //读取设备当前的wifi EAP类型
    mk_sd_taskReadWIFIEAPUsernameOperation,     //读取设备当前的wifi EAP用户名
    mk_sd_taskReadWIFIEAPPasswordOperation,     //读取设备当前的wifi EAP密码
    mk_sd_taskReadWIFIEAPDomainIDOperation,     //读取设备当前的wifi EAP域名ID
    mk_sd_taskReadWIFIVerifyServerStatusOperation,  //读取是否校验服务器
    mk_sd_taskReadDHCPStatusOperation,              //读取DHCP开关
    mk_sd_taskReadNetworkIpInfosOperation,          //读取IP信息
    mk_sd_taskReadCountryBandOperation,             //读取国家地区参数
    
#pragma mark - MQTT Params
    mk_sd_taskReadServerHostOperation,          //读取MQTT服务器域名
    mk_sd_taskReadServerPortOperation,          //读取MQTT服务器端口
    mk_sd_taskReadClientIDOperation,            //读取Client ID
    mk_sd_taskReadServerUserNameOperation,      //读取服务器登录用户名
    mk_sd_taskReadServerPasswordOperation,      //读取服务器登录密码
    mk_sd_taskReadServerCleanSessionOperation,  //读取MQTT Clean Session
    mk_sd_taskReadServerKeepAliveOperation,     //读取MQTT KeepAlive
    mk_sd_taskReadServerQosOperation,           //读取MQTT Qos
    mk_sd_taskReadSubscibeTopicOperation,       //读取Subscribe topic
    mk_sd_taskReadPublishTopicOperation,        //读取Publish topic
    mk_sd_taskReadLWTStatusOperation,           //读取LWT开关状态
    mk_sd_taskReadLWTQosOperation,              //读取LWT Qos
    mk_sd_taskReadLWTRetainOperation,           //读取LWT Retain
    mk_sd_taskReadLWTTopicOperation,            //读取LWT topic
    mk_sd_taskReadLWTPayloadOperation,          //读取LWT Payload
    mk_sd_taskReadConnectModeOperation,         //读取MTQQ服务器通信加密方式
    
#pragma mark - Filter Params
    mk_sd_taskReadRssiFilterValueOperation,             //读取扫描RSSI过滤
    mk_sd_taskReadFilterRelationshipOperation,          //读取扫描过滤逻辑
    mk_sd_taskReadFilterMACAddressListOperation,        //读取MAC过滤列表
    mk_sd_taskReadFilterAdvNameListOperation,           //读取ADV Name过滤列表
    
#pragma mark - iBeacon Params
    mk_sd_taskReadAdvertiseBeaconStatusOperation,       //读取iBeacon开关
    mk_sd_taskReadBeaconMajorOperation,                 //读取iBeacon major
    mk_sd_taskReadBeaconMinorOperation,                 //读取iBeacon minor
    mk_sd_taskReadBeaconUUIDOperation,                  //读取iBeacon UUID
    mk_sd_taskReadBeaconAdvIntervalOperation,           //读取Adv interval
    mk_sd_taskReadBeaconTxPowerOperation,               //读取Tx Power
    
    
#pragma mark - 密码特征
    mk_sd_connectPasswordOperation,             //连接设备时候发送密码
    
#pragma mark - 配置
    mk_sd_taskEnterSTAModeOperation,                //设备重启进入STA模式
    mk_sd_taskConfigNTPServerHostOperation,         //配置NTP服务器域名
    mk_sd_taskConfigTimeZoneOperation,              //配置时区
    mk_sd_taskConfigDeviceTimeOperation,            //配置UTC时间戳
    
#pragma mark - Wifi Params
    
    mk_sd_taskConfigWIFISecurityOperation,      //配置wifi的加密模式
    mk_sd_taskConfigWIFISSIDOperation,          //配置wifi的ssid
    mk_sd_taskConfigWIFIPasswordOperation,      //配置wifi的密码
    mk_sd_taskConfigWIFIEAPTypeOperation,       //配置wifi的EAP类型
    mk_sd_taskConfigWIFIEAPUsernameOperation,   //配置wifi的EAP用户名
    mk_sd_taskConfigWIFIEAPPasswordOperation,   //配置wifi的EAP密码
    mk_sd_taskConfigWIFIEAPDomainIDOperation,   //配置wifi的EAP域名ID
    mk_sd_taskConfigWIFIVerifyServerStatusOperation,    //配置wifi是否校验服务器
    mk_sd_taskConfigWIFICAFileOperation,                //配置WIFI CA证书
    mk_sd_taskConfigWIFIClientCertOperation,            //配置WIFI设备证书
    mk_sd_taskConfigWIFIClientPrivateKeyOperation,      //配置WIFI私钥
    mk_sd_taskConfigDHCPStatusOperation,                //配置DHCP开关
    mk_sd_taskConfigIpInfoOperation,                    //配置IP地址相关信息
    mk_sd_taskConfigCountryBandOperation,               //配置国家地区参数
    
#pragma mark - MQTT Params
    mk_sd_taskConfigServerHostOperation,        //配置MQTT服务器域名
    mk_sd_taskConfigServerPortOperation,        //配置MQTT服务器端口
    mk_sd_taskConfigClientIDOperation,              //配置ClientID
    mk_sd_taskConfigServerUserNameOperation,        //配置服务器的登录用户名
    mk_sd_taskConfigServerPasswordOperation,        //配置服务器的登录密码
    mk_sd_taskConfigServerCleanSessionOperation,    //配置MQTT Clean Session
    mk_sd_taskConfigServerKeepAliveOperation,       //配置MQTT KeepAlive
    mk_sd_taskConfigServerQosOperation,             //配置MQTT Qos
    mk_sd_taskConfigSubscibeTopicOperation,         //配置Subscribe topic
    mk_sd_taskConfigPublishTopicOperation,          //配置Publish topic
    mk_sd_taskConfigLWTStatusOperation,             //配置LWT开关
    mk_sd_taskConfigLWTQosOperation,                //配置LWT Qos
    mk_sd_taskConfigLWTRetainOperation,             //配置LWT Retain
    mk_sd_taskConfigLWTTopicOperation,              //配置LWT topic
    mk_sd_taskConfigLWTPayloadOperation,            //配置LWT payload
    mk_sd_taskConfigConnectModeOperation,           //配置MTQQ服务器通信加密方式
    mk_sd_taskConfigCAFileOperation,                //配置CA证书
    mk_sd_taskConfigClientCertOperation,            //配置设备证书
    mk_sd_taskConfigClientPrivateKeyOperation,      //配置私钥
        
#pragma mark - 过滤参数
    mk_sd_taskConfigRssiFilterValueOperation,                   //配置扫描RSSI过滤
    mk_sd_taskConfigFilterRelationshipOperation,                //配置扫描过滤逻辑
    mk_sd_taskConfigFilterMACAddressListOperation,           //配置MAC过滤规则
    mk_sd_taskConfigFilterAdvNameListOperation,             //配置Adv Name过滤规则
    
#pragma mark - 蓝牙广播参数
    mk_sd_taskConfigAdvertiseBeaconStatusOperation,         //配置iBeacon开关
    mk_sd_taskConfigBeaconMajorOperation,                   //配置iBeacon major
    mk_sd_taskConfigBeaconMinorOperation,                   //配置iBeacon minor
    mk_sd_taskConfigBeaconUUIDOperation,                    //配置iBeacon UUID
    mk_sd_taskConfigAdvIntervalOperation,                   //配置广播频率
    mk_sd_taskConfigTxPowerOperation,                       //配置Tx Power
};

