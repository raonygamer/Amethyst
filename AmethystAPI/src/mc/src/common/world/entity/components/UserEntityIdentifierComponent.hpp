#pragma once
#include <string>
#include <memory>
#include <mc/src/common/CommonTypes.hpp>
#include <mc/src/common/network/NetworkIdentifier.hpp>
#include <mc/src-deps/core/utility/UUID.hpp>

class Certificate {}; // unique_ptr needs complete type

class UserEntityIdentifierComponent {
public:
    NetworkIdentifier mNetworkId;
    SubClientId mSubClientId;
    mce::UUID mClientUUID;
    std::string mPlayfabId;
    std::unique_ptr<Certificate> mCertificate;
};