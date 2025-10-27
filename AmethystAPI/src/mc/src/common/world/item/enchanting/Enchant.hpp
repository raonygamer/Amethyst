/// @symbols
#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include <amethyst/Imports.hpp>

class ActorDamageSource;
class Actor;
class ItemInstance;

/** @vptr {48 8D 05 ? ? ? ? 48 89 01 88 51 ? 44 89 41} */
class Enchant {
public:
	// ty Levi for enums
	enum class Type : uint8_t {
		Protection = 0,
		FireProtection = 1,
		FeatherFalling = 2,
		BlastProtection = 3,
		ProjectileProtection = 4,
		Thorns = 5,
		Respiration = 6,
		DepthStrider = 7,
		AquaAffinity = 8,
		Sharpness = 9,
		Smite = 10,
		BaneOfArthropods = 11,
		Knockback = 12,
		FireAspect = 13,
		Looting = 14,
		Efficiency = 15,
		SilkTouch = 16,
		Unbreaking = 17,
		Fortune = 18,
		Power = 19,
		Punch = 20,
		Flame = 21,
		Infinity = 22,
		LuckOfTheSea = 23,
		Lure = 24,
		FrostWalker = 25,
		Mending = 26,
		CurseOfBinding = 27,
		CurseOfVanishing = 28,
		Impaling = 29,
		Riptide = 30,
		Loyalty = 31,
		Channeling = 32,
		Multishot = 33,
		Piercing = 34,
		QuickCharge = 35,
		SoulSpeed = 36,
		SwiftSneak = 37,
		WindBurst = 38,
		Density = 39,
		Breach = 40,
		NumEnchantments = 41,
		InvalidEnchantment = 42,
	};

	enum class Frequency : int {
		Common = 30,
		Uncommon = 10,
		Rare = 3,
		VeryRare = 1,
	};

	enum class Slot : uint32_t {
		None = 0,
		ArmorHead = 1u << 0,
		ArmorTorso = 1u << 1,
		ArmorFeet = 1u << 2,
		ArmorLegs = 1u << 3,
		Sword = 1u << 4,
		Bow = 1u << 5,
		Hoe = 1u << 6,
		Shears = 1u << 7,
		Flintsteel = 1u << 8,
		Axe = 1u << 9,
		Pickaxe = 1u << 10,
		Shovel = 1u << 11,
		FishingRod = 1u << 12,
		CarrotStick = 1u << 13,
		Elytra = 1u << 14,
		Spear = 1u << 15,
		Crossbow = 1u << 16,
		Shield = 1u << 17,
		CosmeticHead = 1u << 18,
		Compass = 1u << 19,
		MushroomStick = 1u << 20,
		Brush = 1u << 21,
		HeavyWeapon = 1u << 22,
		GArmor = ArmorHead | ArmorTorso | ArmorFeet | ArmorLegs,
		GDigging = Hoe | Axe | Pickaxe | Shovel,
		GTool = Hoe | Shears | Flintsteel | Shield,
		All = 4294967295,
	};

	enum class Activation : int {
		Equipped = 0,
		Held = 1,
		Self = 2,
		NumActivations = 3,
		Invalid = 4,
	};

	enum class CompatibilityID : int {
		NonConflict = 0,
		Damage = 1,
		Gathering = 2,
		Protection = 3,
		Froststrider = 4,
		Mendfinity = 5,
		Loyalriptide = 6,
	};

	enum class VillagerTrading : int {
		NotAvailable = 0,
		Available = 1,
	};

public:
	// 1.21.0.3
	// No 'lea reg, [rip+disp32]' found, using direct address
	/** @addr {0x59DD368} */
	MC static std::vector<std::unique_ptr<Enchant>> mEnchants;
	
	const Enchant::Type mEnchantType;
	const Enchant::Frequency mFrequency;
	const bool mIsAvailableInVillagerTrading;
	const int mPrimarySlots;
	const int mSecondarySlots;
	const int mCompatibility;
	const std::string mDescription;
	const HashedString mStringId;
	const HashedString mScriptStringId;
	bool mIsDisabled;

	/** @sig {E8 ? ? ? ? 48 89 33 EB ? 49 8B DE 48 8B 05 ? ? ? ? 48 8B 48} */
	MC Enchant(Enchant::Type type, Enchant::Frequency frequency, std::string_view stringId, std::string_view description, int primarySlots, int secondarySlots, bool isLootable);
	/** @vidx {00} */ MC virtual ~Enchant() = default;
	/** @vidx {01} */ MC virtual bool isCompatibleWith(Enchant::Type) const;
	/** @vidx {02} */ MC virtual int32_t getMinCost(int32_t) const;
	/** @vidx {03} */ MC virtual int32_t getMaxCost(int32_t) const;
	/** @vidx {04} */ MC virtual int32_t getMinLevel() const;
	/** @vidx {05} */ MC virtual int32_t getMaxLevel() const;
	/** @vidx {06} */ MC virtual int32_t getDamageProtection(int32_t, const ActorDamageSource&) const;
	/** @vidx {07} */ MC virtual float getAfterBreachArmorFraction(int, float) const;
	/** @vidx {08} */ MC virtual float getDamageBonus(int32_t, const Actor&) const;
	/** @vidx {09} */ MC virtual void doPostAttack(Actor&, Actor&, int32_t) const;
	/** @vidx {10} */ MC virtual void doPostItemHurtActor(Actor&, Actor&, int) const;
	/** @vidx {11} */ MC virtual void doPostHurt(ItemInstance&, Actor&, Actor&, int32_t) const;
	/** @vidx {12} */ MC virtual bool isMeleeDamageEnchant() const;
	/** @vidx {13} */ MC virtual bool isProtectionEnchant() const;
	/** @vidx {14} */ MC virtual bool isTreasureOnly() const;
	/** @vidx {15} */ MC virtual bool isDiscoverable() const;
	/** @vidx {16} */ MC virtual bool _isValidEnchantmentTypeForCategory(::Enchant::Type type) const;
};
