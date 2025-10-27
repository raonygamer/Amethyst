#include "mc/src/common/world/item/ShearsItem.hpp"

ShearsItem::ShearsItem(const std::string& name, short id) :
	Item(name, id)
{
	setMaxStackSize(1);
	setMaxDamage(238);
}