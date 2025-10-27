/// @symbols
#pragma once
#include <gsl/gsl>
#include <vector>
#include <memory>
#include <string>
#include <optional>

#include "mc/src/common/world/entity/EntityContext.hpp"
#include <mc/src/common/gamerefs/WeakRef.hpp>
#include <mc/src/common/world/actor/Actor.hpp>
#include <mc/src/common/world/actor/ActorDamageSource.hpp>
#include <mc/src/common/world/phys/Vec3.hpp>
#include <mc/src-deps/core/math/Color.hpp>
#include <mc/src/common/ActorUniqueID.hpp>
#include <mc/src/common/world/phys/AABB.hpp>
#include <mc/src/common/world/level/material/MaterialType.hpp>
#include <mc/src/common/world/level/BlockPos.hpp>
#include <mc/src/common/world/level/dimension/Dimension.hpp>
#include <mc/src-deps/core/utility/AutomaticID.hpp>
#include <mc/src/common/world/item/Item.hpp>
#include <mc/src-deps/shared_types/legacy/LevelSoundEvent.hpp>
#include <mc/src/common/world/actor/ActorFlags.hpp>
#include <mc/src/common/world/actor/ActorType.hpp>
#include <mc/src/common/world/actor/player/Abilities.hpp>
#include <mc/src-deps/input/InputMode.hpp>

enum class ActorInitializationMethod : __int8 {
    INVALID = 0x0,
    LOADED = 0x1,
    SPAWNED = 0x2,
    BORN = 0x3,
    TRANSFORMED = 0x4,
    UPDATED = 0x5,
    EVENT = 0x6,
    LEGACY = 0x7,
};

class AddActorBasePacket;

// Auto-generated: Unknown complete types
enum NewInteractionModel {};

namespace Puv {
    namespace Legacy {
        enum EquipmentSlot {};
    } // namespace Legacy
} // namespace Puv

enum ArmorSlot {};
enum HandSlot {};
enum ArmorMaterialType {};

// Auto-generated: Forward declarations
class AABBShapeComponent;
class HashedString;
class VariantParameterList;
class ActorDamageSource;
class Actor;
class IConstBlockSource;
class Block;
class ItemStack;
class CompoundTag;
class DataLoadHelper;
struct PlayerMovementSettings;
class MobEffectInstance;
class AnimationComponent;
class Player;
class ItemStackBase;
class ActorInteraction;
class EntityContext;
class DefaultDataLoadHelper;
class ActorWalkAnimationComponent;
class StateVectorComponent;
class ActorRotationComponent;
class Vec2;
class Vec3;

struct BuiltInActorComponents {
    gsl::not_null<StateVectorComponent*> mStateVectorComponent;
    gsl::not_null<AABBShapeComponent*> mAABBShapeComponent;
    gsl::not_null<ActorRotationComponent*> mActorRotationComponent;
    gsl::not_null<ActorWalkAnimationComponent*> mWalkAnimationComponent;
};


/// @vptr {0x4DBE658}
class Actor {
public:
    /* this + 8   */ EntityContext mEntityContext;
    /* this + 32  */ ActorInitializationMethod mInitMethod;
    /* this + 33  */ std::byte padding33[576 - 33];
    /* this + 576 */ std::weak_ptr<Dimension> mDimension; // moved -16 in 1.21
    /* this + 592 */ ILevel* mLevel;
    /* this + 600 */ std::byte padding592[56];
    /* this + 656 */ BuiltInActorComponents mBuiltInComponents; // 1.21
    /* this + 688 */ std::byte padding688[408];

public:
	MC static uintptr_t $vtable_for_this;

    Vec3* getPosition() const;
    Vec2* getHeadRot() const;
    void moveTo(const Vec3&, const Vec2&);
    float distanceTo(const Vec3& other) const;

    const Dimension& getDimensionConst() const;
    const BlockSource& getDimensionBlockSourceConst() const;
    BlockSource& getDimensionBlockSource() const;
    bool hasDimension() const;
    void setDimension(WeakRef<Dimension> dimension);

