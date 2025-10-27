#pragma once

enum class ActorDamageCause : int32_t {
	None = 0xff,
	Override = 0x0000,
	Contact = 0x0001,
	EntityAttack = 0x0002,
	Projectile = 0x0003,
	Suffocation = 0x0004,
	Fall = 0x0005,
	Fire = 0x0006,
	FireTick = 0x0007,
	Lava = 0x0008,
	Drowning = 0x0009,
	BlockExplosion = 0x000a,
	EntityExplosion = 0x000b,
	Void = 0x000c,
	Suicide = 0x000d,
	Magic = 0x000e,
	Wither = 0x000f,
	Starve = 0x0010,
	Anvil = 0x0011,
	Thorns = 0x0012,
	FallingBlock = 0x0013,
	Piston = 0x0014,
	FlyIntoWall = 0x0015,
	Magma = 0x0016,
	Fireworks = 0x0017,
	Lightning = 0x0018,
	Charging = 0x0019,
	Temperature = 0x001a,
	All = 0x001f,
};

class ActorDamageSource {
public:
	ActorDamageCause mCause;
	virtual ~ActorDamageSource() = default;
};