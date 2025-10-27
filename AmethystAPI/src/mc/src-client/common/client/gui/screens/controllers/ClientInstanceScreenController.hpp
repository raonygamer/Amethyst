/// @symbolgeneration
#pragma once
#include "amethyst/Imports.hpp"
#include "mc/src-client/common/client/gui/screens/controllers/MinecraftScreenController.hpp"
#include "mc/src-client/common/client/gui/screens/models/ClientInstanceScreenModel.hpp"

class PlatformMultiplayerRestrictions;

/// @vptr {0x4CC91C0}
class ClientInstanceScreenController : public MinecraftScreenController {
public:
    std::shared_ptr<ClientInstanceScreenModel> mClientInstanceScreenModel;
    std::unique_ptr<PlatformMultiplayerRestrictions> mPlatformMultiplayerRestrictions;

	/// @signature {48 89 5C 24 ? 48 89 54 24 ? 48 89 4C 24 ? 57 48 83 EC ? 48 8B FA 48 8B D9 0F 57 C0 F3 0F 7F 44 24 ? 48 8B 42 ? 48 85 C0 74 ? F0 FF 40 ? 48 8B 02 48 89 44 24 ? 48 8B 42 ? 48 89 44 24 ? 41 B1 ? 45 33 C0 48 8D 54 24 ? E8 ? ? ? ? 90 48 8D 05 ? ? ? ? 48 89 03 48 8D 05 ? ? ? ? 48 89 83 ? ? ? ? 33 C0}
    MC ClientInstanceScreenController(std::shared_ptr<ClientInstanceScreenModel> model);

    /// @vidx {i}
    MC virtual ~ClientInstanceScreenController();

    /// @vidx {i}
    MC virtual ui::DirtyFlag tick() override;
};

static_assert(sizeof(ClientInstanceScreenController) == 0xC38);