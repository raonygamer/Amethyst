/// @symbols
#pragma once
#include <amethyst/Imports.hpp>
#include "mc/src/common/world/level/block/ActorBlock.hpp"

/** @vptr {0x4E18338} */
class FurnaceBlock :
	public ActorBlock 
{
public:
    bool mLit;

    /** @sig {48 89 5C 24 ? 57 48 83 EC ? 48 8B 05 ? ? ? ? 48 8B D9 48 8B 0D ? ? ? ? 41 0F B6 F9 48 2B C1 45 8B D0 48 C1 F8 ? 4C 8B DA 48 83 F8 ? 73 ? B9 ? ? ? ? E8 ? ? ? ? EB ? 48 8B 41 ? 4C 8B C8 45 8B C2 49 8B D3 48 8B CB E8 ? ? ? ? 48 8D 05 ? ? ? ? 40 88 BB ? ? ? ? 48 89 03 48 8B C3 C7 83 ? ? ? ? ? ? ? ? C6 83} */
    MC FurnaceBlock(const std::string& nameId, int id, bool isLit);

    /** @vidx {i} */ MC virtual ~FurnaceBlock() override;
    /** @vidx {i} */ MC virtual bool isContainerBlock() const;
    /** @vidx {i} */ MC virtual bool isCraftingBlock() const;
    /** @vidx {i} */ MC virtual ItemInstance asItemInstance(const Block& block, const BlockActor* actor) const;
    /** @vidx {i} */ MC virtual bool hasComparatorSignal() const;
    /** @vidx {i} */ MC virtual int getComparatorSignal(BlockSource& blockSource, const BlockPos& pos, const Block& block, Facing::Name face) const;
    /** @vidx {i} */ MC virtual Facing::Name getMappedFace(Facing::Name face, const Block& block) const;
    /** @vidx {i} */ MC virtual void animateTickBedrockLegacy(BlockSource& blockSource, const BlockPos& pos, Random& rand) const;
    /** @vidx {i} */ MC virtual void onRemove(BlockSource& blockSource, const BlockPos& pos) const;
    /** @vidx {i} */ MC virtual bool isInteractiveBlock() const;
    /** @vidx {i} */ MC virtual bool use(Player& player, const BlockPos& pos, Facing::Name face) const;
};

static_assert(sizeof(FurnaceBlock) == 992);