    ILevel* getLevel() const
    {
        return mLevel;
    }

    // Generics
    template <typename T>
    const T* tryGetComponent() const
    {
        const auto& registry = mEntityContext.getRegistry();
        return registry.try_get<T>(mEntityContext.mEntity);
    }

    template <typename T>
    T* tryGetComponent()
    {
        auto& registry = mEntityContext.getRegistry();
        return registry.try_get<T>(mEntityContext.mEntity);
    }

    template <typename T>
    bool hasComponent() const
    {
        const auto& registry = mEntityContext.getRegistry();
        return registry.all_of<T>(mEntityContext.mEntity);
    }

    template <typename T, typename... Args>
    T& addComponent(Args&&... args)
    {
        auto& registry = mEntityContext.getRegistry();
        Assert(!registry.all_of<T>(mEntityContext.mEntity), "Entity already has component");
        return registry.emplace<T>(mEntityContext.mEntity, std::forward<Args>(args)...);
    }

    //int load(const CompoundTag&, DefaultDataLoadHelper&);
    void reload();

    bool isClientSide() const;
    bool isCreative() const;

    ActorUniqueID getUniqueID() const;

    /**@vidx {0}*/
    MC virtual bool getStatusFlag(ActorFlags unk0) const;

    /**@vidx {1}*/
    MC virtual void setStatusFlag(ActorFlags unk0, bool unk1);

    /**@vidx {2}*/
    MC virtual bool hasComponent(const HashedString& unk0) const;

    /**@vidx {3}*/
    MC virtual void outOfWorld();

    /**@vidx {4}*/
    MC virtual void reloadHardcoded(ActorInitializationMethod unk0, const VariantParameterList& unk1);

    /**@vidx {5}*/
    MC virtual void reloadHardcodedClient(ActorInitializationMethod unk0, const VariantParameterList& unk1);

    /**@vidx {6}*/
    MC virtual void initializeComponents(ActorInitializationMethod unk0, const VariantParameterList& unk1);

    /**@vidx {7}*/
    MC virtual void reloadComponents(ActorInitializationMethod unk0, const VariantParameterList& unk1);

    /**@vidx {8}*/
    MC virtual void _serverInitItemStackIds();

    /**@vidx {9}*/
    MC virtual void _doInitialMove();

    /**@vidx {10}*/
    MC virtual ~Actor();

    /**@vidx {11}*/
    MC virtual void _unknown_11(); // resetUserPos

    /**@vidx {12}*/
    MC virtual ActorType getOwnerEntityType();

    /**@vidx {13}*/
    MC virtual void remove();

    /**@vidx {14}*/
    MC virtual Vec3 getFiringPos() const;

    /**@vidx {15}*/
    MC virtual float getInterpolatedBodyRot(float unk0) const;

    /**@vidx {16}*/
    MC virtual float getInterpolatedHeadRot(float unk0) const;

    /**@vidx {17}*/
    MC virtual float getInterpolatedBodyYaw(float unk0) const;

    /**@vidx {18}*/
    MC virtual float getYawSpeedInDegreesPerSecond() const;

    /**@vidx {19}*/
    MC virtual Vec3 getInterpolatedRidingOffset(float unk0, int unk1) const;

    /**@vidx {20}*/
    MC virtual bool isFireImmune() const;

    /**@vidx {21}*/
    MC virtual void blockedByShield(const ActorDamageSource& unk0, Actor& unk1);

    /**@vidx {22}*/
    MC virtual bool canDisableShield();

    /**@vidx {23}*/
    MC virtual void teleportTo(const Vec3& unk0, bool unk1, int unk2, int unk3, bool unk4);

    /**@vidx {24}*/
    MC virtual void lerpMotion(const Vec3& unk0);

    /**@vidx {25}*/
    MC virtual std::unique_ptr<AddActorBasePacket> tryCreateAddActorPacket();

    /**@vidx {26}*/
    MC virtual void normalTick();

