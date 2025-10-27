/// @symbols
#pragma once
#include "mc/src/common/world/item/DiggerItem.hpp"

/** @vptr {0x4E2AB48} */
class PickaxeItem :
	public DiggerItem 
{
public:
	/** @sig {40 55 53 56 57 41 54 41 56 41 57 48 8B EC 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 ? 4C 8B E1 48 89 4D ? 0F 57 C0 F3 0F 7F 45 ? 45 33 FF 4C 89 7D ? 48 8D 45 ? 48 89 44 24 ? 4C 89 4C 24 ? 45 8D 4F ? E8 ? ? ? ? 90 48 8B 55} */
	MC PickaxeItem(const std::string& name, short id, const Item::Tier& tier);

	/** @vidx {i} */ MC virtual ~PickaxeItem() override;
	/** @vidx {i} */ MC virtual bool canDestroySpecial(const Block& block) const override;
	/** @vidx {i} */ MC virtual int getEnchantSlot() const override;
	/** @vidx {i} */ MC virtual float getDestroySpeed(const ItemStackBase& stack, const Block& block) const override;
};

static_assert(sizeof(PickaxeItem) - sizeof(DiggerItem) == 0, "Size of PickaxeItem doesn't match what's expected!");