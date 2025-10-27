/// @symbols
#pragma once
#include <amethyst/Imports.hpp>

#include <cstdint>
#include <string>
#include <optional>
#include <chrono>
#include "mc/src/common/SharedPtr.hpp"
#include "mc/src/common/world/item/UseAnim.hpp"
#include "mc/src/common/world/level/Tick.hpp"
#include "mc/src/common/world/item/enchanting/ItemEnchants.hpp"

class Item;
class CompoundTag;
class BlockLegacy;
class Block;
class ItemInstance;
class HashedString;

/*
 * Represents a basic stack of items, including the item type, count, auxiliary value, and associated metadata.
 */
/** @vptr {0x4E2C5E8} */
class ItemStackBase {
public:
	/** @sig {4C 8D 3D ? ? ? ? 90 83 FB} */
	MC static std::string TAG_ENCHANTS;

    /* this + 008 */ WeakPtr<Item> mItem;
    /* this + 016 */ CompoundTag* mUserData;
    /* this + 024 */ const Block* mBlock;
    /* this + 032 */ unsigned short mAuxValue;
    /* this + 034 */ byte mCount;
    /* this + 035 */ bool mValid;
    /* this + 040 */ std::chrono::steady_clock::time_point mPickupTime;
    /* this + 048 */ bool mShowPickup;
    /* this + 056 */ std::vector<const BlockLegacy*> mCanPlaceOn;
    /* this + 080 */ size_t mCanPlaceOnHash;
    /* this + 088 */ std::vector<const BlockLegacy*> mCanDestroy;
    /* this + 112 */ size_t mCanDestroyHash;
    /* this + 120 */ Tick mBlockingTick;
    /* this + 128 */ std::unique_ptr<ItemInstance> mChargedItem;

public:
    ItemStackBase();
    ItemStackBase(const ItemStackBase&);
    ItemStackBase& operator=(const ItemStackBase&);

    /** @vidx {0} */ MC virtual ~ItemStackBase();
    /** @vidx {3} */ MC virtual void reinit(const Item& item, int count, int auxValue);
    /** @vidx {2} */ MC virtual void reinit(const BlockLegacy& block, int count);
    /** @vidx {1} */ MC virtual void reinit(std::string_view name, int count, int auxValue);
    /** @vidx {4} */ MC virtual void setNull(std::optional<std::string> reason);
    /** @vidx {5} */ MC virtual std::string toString() const;
    /** @vidx {6} */ MC virtual std::string toDebugString() const;

    /** @sig {48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B EA 48 89 8D} */
    MC void _loadItem(const CompoundTag*);
    /** @sig {48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 48 8B FA 48 8B F1 48 89 94 24 ? ? ? ? 48 8D 59} */
    MC void setUserData(std::unique_ptr<CompoundTag> userData);
	/** @sig {48 89 5C 24 ? 55 56 57 48 81 EC ? ? ? ? 48 8B F2 48 8B E9 48 89 54 24} */
	MC ItemEnchants constructItemEnchantsFromUserData() const;

    Item* getItem() const;
    bool isNull() const;
    bool isLiquidClipItem() const;
    bool shouldInteractionWithBlockBypassLiquid(const Block& block) const;
    bool isInstance(const HashedString& itemName, bool useItemLookup) const;
    bool isBlock() const;
    bool isOffhandItem() const;
	bool isEnchanted() const;
    WeakPtr<BlockLegacy> getLegacyBlock() const;
    operator bool() const;
    bool hasTag(const HashedString& tag) const;
    UseAnim getUseAnimation() const;
	bool canDestroySpecial(const Block& block) const;
	bool canDestroyOptimally(const Block& block) const;
private:
    bool _isInstance(std::string_view itemName) const;
};

static_assert(sizeof(ItemStackBase) == 0x88);