    /**@vidx {27}*/
    MC virtual void baseTick();

    /**@vidx {28}*/
    MC virtual void passengerTick();

    /**@vidx {29}*/
    MC virtual bool startRiding(Actor& unk0);

    /**@vidx {30}*/
    MC virtual void addPassenger(Actor& unk0);

    /**@vidx {31}*/
    MC virtual std::string getExitTip(const std::string& unk0, InputMode unk1, NewInteractionModel unk2) const;

    /**@vidx {32}*/
    MC virtual std::string getEntityLocNameString() const;

    /**@vidx {33}*/
    MC virtual bool isInWall() const;

    /**@vidx {34}*/
    MC virtual bool isInvisible() const;

    /**@vidx {35}*/
    MC virtual bool canShowNameTag() const;

    /**@vidx {36}*/
    MC virtual std::string getFormattedNameTag() const;

    /**@vidx {37}*/
    MC virtual mce::Color getNameTagTextColor() const;

    /**@vidx {38}*/
    MC virtual float getShadowRadius() const;

    /**@vidx {39}*/
    MC virtual Vec3 getHeadLookVector(float unk0) const;

    /**@vidx {40}*/
    MC virtual void _unknown_40();

    /**@vidx {41}*/
    MC virtual float getBrightness(float unk0, const IConstBlockSource& unk1) const;

    /**@vidx {42}*/
    MC virtual void playerTouch(Player& unk0);

    /**@vidx {43}*/
    MC virtual bool isImmobile() const;

    /**@vidx {44}*/
    MC virtual void _unknown_44();

    /**@vidx {45}*/
    MC virtual bool isSleeping() const;

    /**@vidx {46}*/
    MC virtual void setSleeping(bool unk0);

    /**@vidx {47}*/
    MC virtual void setSneaking(bool unk0);

    /**@vidx {48}*/
    MC virtual bool isBlocking() const;

    /**@vidx {49}*/
    MC virtual void _unknown_49();

    /**@vidx {50}*/
    MC virtual bool isAlive() const;

    /**@vidx {51}*/
    MC virtual bool isOnFire() const;

    /**@vidx {52}*/
    MC virtual bool isSurfaceMob() const;

    /**@vidx {53}*/
    MC virtual void _unknown_53();

    /**@vidx {54}*/
    MC virtual bool canAttack(Actor* unk0, bool unk1) const;

    /**@vidx {55}*/
    MC virtual void setTarget(Actor* unk0);

    /**@vidx {56}*/
    MC virtual void _unknown_56();

    /**@vidx {57}*/
    MC virtual bool attack(Actor& unk0, const ActorDamageCause& unk1);

    /**@vidx {58}*/
    MC virtual void performRangedAttack(Actor& unk0, float unk1);

    /**@vidx {59}*/
    MC virtual void setOwner(ActorUniqueID unk0);

    /**@vidx {60}*/
    MC virtual void setSitting(bool unk0);

    /**@vidx {61}*/
    MC virtual void _unknown_61();

    /**@vidx {62}*/
    MC virtual void _unknown_62();

    /**@vidx {63}*/
    MC virtual void setStanding(bool unk0);

    /**@vidx {64}*/
    MC virtual bool canPowerJump() const;

    /**@vidx {65}*/
    MC virtual bool isEnchanted() const;

    /**@vidx {66}*/
    MC virtual bool shouldRender() const;

    /**@vidx {67}*/
    MC virtual void playAmbientSound();

    /**@vidx {68}*/
    MC virtual Puv::Legacy::LevelSoundEvent getAmbientSound() const;

    /**@vidx {69}*/
    MC virtual bool isInvulnerableTo(const ActorDamageSource& unk0) const;

    /**@vidx {70}*/
    MC virtual ActorDamageCause getBlockDamageCause(const Block& unk0) const;

    /**@vidx {71}*/
    MC virtual bool doFireHurt(int unk0);

    /**@vidx {72}*/
    MC virtual void onLightningHit();

