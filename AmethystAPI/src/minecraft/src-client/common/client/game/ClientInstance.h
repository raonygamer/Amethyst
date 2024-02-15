#pragma once
#include "minecraft/src-client/common/client/game/MinecraftGame.h"
#include "minecraft/src-client/common/client/gui/gui/GuiData.h"
#include "minecraft/src-client/common/client/player/LocalPlayer.h"
#include "minecraft/src/common/world/level/BlockSource.h"
#include <cstdint>
#include "minecraft/src-deps/renderer/Camera.h"

class Minecraft;
class ClientInputHandler;
class ItemRenderer;

#pragma pack(push, 1)
class ClientInstance {
public:
    /* this + 0    */ uintptr_t** vtable;
    /* this + 8    */ std::byte padding8[192];
    /* this + 200  */ MinecraftGame* minecraftGame;
    /* this + 208  */ Minecraft* minecraft;
    /* this + 216  */ std::byte padding216[56];
    /* this + 272  */ ClientInputHandler* inputHandler;
    /* this + 280  */ std::byte padding280[344];
    /* this + 624  */ mce::Camera camera;
    /* this + 1136 */ std::byte padding1136[232];
    /* this + 1368 */ ItemRenderer* itemRenderer;
    /* this + 1376 */ GuiData* guiData;
    /* this + 1384 */ std::byte padding1384[1848];

public:
    // 1.20.51.1 - index 11
    // 40 55 53 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 45 8B F1
    int64_t onStartJoinGame(ClientInstance*, int64_t, int64_t, int64_t);

    // 1.20.51.1 - index: 13
    // 48 89 5C 24 ? 48 89 74 24 ? 55 57 41 54 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 ? 45 0F B6 F0 44 0F B6 FA
    void requestLeaveGame(char switchScreen, char sync);

    BlockSource* getRegion();
    LocalPlayer* getLocalPlayer();
};
#pragma pack(pop)