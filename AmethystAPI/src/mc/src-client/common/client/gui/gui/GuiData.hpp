/// @symbols
#pragma once
#include <amethyst/Imports.hpp>

#include "mc/src/common/world/phys/Vec2.hpp"
#include <cstddef>
#include <optional>
#include <string>
#include <vector>

//struct_size = 0x9E0 is_virtual = False
//    hide_vtable = True
//
//#(Type, Name, Size(in bytes), Offset(in bytes))
//    struct
//    = [("Vec2", "totalScreenSize", 8, 48),
//       ("Vec2", "clientScreenSize", 8, 48 + 8),
//       ("Vec2", "clientUIScreenSize", 8, 48 + 16),
//       ("IClientInstance&", "mClient", 8, 136)]

class IClientInstance;

#pragma pack(push, 1)
class GuiData {
public:
    /* this + 0    */ std::byte padding0[48];
    /* this + 48   */ Vec2 totalScreenSize;
    /* this + 56   */ Vec2 clientScreenSize;
    /* this + 64   */ Vec2 clientUIScreenSize;
    /* this + 72   */ bool mScreenSizeDataValid;
    /* this + 73   */ std::byte padding73[3];
    /* this + 76   */ float mGuiScale;
    /* this + 80   */ std::byte padding77[106 - 80];
    /* this + 106  */ short mPointerX;
    /* this + 108  */ short mPointerY;
    /* this + 110  */ std::byte padding108[136 - 110];
    /* this + 136  */ IClientInstance& mClient;
    /* this + 144  */ std::byte padding144[2384];

	/** @sig {E8 ? ? ? ? 90 48 85 DB 74 ? 48 8B CB E8 ? ? ? ? 90 E9 ? ? ? ? 0F 57 C0 0F 11 45 ? 66 0F 6F 0D} */
	MC void displayLocalizedMessage(const std::string& message);

    void _displayWhisperMessage(const std::string& a1, const std::string& a2, const std::string& a3, const std::string& a4);
    void displayLocalizableMessage(const std::string& a1, const std::vector<std::string>& a3);
};
#pragma pack(pop)

static_assert(sizeof(GuiData) == 0x9E0);