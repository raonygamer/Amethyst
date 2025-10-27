#pragma once
#include <string>
#include <mc/src-deps/core/utility/Result.hpp>
#include <mc/src-deps/core/container/Blob.hpp>
#include <amethyst/Log.hpp>

class ReadOnlyBinaryStream {
private:
    size_t mReadPointer;
    bool mHasOverflowed;
    const std::string mOwnedBuffer;
    const std::string& mBuffer;

public:
    virtual ~ReadOnlyBinaryStream();
    virtual Bedrock::Result<void, std::error_code> read(void* target, uint64_t num);

public:
    template <typename T>
    Bedrock::Result<T> get()
    {
        T data{};

        auto result = this->read(&data, sizeof(T));
        Assert(result.has_value(), "this->read<T>() had an exception.");

        return Bedrock::Result<T>(data);
    }

    Bedrock::Result<uint32_t> getUnsignedVarInt32();
    Bedrock::Result<int32_t> getSignedVarInt32();
    Bedrock::Result<std::string> getString();
	Bedrock::Result<mce::Blob> getBlob();
};

class BinaryStream : public ReadOnlyBinaryStream {
private:
    std::string mOwnedBuffer;
    std::string& mBuffer;

public:
    template <typename T>
    void write(T in)
    {
        unsigned char* bytes = reinterpret_cast<unsigned char*>(&in);

        for (int i = 0; i < sizeof(T); i++) {
            mBuffer += bytes[i];
        }
    }

    void writeUnsignedVarInt32(uint32_t value);
    void writeSignedVarInt32(int32_t value);
    void writeString(std::string value);
	void writeBlob(const mce::Blob& blob);
};