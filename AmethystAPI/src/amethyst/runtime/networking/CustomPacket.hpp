#pragma once
#include <string>
#include <memory>
#include <mc/src/common/network/NetworkPeer.hpp>
#include <mc/src-deps/core/utility/Result.hpp>
#include <mc/src-deps/core/utility/BinaryStream.hpp>
#include <mc/src/common/network/packet/Packet.hpp>

class NetworkIdentifier;
class NetEventCallback;

namespace Amethyst {

class CustomPacket {
public:
    PacketPriority mPriority;
    NetworkPeer::Reliability mReliability;
    Compressibility mCompressible;

    CustomPacket()
        : mPriority(PacketPriority::MEDIUM_PRIORITY), mReliability(NetworkPeer::Reliability::ReliableOrdered), mCompressible(Compressibility::Compressible) {}

    virtual std::string getName() const = 0;
    virtual void write(BinaryStream& out) = 0;
    virtual Bedrock::Result<void, std::error_code> read(ReadOnlyBinaryStream& in) = 0;
};

class CustomPacketHandler {
public:
    virtual void handle(const NetworkIdentifier& networkId, NetEventCallback& callback, const Amethyst::CustomPacket& _packet) const = 0;
};

}