#pragma once
#include "mc/src/common/world/item/enchanting/EnchantmentInstance.hpp"

class EnchantmentInstance;
class ItemEnchants {
public:
	int mSlot;
	std::vector<EnchantmentInstance> mItemEnchants[3];
};