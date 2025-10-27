/// @symbols
#pragma once
#include <unordered_map>
#include "amethyst/Imports.hpp"
#include "mc/src-deps/core/string/StringHash.hpp"
#include "mc/src-deps/core/utility/NonOwnerPointer.hpp"

class ParticleEffectGroup;
class BlockSource;
class LightTexture;
class ParticleSystemEngine :
	public Bedrock::EnableNonOwnerReferences
{
public:
	/** this + 0024 */ std::byte padding0[4280];
	/** this + 4304 */ std::unordered_map<HashedString, uint64_t> mEffectEmitterCounts;
	/** this + 4368 */ std::unordered_map<HashedString, uint64_t> mEffectParticleCounts;

	/** @sig {48 89 5C 24 ? 48 89 6C 24 ? 48 89 4C 24 ? 56 57 41 56 48 83 EC ? 49 8B F1 49 8B F8 48 8B DA 4C 8B F1 48 8D 05} */
	MC ParticleSystemEngine(ParticleEffectGroup& effectGroup, BlockSource& region, LightTexture& texture);

	/** @sig {48 89 5C 24 ? 48 89 6C 24 ? 48 89 4C 24 ? 56 57 41 56 48 83 EC ? 49 8B F1 49 8B F8 48 8B DA 4C 8B F1 48 8D 05} */
	MC static ParticleSystemEngine* $constructor(ParticleSystemEngine* self, ParticleEffectGroup& effectGroup, BlockSource& region, LightTexture& texture);
};

static_assert(offsetof(ParticleSystemEngine, mEffectEmitterCounts) == 4304, "Incorrect offset for ParticleSystemEngine::mEffectEmitterCounts");
static_assert(offsetof(ParticleSystemEngine, mEffectParticleCounts) == 4368, "Incorrect offset for ParticleSystemEngine::mEffectParticleCounts");