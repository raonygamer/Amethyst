/// @symbols
#pragma once
#include <amethyst/Imports.hpp>
#include "mc/src-client/common/client/gui/screens/controllers/ClientInstanceScreenController.hpp"
#include "mc/src/common/world/containers/managers/controllers/ContainerManagerController.hpp"

/** @vptr {0x4D0C918} */
class HudScreenController :
	public ClientInstanceScreenController
{
public:
    MC static uintptr_t $vtable_for_this;
    std::byte mPadding3128[184];
    // Actually HudContainerManagerController, but meh
    std::shared_ptr<ContainerManagerController> mHudScreenManagerController;

    /** @sig {48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 4C 8B E2 48 8B F9 48 89 8D} */
    MC HudScreenController(std::shared_ptr<ClientInstanceScreenModel> model);

    /** @sig {48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 4C 8B E2 48 8B F9 48 89 8D} */
    MC static void $constructor(HudScreenController* self, std::shared_ptr<ClientInstanceScreenModel> model);

    /** @vidx {i} */ MC virtual bool bind(const std::string& collectionName, uint32_t collectionNameHash, int collectionIndex, const std::string& bindingName, uint32_t bindingNameHash, const std::string& bindingNameOverride, UIPropertyBag& bag);

	/** @sig {E8 ? ? ? ? 48 81 C7 ? ? ? ? 48 3B FE 75 ? 48 8B 8B ? ? ? ? E8} */
	MC void _pushNewChatMessage(const std::string& message, float time);
};

static_assert(offsetof(HudScreenController, mHudScreenManagerController) == 3312);