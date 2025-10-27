/// @symbols
#pragma once
#include <amethyst/Imports.hpp>
#include <mc/src/common/world/item/Item.hpp>

/** @vptr {48 8D 05 ? ? ? ? 48 89 07 48 89 9F ? ? ? ? C6 87 ? ? ? ? ? 8B 43} */
class WeaponItem : 
	public Item 
{
public:
	MC static uintptr_t $vtable_for_this;
	int32_t mDamage;
	const Item::Tier& mTier;
	
	/** @sig {E8 ? ? ? ? 90 48 8D 05 ? ? ? ? 48 89 07 48 8D 15 ? ? ? ? 48 8B CF E8 ? ? ? ? C7 87} */
	MC WeaponItem(const std::string& identifier, short numId, const Item::Tier& tier);

	/** @vidx {i} */ MC virtual ~WeaponItem() override;
	/** @vidx {i} */ MC virtual bool canDestroySpecial(const Block& block) const override;
	/** @vidx {i} */ MC virtual int getAttackDamage() const override;
	/** @vidx {i} */ MC virtual bool isHandEquipped() const override;
	/** @vidx {i} */ MC virtual bool canDestroyInCreative() const override;
	/** @vidx {i} */ MC virtual void appendFormattedHovertext(const ItemStackBase& stack, Level& level, std::string& outText, bool showCategory) const override;
	/** @vidx {i} */ MC virtual bool isValidRepairItem(const ItemStackBase& targetStack, const ItemStackBase& repairStack, const BaseGameVersion& version) const override;
	/** @vidx {i} */ MC virtual int getEnchantSlot() const override;
	/** @vidx {i} */ MC virtual int getEnchantValue() const override;
	/** @vidx {i} */ MC virtual ItemStack& use(ItemStack& stack, Player& player) const override;
	/** @vidx {i} */ MC virtual float getDestroySpeed(const ItemStackBase& stack, const Block& block) const override;
	/** @vidx {i} */ MC virtual void hurtActor(ItemStack& stack, Actor& actor, Mob& mob) const override;
};

static_assert(sizeof(WeaponItem) - sizeof(Item) == 16, "WeaponItem size does not match what's expected!");