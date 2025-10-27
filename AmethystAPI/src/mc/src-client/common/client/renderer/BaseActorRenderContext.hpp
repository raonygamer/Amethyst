/// @symbolgeneration
#pragma once
#include <mc/src/common/world/phys/Vec3.hpp>
#include <mc/src/common/world/phys/AABB.hpp>
#include <amethyst/Imports.hpp>

class ScreenContext;

class MinecraftGame;
using IMinecraftGame = MinecraftGame;

class ClientInstance;
class IClientInstance;
class ItemRenderer;
struct SortedMeshDrawList;
class BlockActorRenderDispatcher;
class ActorRenderDispatcher;
class ItemInHandRenderer;
struct ActorBlockRenderer;
class ParticleSystemEngine;
class MatrixStack;

/** @vptr {48 8D 05 ? ? ? ? 4C 8B C1 48 89 01 8B 42} */
class BaseActorRenderContext {
public:
    /* this + 8   */ float mNumEntitiesRenderedThisFrame;
    /* this + 12  */ float mLastFrameTime;
    /* this + 16  */ SortedMeshDrawList* mSortedMeshDrawList;
    /* this + 24  */ ClientInstance* mClientInstance;
    /* this + 32  */ MinecraftGame* mMinecraftGame;
    /* this + 40  */ ScreenContext* mScreenContext;
    /* this + 48  */ BlockActorRenderDispatcher* mBlockEntityRenderDispatcher;
    /* this + 56  */ std::shared_ptr<ActorRenderDispatcher> mEntityRenderDispatcher;
    /* this + 72  */ ActorBlockRenderer* mEntityBlockRenderer;
    /* this + 80  */ ItemInHandRenderer* mItemInHandRenderer;
    /* this + 88  */ ItemRenderer* itemRenderer;
    /* this + 96  */ ParticleSystemEngine* mParticleEngineSystem;
    /* this + 104 */ std::optional<uint64_t> mRenderUniqueIdOverride;
    /* this + 120 */ Vec3 mCameraTargetPosition;
    /* this + 132 */ Vec3 mCameraPosition;
    /* this + 144 */ AABB mWorldClipRegion;
    /* this + 168 */ float mFrameAlpha;
    /* this + 172 */ bool mIsOnScreen;
    /* this + 173 */ bool mUpdateBonesAndEffects;
    /* this + 174 */ bool mUpdateEffects;
    /* this + 175 */ bool mIgnoresLighting;
    /* this + 176 */ bool mForceLightingOn;
    /* this + 177 */ std::byte mHistoricalFrameTimes[0x1E7];

public:
    /** @sig {E8 ? ? ? ? 90 41 0F B6 D7} */
    MC BaseActorRenderContext(ScreenContext& screenContext, ClientInstance& clientInstance, IMinecraftGame& minecraftGame);
	/** @vidx {0} */ MC virtual ~BaseActorRenderContext();

    MatrixStack& getWorldMatrix();
};

static_assert(sizeof(BaseActorRenderContext) == 0x298);