/// @symbols
#pragma once
#include "mc/src/common/world/item/Item.hpp"

/** @vptr {48 8D 05 ? ? ? ? 49 89 06 48 8B 7C 24} */
class DiggerItem : 
	public Item 
{
public:
	float mSpeed;
	const Item::Tier& mTier;
	int32_t mAttackDamage;
	std::vector<const Block*> mBlocks;
	std::set<const BlockLegacy*> m_bBlocks;

	/** @sig {48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 48 89 4C 24 ? 41 56 48 83 EC ? 41 8B F1 4C 8B F1} */
	MC DiggerItem(const std::string& name, short id, int32_t attackDamage, const Item::Tier& tier, const std::vector<const Block*>& blocks);

	/** @vidx {i} */ MC virtual ~DiggerItem() override;
	/** @vidx {i} */ MC virtual int getAttackDamage() const override;
	/** @vidx {i} */ MC virtual bool isHandEquipped() const override;
	/** @vidx {i} */ MC virtual void appendFormattedHovertext(const ItemStackBase& stack, Level& level, std::string& outText, bool showCategory) const override;
	/** @vidx {i} */ MC virtual bool isValidRepairItem(const ItemStackBase& targetStack, const ItemStackBase& repairStack, const BaseGameVersion& version) const override;
	/** @vidx {i} */ MC virtual int getEnchantValue() const override;
	/** @vidx {i} */ MC virtual float getDestroySpeed(const ItemStackBase& stack, const Block& block) const override;
};

static_assert(sizeof(DiggerItem) - sizeof(Item) == 64, "Size of DiggerItem doesn't match what's expected!");