///@symbolgeneration
#pragma once
#include <amethyst/Imports.hpp>
#include <memory>
#include <chrono>
#include <functional>
#include "mc/src/common/world/level/BlockPos.hpp"
#include "mc/src/common/world/phys/Vec3.hpp"
#include "mc/src/common/world/Facing.hpp"
#include "mc/src/common/world/item/Item.hpp"
#include <mc/src-deps/input/InputMode.hpp>

class Player;
class IGameModeTimer;
class IGameModeMessenger;
class ItemStack;

/// @vptr {0x4DE5338}
class GameMode {
public:
    class BuildContext {
    public:
        bool mHasBuildDirection;
        bool mHasLastBuiltPosition;
        bool mLastBuildBlockWasInteractive;
        bool mLastBuildBlockWasSnappable;
        BlockPos mLastBuiltBlockPosition;
        BlockPos mBuildDirection;
        BlockPos mNextBuildPos;
        unsigned char mContinueFacing;
    };

    Player& mPlayer;
    BlockPos mDestroyBlockPos;
    uint8_t mDestroyBlockFace;
    float mOldDestroyProgress;
    float mDestroyProgress;
    long double mLastDestroyTime;
    float mDistanceTravelled;
    Vec3 mPlayerLastPosition;
    GameMode::BuildContext mBuildContext;
    float mMinPlayerSpeed;
    int mContinueBreakBlockCount;

    std::chrono::steady_clock::time_point mLastBuildTime;
    std::chrono::steady_clock::time_point mNoDestroyUntil;
    std::chrono::steady_clock::time_point mNoDestroySoundUntil;

    std::chrono::milliseconds creativeDestructionTickDelay;
    std::chrono::milliseconds buildingTickDelay;
    std::chrono::milliseconds destroySoundDelay;

    std::unique_ptr<IGameModeTimer> mTimer;
    std::unique_ptr<IGameModeMessenger> mMessenger;

    /// @vidx {0}
    MC virtual ~GameMode();

    /// @vidx {1}
    MC virtual bool startDestroyBlock(const BlockPos& pos, FacingID face, bool& hasDestroyedBlock);

    /// @vidx {2}
    MC virtual bool destroyBlock(const BlockPos& pos, FacingID face);

    /// @vidx {3}
    MC virtual bool continueDestroyBlock(const BlockPos& pos, FacingID face, const Vec3& playerPos, bool& hasDestroyedBlock);

    /// @vidx {4}
    MC virtual void stopDestroyBlock(const BlockPos& pos);

    /// @vidx {5}
    MC virtual void startBuildBlock(const BlockPos& unk0, FacingID unk1);

    /// @vidx {6}
    MC virtual bool buildBlock(const BlockPos& unk0, FacingID unk1, bool unk2);

    /// @vidx {7}
    MC virtual void continueBuildBlock(const BlockPos& unk0, FacingID unk1);

    /// @vidx {8}
    MC virtual void stopBuildBlock();

    /// @vidx {9}
    MC virtual void tick();

    /// @vidx {10}
    MC virtual float getPickRange(const InputMode& unk0, bool unk1);

    /// @vidx {11}
    MC virtual bool useItem(ItemStack& unk0);

    /// @vidx {12}
    MC virtual InteractionResult useItemOn(ItemStack& item, const BlockPos pos, FacingID face, const Vec3& clickPos, const Block* block);

    /// @vidx {13}
    MC virtual bool interact(Actor& unk0, const Vec3& unk1);

    /// @vidx {14}
    MC virtual bool attack(Actor& unk0);

    /// @vidx {15}
    MC virtual void releaseUsingItem();

    /// @vidx {16}
    MC virtual void setTrialMode(bool unk0);

    /// @vidx {17}
    MC virtual bool isInTrialMode();

    /// @vidx {18}
    MC virtual void registerUpsellScreenCallback(std::function<void(bool)> unk0);

    MC static uintptr_t $vtable_for_this;

    __declspec(noinline) InteractionResult _sendUseItemOnEvents(ItemStack& item, const BlockPos& pos, FacingID face, const Vec3& clickPos) const
    {
        using function = decltype(&GameMode::_sendUseItemOnEvents);
        static auto func = std::bit_cast<function>(SigScan("40 55 53 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4D 8B F9 4D 8B E0 48 8B F2 4C 8B F1 4C 8B AD"));
        return (this->*func)(item, pos, face, clickPos);
    }

    void _sendPlayerInteractWithBlockAfterEvent(Player& player, const BlockPos& pos, FacingID face, const Vec3& at);

    bool _canUseBlock(const Block& block) const;

    float getMaxPickRange() const;

    bool baseUseItem(ItemStack& stack);

    bool isLastBuildBlockInteractive() const {
        return mBuildContext.mLastBuildBlockWasInteractive;
    }

    BlockPos _calculatePlacePos(ItemStack& heldStack, const BlockPos& pos, FacingID& face);
};