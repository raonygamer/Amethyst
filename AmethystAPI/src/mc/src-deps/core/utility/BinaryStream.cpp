#include "BinaryStream.hpp"
#include <mc/src/common/world/Facing.hpp>

Bedrock::Result<uint32_t> ReadOnlyBinaryStream::getUnsignedVarInt32()
{
    uint32_t value = 0;
    int shift = 0;

    while (true) {
        unsigned char byte;
        auto result = this->read(&byte, 1);
        Assert(result.has_value(), "read failed");

        value |= (byte & 0x7F) << shift;
        if (!(byte & 0x80)) break;
        shift += 7;

        Assert(!(shift >= 32), "out of range");
    }

    return Bedrock::Result<uint32_t>(value);
}

Bedrock::Result<int32_t> ReadOnlyBinaryStream::getSignedVarInt32()
{
    auto result = getUnsignedVarInt32();
    Assert(result.has_value(), "Issue with reading unsigned var int");

    uint32_t value = result.value();
    return Bedrock::Result<int32_t>((value >> 1) ^ -static_cast<int32_t>(value & 1));
}

Bedrock::Result<std::string> ReadOnlyBinaryStream::getString()
{
    auto length = getUnsignedVarInt32();
    Assert(length.has_value(), "Issue with reading string length");

    std::string value;
    value.resize(length.value());

    auto result = read(&value[0], length.value());
    Assert(result.has_value(), "Issue with reading string");

    return Bedrock::Result<std::string>(value);
}

void BinaryStream::writeUnsignedVarInt32(uint32_t value)
{
    while (value > 0x7F) {
        mBuffer += (unsigned char)((value & 0x7F) | 0x80);
        value >>= 7;
    }
    mBuffer += (unsigned char)value;
}

void BinaryStream::writeSignedVarInt32(int32_t value)
{
    writeUnsignedVarInt32((value << 1) ^ (value >> 31));
}

void BinaryStream::writeString(std::string value) {
    writeUnsignedVarInt32((uint32_t)value.size());
    mBuffer += value;
}

void BinaryStream::writeBlob(const mce::Blob& blob)
{
    writeUnsignedVarInt32(static_cast<uint32_t>(blob.size()));
    if (blob.size() > 0) {
        const unsigned char* data = blob.data();
        mBuffer.append(reinterpret_cast<const char*>(data), blob.size());
    }
}

Bedrock::Result<mce::Blob> ReadOnlyBinaryStream::getBlob()
{
    auto lenResult = getUnsignedVarInt32();
    Assert(lenResult.has_value(), "Failed to read blob length");
    uint32_t length = lenResult.value();

    mce::Blob blob(length);
	if (length > 0) {
		auto result = read(blob.data(), length);
		Assert(result.has_value(), "Failed to read blob data");
	}

    return Bedrock::Result<mce::Blob>(std::move(blob));
}