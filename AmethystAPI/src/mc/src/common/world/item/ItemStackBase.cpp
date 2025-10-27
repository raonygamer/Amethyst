#include "mc/src/common/world/item/ItemStackBase.hpp"
#include "mc/src/common/world/item/Item.hpp"
#include <amethyst/Memory.hpp>
#include "registry/ItemRegistryManager.hpp"
#include "registry/ItemRegistry.hpp"
#include "mc/src-deps/core/string/StringHash.hpp"

ItemStackBase::ItemStackBase() :
    mUserData(nullptr),
    mBlock(nullptr),
    mAuxValue(0b1000000000000000),
    mCount(0),
    mValid(false),
    mShowPickup(true),
    mCanPlaceOnHash(0),
    mCanDestroyHash(0),
    mChargedItem(nullptr)
{
}

ItemStackBase::ItemStackBase(const ItemStackBase& other) :
    mCount(other.mCount),
    mAuxValue(other.mAuxValue),
    mItem(other.mItem),
    mBlock(other.mBlock),
    mValid(other.mValid),
    mPickupTime(other.mPickupTime),
    mUserData(nullptr)
{
    if (other.mUserData != nullptr) {
        std::unique_ptr<CompoundTag> clonedData = other.mUserData->clone();
        setUserData(std::move(clonedData));
    }
}

// 1.20.51.1 Reimplementation - Incomplete
ItemStackBase &ItemStackBase::operator=(const ItemStackBase& other) {
    if (this != &other) {
        mCount = other.mCount;
        mAuxValue = other.mAuxValue;
        mItem = other.mItem;
        mBlock = other.mBlock;
        mValid = other.mValid;
        mPickupTime = other.mPickupTime;
        if (other.mUserData != nullptr) {
            std::unique_ptr<CompoundTag> clonedData = other.mUserData->clone();
            setUserData(std::move(clonedData));
        }
    }
    return *this;
}

bool ItemStackBase::isNull() const {
    if (!mValid) 
        return true;
    Item* item = mItem.get();

    if (!item || item->mFullName != HashedString("minecraft:air")) {
        if (mCount != 0 || mBlock != nullptr || mAuxValue != 0) 
            return false;
        if (item || mUserData != 0 || mCanDestroyHash != 0 || mCanPlaceOnHash != 0) 
            return false;
    }

    return true;
}

bool ItemStackBase::isLiquidClipItem() const
{
    return mItem && mItem->isLiquidClipItem();
}

bool ItemStackBase::shouldInteractionWithBlockBypassLiquid(const Block& block) const
{
    return mItem && mItem->shouldInteractionWithBlockBypassLiquid(block);
}

bool ItemStackBase::isInstance(const HashedString& itemName, bool useItemLookup) const
{
    if (useItemLookup) {
        return this->_isInstance(itemName.getString());
    }
    else {
        if (!mItem) return false;
        return mItem->mFullName == itemName;
    }
}

bool ItemStackBase::_isInstance(std::string_view itemName) const
{
    if (!mItem) return false;
    AssertFail("Too lazy to implement this, if needed write impl here");
}

Item* ItemStackBase::getItem() const {
    return mItem.get();
}

ItemStackBase::operator bool() const
{
    return mValid && mItem && !isNull() && mCount > 0;
}

bool ItemStackBase::isBlock() const
{
    return mItem && mItem->mLegacyBlock;
}

WeakPtr<BlockLegacy> ItemStackBase::getLegacyBlock() const
{
    if (mItem && mItem->mLegacyBlock) {
        return mItem->mLegacyBlock;
    }

    return WeakPtr<BlockLegacy>();
}

bool ItemStackBase::isOffhandItem() const
{
    if (!mItem) return false;
    return mItem->mAllowOffhand;
}

bool ItemStackBase::hasTag(const HashedString& tag) const
{
    return mItem && mItem->hasTag(tag);
}

UseAnim ItemStackBase::getUseAnimation() const
{
    if (!mItem) return UseAnim::None;
    else return mItem->getUseAnimation();
}

bool ItemStackBase::isEnchanted() const {
	if (!mItem || !mUserData)
		return false;
	return mUserData->contains(TAG_ENCHANTS, Tag::Type::List);
}

bool ItemStackBase::canDestroySpecial(const Block& block) const {
	if (!mItem)
		return false;
	return mItem->canDestroySpecial(block);
}

bool ItemStackBase::canDestroyOptimally(const Block& block) const {
	if (!block.requiresCorrectToolForDrops()) {
		return true;
	}
	return canDestroySpecial(block);
}