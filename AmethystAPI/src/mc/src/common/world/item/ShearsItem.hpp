/// @symbols
#pragma once
#include "mc/src/common/world/item/Item.hpp"

/** @vptr {0x4E226B8} */
class ShearsItem :
	public Item
{
public:
	// Inlined constructor (impl on ShearsItem.cpp)
	ShearsItem(const std::string& name, short id);

	/** @vidx {i} */ MC virtual ~ShearsItem() override;
	/** @vidx {i} */ MC virtual bool canDestroySpecial(const Block& block) const override;
	/** @vidx {i} */ MC virtual int getEnchantSlot() const override;
	/** @vidx {i} */ MC virtual bool dispense(BlockSource& source, Container& container, int slot, const Vec3& pos, FacingID facing) const override;
	/** @vidx {i} */ MC virtual float getDestroySpeed(const ItemStackBase& stack, const Block& block) const override;
	/** @vidx {i} */ MC virtual void hurtActor(ItemStack& stack, Actor& actor, Mob& attacker) const override;
	/** @vidx {i} */ MC virtual bool mineBlock(ItemStack& stack, const Block& block, int x, int y, int z, Actor* owner) const override;
	/** @vidx {i} */ MC virtual InteractionResult _useOn(ItemStack& stack, Actor& actor, BlockPos pos, FacingID face, const Vec3& hit) const override;
};