    /**@vidx {73}*/
    MC virtual void feed(int unk0);

    /**@vidx {74}*/
    MC virtual void handleEntityEvent(ActorEvent unk0, int unk1);

    /**@vidx {75}*/
    MC virtual const HashedString& getActorRendererId() const;

    /**@vidx {76}*/
    MC virtual void despawn();

    /**@vidx {77}*/
    MC virtual void setArmor(ArmorSlot unk0, const ItemStack& unk1);

    /**@vidx {78}*/
    MC virtual ArmorMaterialType getArmorMaterialTypeInSlot(ArmorSlot unk0) const;

    /**@vidx {79}*/
    MC virtual int getArmorTextureIndexInSlot(ArmorSlot unk0) const;

    /**@vidx {80}*/
    MC virtual float getArmorColorInSlot(ArmorSlot unk0, int unk1) const;

    /**@vidx {81}*/
    MC virtual void setEquippedSlot(Puv::Legacy::EquipmentSlot unk0, const ItemStack& unk1);

    /**@vidx {82}*/
    MC virtual void setCarriedItem(const ItemStack& unk0);

    /**@vidx {83}*/
    MC virtual const ItemStack& getCarriedItem() const;

    /**@vidx {84}*/
    MC virtual void setOffhandSlot(const ItemStack& unk0);

    /**@vidx {85}*/
    MC virtual const ItemStack& getEquippedTotem() const;

    /**@vidx {86}*/
    MC virtual bool consumeTotem();

    /**@vidx {87}*/
    MC virtual bool save(CompoundTag& unk0) const;

    /**@vidx {88}*/
    MC virtual bool load(const CompoundTag& unk0, DataLoadHelper& unk1);

    /**@vidx {89}*/
    MC virtual const HashedString& queryEntityRenderer() const;

    /**@vidx {90}*/
    MC virtual ActorUniqueID getSourceUniqueID() const;

    /**@vidx {91}*/
    MC virtual bool canFreeze() const;

    /**@vidx {92}*/
    MC virtual AABB getLiquidAABB(MaterialType unk0) const;

    /**@vidx {93}*/
    MC virtual void handleInsidePortal(const BlockPos& unk0);

    /**@vidx {94}*/
    MC virtual bool canChangeDimensionsUsingPortal() const;

    /**@vidx {95}*/
    MC virtual void _unknown_95();

    /**@vidx {96}*/
    MC virtual void changeDimension(AutomaticID<Dimension, int> unk0);

    /**@vidx {97}*/
    MC virtual ActorUniqueID getControllingPlayer() const;

    /**@vidx {98}*/
    MC virtual float causeFallDamageToActor(float unk0, float unk1, ActorDamageSource unk2);

    /**@vidx {99}*/
    MC virtual void onSynchedDataUpdate(int unk0);

    /**@vidx {100}*/
    MC virtual bool canAddPassenger(Actor& unk0) const;

    /**@vidx {101}*/
    MC virtual void _unknown_101();

    /**@vidx {102}*/
    MC virtual bool canBePulledIntoVehicle() const;

    /**@vidx {103}*/
    MC virtual bool inCaravan() const;

    /**@vidx {104}*/
    MC virtual void sendMotionPacketIfNeeded(const PlayerMovementSettings& unk0);

    /**@vidx {105}*/
    MC virtual bool canSynchronizeNewEntity() const;

    /**@vidx {106}*/
    MC virtual void startSwimming();

    /**@vidx {107}*/
    MC virtual void stopSwimming();

    /**@vidx {108}*/
    MC virtual void buildDebugInfo(std::string& unk0) const;

    /**@vidx {109}*/
    MC virtual CommandPermissionLevel getCommandPermissionLevel() const;

    /**@vidx {110}*/
    MC virtual int getDeathTime() const;

    /**@vidx {111}*/
    MC virtual bool canBeAffected(unsigned int unk0) const;

    /**@vidx {112}*/
    MC virtual bool canBeAffectedByArrow(const MobEffectInstance& unk0) const;

