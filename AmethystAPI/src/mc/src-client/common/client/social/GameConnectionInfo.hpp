#pragma once
#include <string>
#include <unordered_set>
#include <mc/src-deps/raknet/RakNetGUID.hpp>

class ThirdPartyInfo {
public:
    std::unordered_set<std::string> mAllowListUrls;
    std::string mCreatorId;
    std::string mCreatorName;
    std::string mStorePageId;
    bool mRequireXBL;
};

class GatheringServerInfo {
public:
    std::string mGatheringId;
    std::string mGatheringIdAsCreatorName;
    std::string mUrl;
    std::string mTitle;
    int mPort;
};

namespace Social {
    enum class ConnectionType : int16_t {
        Undefined = 0xff,
        Local = 0x0000,
        IPv4 = 0x0001,
        IPv6 = 0x0002,
        NAT = 0x0003,
        UPNP = 0x0004,
        UnknownIP = 0x0005,
    };

    class GameConnectionInfo {
    public:
        ConnectionType mType;
        std::string mHostIpAddress;
        std::string mUnresolvedUrl;
        int mPort;
        RakNet::RakNetGUID mRakNetGUID;
        unsigned __int64 mNetherNetId;
        ThirdPartyInfo mThirdPartyServerInfo;
        GatheringServerInfo mGatheringServerInfo;
        bool mAllowSmallDownloads;
    };
}