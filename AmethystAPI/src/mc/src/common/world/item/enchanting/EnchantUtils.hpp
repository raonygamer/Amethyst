/// @symbols
#pragma once
#include "mc/src/common/world/item/enchanting/Enchant.hpp"

class EnchantUtils {
public:
	/*
	 * Determines whether two enchantments are compatible.
	 */
	/** @sig {33 D2 0F B6 C1 83 F8 ? 77 ? 4C 8D 05 ? ? ? ? 41 0F B6 84 00} */
	MC static int determineCompatibility(Enchant::Type type);
};