    /**@vidx {113}*/
    MC virtual void onEffectRemoved(MobEffectInstance& unk0);

    /**@vidx {114}*/
    MC virtual bool canObstructSpawningAndBlockPlacement() const;

    /**@vidx {115}*/
    MC virtual AnimationComponent& getAnimationComponent();

    /**@vidx {116}*/
    MC virtual void openContainerComponent(Player& unk0);

    /**@vidx {117}*/
    MC virtual void swing();

    /**@vidx {118}*/
    MC virtual void useItem(ItemStackBase& unk0, ItemUseMethod unk1, bool unk2);

    /**@vidx {119}*/
    MC virtual void getDebugText(std::vector<std::string>& unk0);

    /**@vidx {120}*/
    MC virtual float getMapDecorationRotation() const;

    /**@vidx {121}*/
    MC virtual float getPassengerYRotation(const Actor& unk0) const;

    /**@vidx {122}*/
    MC virtual bool add(ItemStack& unk0);

    /**@vidx {123}*/
    MC virtual bool drop(const ItemStack& unk0, bool unk1);

    /**@vidx {124}*/
    MC virtual bool getInteraction(Player& unk0, ActorInteraction& unk1, const Vec3& unk2);

    /**@vidx {125}*/
    MC virtual void _unknown_125();

    /**@vidx {126}*/
    MC virtual void _unknown_126();

    /**@vidx {127}*/
    MC virtual void startSpinAttack();

    /**@vidx {128}*/
    MC virtual void _unknown_128();

    /**@vidx {129}*/
    MC virtual void _unknown_129();

    /**@vidx {130}*/
    MC virtual void kill();

    /**@vidx {131}*/
    MC virtual void die(const ActorDamageSource& unk0);

    /**@vidx {132}*/
    MC virtual bool shouldDropDeathLoot() const;

    /**@vidx {133}*/
    MC virtual void applySnapshot(const EntityContext& unk0, const EntityContext& unk1);

    /**@vidx {134}*/
    MC virtual float getNextStep(float unk0);

    /**@vidx {135}*/
    MC virtual void _unknown_135();

    /**@vidx {136}*/
    MC virtual std::optional<BlockPos> getLastDeathPos() const;

    /**@vidx {137}*/
    MC virtual std::optional<AutomaticID<Dimension, int>> getLastDeathDimension() const;

    /**@vidx {138}*/
    MC virtual void _unknown_138();

    /**@vidx {139}*/
    MC virtual void _unknown_139();

    /**@vidx {140}*/
    MC virtual void _unknown_140();

    /**@vidx {141}*/
    MC virtual void doWaterSplashEffect();

    /**@vidx {142}*/
    MC virtual bool _shouldProvideFeedbackOnHandContainerItemSet(HandSlot unk0, const ItemStack& unk1) const;

    /**@vidx {143}*/
    MC virtual bool _shouldProvideFeedbackOnArmorSet(ArmorSlot unk0, const ItemStack& unk1) const;

    /**@vidx {144}*/
    MC virtual void updateEntitySpecificMolangVariables(RenderParams& unk0);

    /**@vidx {145}*/
    MC virtual bool shouldTryMakeStepSound();

    /**@vidx {146}*/
    MC virtual bool _hurt(const ActorDamageSource& unk0, float unk1, bool unk2, bool unk3);

    /**@vidx {147}*/
    MC virtual void readAdditionalSaveData(const CompoundTag& unk0, DataLoadHelper& unk1);

    /**@vidx {148}*/
    MC virtual void addAdditionalSaveData(CompoundTag& unk0) const;

    /**@vidx {149}*/
    MC virtual void _playStepSound(const BlockPos& unk0, const Block& unk1);

    /**@vidx {150}*/
    MC virtual void _unknown_150();

	/** @sig {40 56 57 48 83 EC ? 8B 41} */
	MC float calculateAttackDamage(Actor& target) const;
};

// 1.21.0.3
static_assert(sizeof(Actor) == 1096);