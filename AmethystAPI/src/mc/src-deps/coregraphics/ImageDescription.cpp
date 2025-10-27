#include <mc/src-deps/coregraphics/ImageDescription.hpp>
#include <amethyst/Log.hpp>

uint32_t cg::ImageDescription::getStrideFromFormat(const mce::TextureFormat format)
{
    switch (format) {
    case mce::TextureFormat::R32g32b32a32Float:
        return 16;

    case mce::TextureFormat::R8g8b8a8Unorm:
        return 4;

    case mce::TextureFormat::A8Unorm:
        return 1;

    default:
        AssertFail("Case {} has not been implemented in getStrideFromFormat", (int)format);
    }
}