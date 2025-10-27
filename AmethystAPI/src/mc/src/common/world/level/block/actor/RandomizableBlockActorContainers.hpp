/// @symbolgeneration
#pragma once
#include "mc/src/common/world/level/block/actor/BlockActor.hpp"
#include "mc/src/common/world/inventory/FillingContainer.hpp"

/// @vptr {0x4E71F18}
class RandomizableBlockActorContainerBase : public BlockActor {
public:
    std::string mLootTable;
    int mLootTableSeed;

public:
    RandomizableBlockActorContainerBase(BlockActorType type, const std::string& id, const BlockPos& position);

public:
    /// @vidx {inherit}
    MC virtual ~RandomizableBlockActorContainerBase() override;

    /// @vidx {inherit}
    MC virtual void load(Level& a2, const CompoundTag& tag, DataLoadHelper& a4) override;

    /// @vidx {inherit}
    MC virtual bool save(CompoundTag& tag) const override;

    /// @vidx {inherit}
    MC virtual void eraseLootTable() override;
};

/// @vptr {0x4E73B30, RandomizableBlockActorContainerBase}
/// @vptr {0x4E739C0, FillingContainer}
class RandomizableBlockActorFillingContainer : 
    public RandomizableBlockActorContainerBase, 
    public FillingContainer
{
public:
    /// @vidx {inherit, RandomizableBlockActorContainerBase}
    MC virtual ~RandomizableBlockActorFillingContainer() override;

    /// @vidx {inherit, RandomizableBlockActorContainerBase}
    MC virtual void onRemoved(BlockSource& unk0) override;

    /// @vidx {inherit, FillingContainer}
    MC virtual void setContainerChanged(int unk0) override;

    /// @vidx {inherit, FillingContainer}
    MC virtual void startOpen(Player& unk0) override;

    /// @vidx {inherit, FillingContainer}
    MC virtual void dropSlotContent(BlockSource& unk0, const Vec3& unk1, bool unk2, int unk3) override;

    /// @vidx {inherit, FillingContainer}
    MC virtual void dropContents(BlockSource& unk0, const Vec3& unk1, bool unk2) override;

    /// @vidx {inherit, FillingContainer}
    MC virtual void initializeContainerContents(BlockSource& unk0) override;
};

// 1.21.0.3
static_assert(sizeof(RandomizableBlockActorContainerBase) - sizeof(BlockActor) == 40);
static_assert(sizeof(RandomizableBlockActorFillingContainer) - sizeof(RandomizableBlockActorContainerBase) - sizeof(FillingContainer) == 0);