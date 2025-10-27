/// @symbols
#pragma once
#include "mc/src/common/world/item/DiggerItem.hpp"

/** @vptr {48 8D 05 ? ? ? ? 49 89 04 24 0F 57 C9 F3 0F 7F 4D ? 4C 89 75} */
class ShovelItem :
	public DiggerItem
{
public:
	/** @sig {40 55 53 56 57 41 54 41 56 41 57 48 8B EC 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 ? 4C 8B E1 48 89 4D ? 0F 57 C0 F3 0F 7F 45 ? 45 33 F6} */
	MC ShovelItem(const std::string& name, short id, const Item::Tier& tier);

	/** @vidx {i} */ MC virtual ~ShovelItem() override;
	/** @vidx {i} */ MC virtual void executeEvent(ItemStackBase& stack, const std::string& eventName, RenderParams& renderParams) const;
	/** @vidx {i} */ MC virtual bool canDestroySpecial(const Block& block) const override;
	/** @vidx {i} */ MC virtual int getEnchantSlot() const override;
	/** @vidx {i} */ MC virtual InteractionResult _useOn(ItemStack& stack, Actor& actor, BlockPos pos, FacingID face, const Vec3& hit) const;
};

static_assert(sizeof(ShovelItem) - sizeof(DiggerItem) == 0, "Size of ShovelItem doesn't match what's expected!");