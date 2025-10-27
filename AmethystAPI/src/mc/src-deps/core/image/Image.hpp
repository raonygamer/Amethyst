#pragma once
#include <mc/src-deps/core/container/Blob.hpp>

namespace mce {
    enum class ImageFormat : uint32_t {
        Unknown = 0,
        R8Unorm = 1,
        RG8Unorm = 2,
        RGB8Unorm = 3,
        RGBA8Unorm = 4,
        RGBA16Float = 5,
    };

    enum class ImageUsage : unsigned char {
        Unknown = 0x0000,
        sRGB = 0x0001,
        Data = 0x0002,
    };

    class Image {
    public:
        mce::ImageFormat imageFormat;
        uint32_t mWidth;
        uint32_t mHeight;
        uint32_t mDepth;
        ImageUsage mUsage;
        mce::Blob mImageBytes;

        bool isEmpty() const {
            return mImageBytes.size() == 0;
        }
    };
}