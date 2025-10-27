/// @symbols
#pragma once
#include <amethyst/Imports.hpp>
#include <mc/src-deps/core/string/StringHash.hpp>
#include <mc/src/common/world/Direction.hpp>

class CompoundTag;

/** @vptr {0x4E62FF8} */
class BlockState {
public:
    struct StateListNode {
        BlockState::StateListNode* mNext;
        BlockState::StateListNode* mPrev;
        BlockState* mState;
    };

public:
    const uint64_t mID;
    const uint64_t mVariationCount;
    const HashedString mName;
    BlockState::StateListNode mNode;

    /** @vidx {0} */ MC virtual ~BlockState();
    /** @vidx {1} */ MC virtual void toNBT(CompoundTag&, int) const;
    /** @vidx {2} */ MC virtual bool fromNBT(const CompoundTag&, int&) const;
};

struct BlockStateInstance {
    uint32_t mEndBit;
    uint32_t mNumBits;
    uint32_t mVariationCount;
    uint32_t mMask;
    bool mInitialized;
    const BlockState* mState;
};

template<typename T>
class BlockStateVariant :
	public BlockState
{
public:
};

template<typename T>
class BuiltInBlockStateVariant :
	public BlockStateVariant<T>
{
public:
	static_assert(sizeof(T), "Instantiation of BuiltInBlockStateVariant with T not allowed!");
};

template<>
/** @vptr {0x4E62F20} */
class BuiltInBlockStateVariant<Direction::Type> :
	public BlockStateVariant<Direction::Type>
{
public:
	/** @vidx {0} */ MC virtual ~BuiltInBlockStateVariant() override;
	/** @vidx {1} */ MC virtual void toNBT(CompoundTag&, int) const override;
	/** @vidx {2} */ MC virtual bool fromNBT(const CompoundTag&, int&) const override;
};

class BuiltInBlockStates {
public:
	/** @addr {0x59DF450} */
	MC static BlockState CardinalDirection;
};