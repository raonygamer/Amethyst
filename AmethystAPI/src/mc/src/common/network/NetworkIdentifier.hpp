#pragma once
#include <mc/src-deps/raknet/RakNetGUID.hpp>
#include <cstdint>

class NetworkIdentifier {
public:
    enum class Type : int {
        RakNet    = 0,
        Address   = 1,
        Address6  = 2,
        NetherNet = 3,
        Invalid   = 4,
    };

    uint64_t mNetherNetId;
    RakNet::RakNetGUID mRakNetGuid;
    std::byte mSock[128]; // sockaddr_storage
    Type mType;
};