/// @symbols
#pragma once
#include "mc/src/common/world/level/block/actor/BlockActor.hpp"
#include "mc/src/common/world/Container.hpp"
#include "mc/src/common/world/item/ItemInstance.hpp"
#include "mc/src/common/world/item/ItemStack.hpp"
#include "mc/src/common/ActorUniqueID.hpp"
#include "mc/src-deps/shared_types/legacy/LevelSoundEvent.hpp"

/** @vptr {48 8D 05 ? ? ? ? 48 89 06 48 8D 05 ? ? ? ? 48 89 86 ? ? ? ? 33 DB} */
/** @vptr {48 8D 05 ? ? ? ? 48 89 86 ? ? ? ? 33 DB 48 89 9E ? ? ? ? 48 89 9E ? ? ? ? 48 8D 8E, Container} */
class FurnaceBlockActor :
	public BlockActor, 
	public Container 
{
public:
	MC static uintptr_t $vtable_for_this;
	MC static uintptr_t $vtable_for_Container;

	int32_t mLitTime;
	int32_t mLitDuration;
	int32_t mCookingProgress;
	uint32_t mStoredXP;
	ItemStack mItems[3];
	bool mDirty[3];
	std::unordered_set<ActorUniqueID> mPlayers;
	const HashedString mRecipeTag;
	const int32_t mBurnInterval;
	Puv::Legacy::LevelSoundEvent mSmeltSoundEvent;
	int32_t mSoundTick;
	int32_t mSoundTickTarget;
	const Block& mUnlitFurnace;
	const Block& mLitFurnace;
	ItemInstance mLastFuelItem;
	bool mCanBeFinished;
	bool mFinished;
	bool mNoDrop;

	/** @sig {48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 49 8B F9 48 8B F1 48 89 4C 24 ? E8} */
	MC FurnaceBlockActor(
		BlockActorType blockActorType, 
		const BlockPos& pos, 
		const HashedString& recipeTag, 
		Puv::Legacy::LevelSoundEvent smeltSound, 
		ContainerType containerType, 
		int burnInterval, 
		const Block& unlitFurnace, 
		const Block& litFurnace
	);

	/** @vidx {i} */ MC virtual ~FurnaceBlockActor() override;
	/** @vidx {i} */ MC virtual void load(Level& level, const CompoundTag& tag, DataLoadHelper& helper) override;
	/** @vidx {i} */ MC virtual bool save(CompoundTag& tag) const override;
	/** @vidx {i} */ MC virtual void onCustomTagLoadDone(BlockSource& region) override;
	/** @vidx {i} */ MC virtual void tick(BlockSource& region) override;
	/** @vidx {i} */ MC virtual void onMove() override;
	/** @vidx {i} */ MC virtual void onRemoved(BlockSource& region) override;
	/** @vidx {i} */ MC virtual void onNeighborChanged(BlockSource& region, const BlockPos& pos) override;
	/** @vidx {i} */ MC virtual std::string getName() const override;
	/** @vidx {i} */ MC virtual Container* getContainer() override;
	/** @vidx {i} */ MC virtual const Container* getContainer() const override;
	/** @vidx {i} */ MC virtual void fixupOnLoad(LevelChunk& chunk) override;
	/** @vidx {i} */ MC virtual std::unique_ptr<BlockActorDataPacket> _getUpdatePacket(BlockSource& region) override;
	/** @vidx {i} */ MC virtual void _onUpdatePacket(const CompoundTag& tag, BlockSource& region) override;

	/** @vidx {i, Container} */
	MC virtual void serverInitItemStackIds(int containerSlot, int count, std::function<void(int, const ItemStack&)> onNetIdChanged) override;
	/** @vidx {i, Container} */
	MC virtual const ItemStack& getItem(int slot) const override;
	/** @vidx {i, Container} */
	MC virtual void setItem(int slot, const ItemStack& itemStack) override;
	/** @vidx {i, Container} */
	MC virtual int getMaxStackSize() const override;
	/** @vidx {i, Container} */
	MC virtual int getContainerSize() const override;
	/** @vidx {i, Container} */
	MC virtual void startOpen(Player& player) override;
	/** @vidx {i, Container} */
	MC virtual void stopOpen(Player& player) override;
	/** @vidx {i, Container} */
	MC virtual bool canPushInItem(int slot, int face, const ItemStack& itemStack) const override;
	/** @vidx {i, Container} */
	MC virtual bool canPullOutItem(int slot, int face, const ItemStack& itemStack) const override;
	/** @vidx {i, Container} */
	MC virtual bool hasGetStrictParsingVersion() override;
};

static_assert(sizeof(FurnaceBlockActor) == 1344, "Size of FurnaceBlockActor doesn't match what's expected!");