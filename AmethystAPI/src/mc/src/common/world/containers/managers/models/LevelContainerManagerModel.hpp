/// @symbolgeneration
#pragma once
#include "amethyst/Imports.hpp"
#include "mc/src/common/world/containers/managers/models/ContainerManagerModel.hpp"
#include "mc/src/common/world/level/BlockPos.hpp"
#include "mc/src/common/ActorUniqueID.hpp"
#include "mc/src/common/world/level/block/actor/BlockActorRendererId.hpp"

/// @vptr {0x4DE93E8}
class LevelContainerManagerModel : 
	public ContainerManagerModel 
{
public:
    BlockPos mBlockPos;
    ActorUniqueID mBlockActorId;
    BlockActorType mBlockActorType;

    LevelContainerManagerModel(ContainerID id, Player& player, const BlockPos& pos, BlockActorType type) :
        ContainerManagerModel(id, player),
        mBlockPos(pos),
        mBlockActorId(ActorUniqueID()),
        mBlockActorType(type)
    {
    }

    LevelContainerManagerModel(ContainerID id, Player& player, ActorUniqueID actorId) :
        ContainerManagerModel(id, player),
        mBlockPos({ 0, 0, 0 }),
        mBlockActorId(actorId),
        mBlockActorType(BlockActorType::Undefined)
    {
    }

    /// @vidx {inherit}
    MC virtual ~LevelContainerManagerModel() override;
    /// @vidx {inherit}
    MC virtual std::vector<ItemStack> getItemCopies() const override;
    /// @vidx {inherit}
    MC virtual void setSlot(int slot, const ItemStack& stack, bool) override;
    /// @vidx {inherit}
    MC virtual const ItemStack& getSlot(int slot) const override;
    /// @vidx {inherit}
    MC virtual void setData(int, int) override;
    /// @vidx {inherit}
    MC virtual void broadcastChanges() override;
    /// @vidx {inherit}
    MC virtual bool isValid(float) override;
    /// @vidx {inherit}
    MC virtual ContainerScreenContext _postInit() override;
};