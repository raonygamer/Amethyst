/// @symbols
#pragma once
#include <string>
#include <vector>
#include <memory>

#include <mc/src/common/world/phys/AABB.hpp>
#include <mc/src-deps/core/utility/NonOwnerPointer.hpp>
#include <mc/src/common/world/level/BlockPos.hpp>
#include <mc/src/common/world/level/block/Block.hpp>
#include <mc/src/common/world/actor/ActorTerrainInterlockData.hpp>
#include <mc/src/common/world/level/block/actor/BlockActorRendererId.hpp>
#include <mc/src/common/network/packet/BlockActorDataPacket.hpp>
#include <gsl/gsl>
#include <amethyst/Imports.hpp>

//#include <amethyst/Imports.hpp>

// Auto-generated: Unknown complete types
class UIProfanityContext {}; 

// Auto-generated: Forward declarations
class Level;
class CompoundTag;
class DataLoadHelper;
class BlockSource;
class IConstBlockSource;
class PistonBlockActor;
class Container;
class LevelChunk;
class Player;
class SaveContext;
class BlockLegacy;
class BlockActor;

class BlockActorFactory {
public:
	/// @signature {48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 49 8B F8 44 8B EA}
	MC static std::shared_ptr<BlockActor> createBlockEntity(BlockActorType type, const BlockPos& pos, const BlockLegacy& block);
};

/// @vptr {0x4E6F588}
class BlockActor {
public:
    /* this + 008 */ int mTickCount;
    /* this + 016 */ const Block* mBlock;
    /* this + 024 */ float mDestroyTimer;
    /* this + 028 */ Vec3 mDestroyDirection;
    /* this + 040 */ float mDestroyProgress;
    /* this + 044 */ BlockPos mPosition;
    /* this + 056 */ AABB mBB;
    /* this + 080 */ const BlockActorType mType;
    /* this + 084 */ BlockActorRendererId mRendererId;
    /* this + 088 */ std::string mCustomName;
    /* this + 120 */ std::string mFilteredCustomName;
    /* this + 152 */ int mRepairCost;
    /* this + 156 */ bool mClientSideOnly;
    /* this + 157 */ bool mIsMovable;
    /* this + 158 */ bool mSaveCustomName;
    /* this + 159 */ bool mCanRenderCustomName;
    /* this + 160 */ const float signShadowRadius;
    /* this + 168 */ ActorTerrainInterlockData mTerrainInterlockData;
    /* this + 192 */ bool mChanged;

public:
    /// @signature {48 83 EC ? 45 33 C9 0F 29 34 24}
    MC BlockActor(BlockActorType type, const BlockPos& pos, const std::string& id);

    /// @vidx {0}
    MC virtual ~BlockActor();

    /// @vidx {1}
    MC virtual void load(Level& unk0, const CompoundTag& unk1, DataLoadHelper& unk2);

    /// @vidx {2}
    MC virtual bool save(CompoundTag& unk0) const;

    /// @vidx {3}
    MC virtual bool saveItemInstanceData(CompoundTag& unk0) const;

    /// @vidx {4}
    MC virtual void saveBlockData(CompoundTag& unk0, BlockSource& unk1) const;

    /// @vidx {5}
    MC virtual void loadBlockData(const CompoundTag& unk0, BlockSource& unk1, DataLoadHelper& unk2);

    /// @vidx {6}
    MC virtual void onCustomTagLoadDone(BlockSource& unk0);

    /// @vidx {7}
    MC virtual void tick(BlockSource& unk0);

    /// @vidx {8}
    MC virtual void onChanged(BlockSource& unk0);

    /// @vidx {9}
    MC virtual bool isMovable(BlockSource& unk0);

    /// @vidx {10}
    MC virtual bool isCustomNameSaved();

    /// @vidx {11}
    MC virtual void onPlace(BlockSource& unk0);

    /// @vidx {12}
    MC virtual void onMove();

    /// @vidx {13}
    MC virtual void onRemoved(BlockSource& unk0);

    /// @vidx {14}
    MC virtual bool isPreserved(BlockSource& unk0) const;

    /// @vidx {15}
    MC virtual bool shouldPreserve(BlockSource& unk0);

    /// @vidx {16}
    MC virtual void triggerEvent(int unk0, int unk1);

    /// @vidx {17}
    MC virtual void clearCache();

    /// @vidx {18}
    MC virtual void onNeighborChanged(BlockSource& unk0, const BlockPos& unk1);

    /// @vidx {19}
    MC virtual float getShadowRadius(BlockSource& unk0) const;

    /// @vidx {20}
    MC virtual bool hasAlphaLayer() const;

    /// @vidx {21}
    MC virtual BlockActor* getCrackEntity(BlockSource& unk0, const BlockPos& unk1);

    /// @vidx {22}
    MC virtual AABB getCollisionShape(const IConstBlockSource& unk0) const;

    /// @vidx {23}
    MC virtual void getDebugText(std::vector<std::string>& unk0, const BlockPos& unk1);

    /// @vidx {24}
    MC virtual const std::string& getCustomName() const;

    /// @vidx {25}
    MC virtual const std::string& getFilteredCustomName(const gsl::not_null<Bedrock::NonOwnerPointer<UIProfanityContext>>& unk0);

    /// @vidx {26}
    MC virtual std::string getName() const;

    /// @vidx {27}
    MC virtual void setCustomName(const std::string& unk0);

    /// @vidx {28}
    MC virtual std::string getImmersiveReaderText(BlockSource& unk0);

    /// @vidx {29}
    MC virtual int getRepairCost() const;

    /// @vidx {30}
    MC virtual PistonBlockActor* getOwningPiston(BlockSource& unk0);

    /// @vidx {31}
    MC virtual const PistonBlockActor* getOwningPiston(BlockSource& unk0) const;

    /// @vidx {32}
    MC virtual Container* getContainer();

    /// @vidx {33}
    MC virtual const Container* getContainer() const;

    /// @vidx {34}
    MC virtual void eraseLootTable();

    /// @vidx {35}
    MC virtual void onChunkLoaded(LevelChunk& unk0);

    /// @vidx {36}
    MC virtual void onChunkUnloaded(LevelChunk& unk0);

    /// @vidx {37}
    MC virtual std::vector<std::string> getUgcStrings(const CompoundTag& unk0) const;

    /// @vidx {38}
    MC virtual void setUgcStrings(CompoundTag& unk0, const std::vector<std::string>& unk1) const;

    /// @vidx {39}
    MC virtual void fixupOnLoad(LevelChunk& unk0);

    /// @vidx {40}
    MC virtual std::unique_ptr<BlockActorDataPacket> _getUpdatePacket(BlockSource& unk0);

    /// @vidx {41}
    MC virtual void _onUpdatePacket(const CompoundTag& unk0, BlockSource& unk1);

    /// @vidx {42}
    MC virtual bool _playerCanUpdate(const Player& unk0) const;

public:
    void moveTo(const BlockPos& pos);
};

static_assert(sizeof(BlockActor) == 200);