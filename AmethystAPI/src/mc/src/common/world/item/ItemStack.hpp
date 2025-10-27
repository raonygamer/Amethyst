/// @symbols
#pragma once
#include <format>
#include "mc/src/common/world/item/ItemStackBase.hpp"
#include "mc/src/common/world/inventory/network/ItemStackNetIdVariant.hpp"
#include "mc/src/common/world/Facing.hpp"


class InteractionResult;
class Actor;
class Vec3;
class BlockPalette;
class NetworkItemStackDescriptor;

/** @vptr {0x4E2B6B0} */
class ItemStack : public ItemStackBase {
public:
    /** @address {0x57CF128} */
    MC static ItemStack EMPTY_ITEM;
	/* this + 136 */ ItemStackNetIdVariant mNetIdVariant;

    ItemStack();
    ItemStack(const ItemStack& other);

    /** @vidx {i} */ MC virtual ~ItemStack() override;
    /** @vidx {i} */ MC virtual void reinit(const Item& item, int count, int auxValue) override;
    /** @vidx {i} */ MC virtual void reinit(const BlockLegacy& block, int count) override;
    /** @vidx {i} */ MC virtual void reinit(std::string_view name, int count, int auxValue) override;
    /** @vidx {i} */ MC virtual void setNull(std::optional<std::string> reason) override;
    /** @vidx {i} */ MC virtual std::string toString() const override;
    /** @vidx {i} */ MC virtual std::string toDebugString() const override;

    /** @sig {40 53 55 56 57 41 56 48 83 EC ? 48 8B 41 ? 41 8B E9} */
    MC InteractionResult useOn(Actor&, int, int, int, FacingID, const Vec3&);
    /** @sig {48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? 44 8B 71 ? 49 8B E8 48 8B FA 48 8B D9 33 F6 E8 ? ? ? ? 48 8B CB 44 0F B7 F8 E8 ? ? ? ? 48 8B 4B ? 48 85 C9 74 ? 48 8B 11 48 8B 42 ? 48 8D 54 24 ? FF 15 ? ? ? ? 48 8B 30 48 8B CB E8 ? ? ? ? 48 8B 4B ? 48 85 C9 74 ? 48 8B 01 48 8D 54 24 ? 48 8B 40 ? FF 15 ? ? ? ? 0F B7 48 ? EB ? B9 ? ? ? ? 0F B7 53 ? 48 8D 43 ? 48 89 6C 24 ? 44 0F B7 C1 48 89 44 24 ? 4C 8B CE 44 89 74 24 ? 48 8B CF 66 44 89 7C 24 ? E8 ? ? ? ? 4C 8D 5C 24 ? 48 8B C7 49 8B 5B ? 49 8B 6B ? 49 8B 73 ? 49 8B E3 41 5F 41 5E 5F C3 CC CC CC 48 89 5C 24 ? 48 89 6C 24} */
    MC static ItemStack fromDescriptor(const NetworkItemStackDescriptor& descriptor, BlockPalette& palette, bool isClientSide );
    
    int getMaxUseDuration() const;
};

static_assert(sizeof(ItemStack) == 0xA0);