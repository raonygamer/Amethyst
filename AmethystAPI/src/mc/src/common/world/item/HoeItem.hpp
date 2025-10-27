/// @symbols
#pragma once
#include "mc/src/common/world/item/DiggerItem.hpp"

/** @vptr {48 8D 05 ? ? ? ? 49 89 07 0F 57 C9} */
class HoeItem :
	public DiggerItem
{
public:
	/** @sig {48 89 5C 24 ? 55 56 57 41 56 41 57 48 8B EC 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 ? 4C 8B F9} */
	MC HoeItem(const std::string& name, short id, const Item::Tier& tier);

	/** @vidx {i} */ MC virtual ~HoeItem() override;
	/** @vidx {i} */ MC virtual void executeEvent(ItemStackBase& stack, const std::string& eventName, RenderParams& renderParams) const;
	/** @vidx {i} */ MC virtual int getEnchantSlot() const override;
};

static_assert(sizeof(HoeItem) == sizeof(DiggerItem), "Size of HoeItem doesn't match what's expected!");