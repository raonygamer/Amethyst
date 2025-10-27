///@symbolgeneration
#pragma once
#include <amethyst/Imports.hpp>
#include <mc/src/common/world/containers/controllers/ContainerController.hpp>
#include <mc/src/common/world/item/ItemInstance.hpp>

 class Recipe;
// class ItemInstance;

/** @vptr {0x4DE78F0} */
class CraftingContainerController : public ContainerController {
public:
	MC static uintptr_t $vtable_for_this;

    const Recipe* mCurrentRecipe;
    int mGridSize;
    bool mDisplayOnlyGhostItems;
    std::vector<ItemInstance> mGhostItems;

    /// @vidx {i}
    MC virtual ~CraftingContainerController() override;

    /// @vidx {10}
    MC virtual UnknownReturn onRecipeSelected(const Recipe* unk0, unsigned long unk1, bool unk2);

    /// @vidx {11}
    MC virtual UnknownReturn clearSelectedRecipe();

    /// @vidx {12}
    MC virtual UnknownReturn getSelectedRecipe() const;

    /// @vidx {13}
    MC virtual UnknownReturn setGhostItem(const ItemInstance& unk0, int unk1, bool unk2);

    /// @vidx {14}
    MC virtual UnknownReturn getGhostItem(int unk0) const;

//begin members:
    /// @signature {48 89 54 24 ? 48 89 4C 24 ? 53 56 57 48 83 EC ? 48 8B F2 48 8B F9 0F 57 C0 F3 0F 7F 44 24 ? 48 8B 4A ? 48 85 C9 74 ? 48 8B 02 48 89 44 24 ? 48 89 4C 24 ? F0 FF 41 ? 48 8D 54 24 ? 48 8B CF E8 ? ? ? ? 90 48 8D 05 ? ? ? ? 48 89 07 33 C0 48 89 47}
 	MC CraftingContainerController(std::shared_ptr<ContainerModel> model, bool something);
};