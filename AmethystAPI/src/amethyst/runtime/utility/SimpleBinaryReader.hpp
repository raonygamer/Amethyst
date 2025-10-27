#pragma once
#include <istream>

namespace Amethyst {
class SeekGuard {
public:
    std::istream& Stream;
    std::streampos Last;
    SeekGuard(std::istream& stream, const std::streampos pos) :
        Stream(stream),
        Last(stream.tellg()) {
        Stream.seekg(pos);
    }

	SeekGuard(const SeekGuard&) = delete;
	SeekGuard& operator=(const SeekGuard&) = delete;
	SeekGuard(SeekGuard&&) = delete;
	SeekGuard& operator=(SeekGuard&&) = delete;
    ~SeekGuard() {
        Stream.seekg(Last);
	}
};

class SimpleBinaryReader;
class IReadable {
public:
    virtual ~IReadable() = default;
    virtual void Read(SimpleBinaryReader& reader) = 0;
};

template <typename T>
concept SimpleType = std::is_fundamental_v<T> || std::is_trivially_copyable_v<T> || std::is_base_of_v<IReadable, T>;

class SimpleBinaryReader {
    std::istream& mStream;

public:
    SimpleBinaryReader(std::istream& stream) :
        mStream(stream) {}

    template <SimpleType T>
    T Read() {
        if constexpr (std::is_base_of_v<IReadable, T>) {
            T value = {};
            value.Read(*this);
            return value;
        }
        else {
            T value = {};
            if (!mStream.read(reinterpret_cast<char*>(&value), sizeof(T))) {
                throw std::runtime_error("Unexpected end of stream");
            }
            return value;
        }
    }

    std::string ReadString(size_t length)
    {
        if (length == 0) 
            return {};
        std::string str = {};
        str.resize(length);
        if (!mStream.read(reinterpret_cast<char*>(str.data()), length)) {
            throw std::runtime_error("Unexpected end of stream");
        }
        return str;
    }

    template <SimpleType T>
    std::vector<T> ReadMultiplePrefixed() {
        // Read length prefix
        uint32_t length = Read<uint32_t>();
        if (length == 0) 
            return {};

        // Read array data
        std::vector<T> vec = {};
        vec.reserve(length);
        for (uint32_t i = 0; i < length; i++) {
            vec.push_back(Read<T>());
        }
        return vec;
    }

    std::string ReadPrefixedString() {
        // Read length prefix
        uint32_t length = Read<uint32_t>();
        if (length == 0) 
            return "";

        // Read string data
        return ReadString(length);
    }

    std::istream& GetStream() {
        return mStream;
    }

    const std::istream& GetStream() const {
        return mStream;
    }
};
} // namespace Amethyst