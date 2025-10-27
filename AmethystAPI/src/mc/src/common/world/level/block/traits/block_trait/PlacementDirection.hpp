/// @symbols
#pragma once
#include <amethyst/Imports.hpp>
#include "mc/src/common/world/level/block/traits/block_trait/ITrait.hpp"

namespace BlockTrait {
	/** @vptr {48 8D 05 ? ? ? ? 89 77 ? 48 89 07} */
	class PlacementDirection : 
		public ITrait 
	{
	public:
		struct EnabledStates {
			bool mCardinalDirection;
			bool mFacingDirection;
		};

		/* this + 08 */ EnabledStates mStates = {true, true};
		/* this + 10 - +2 Bytes Hidden Alignment */
		/* this + 12 */ const float mRotationOffset = 180.0f;

		PlacementDirection() = default;
		PlacementDirection(const EnabledStates& states, float rotationOffset);
		/** @vidx {0} */ MC virtual ~PlacementDirection() override;
		/** @vidx {1} */ MC virtual void applyToBlockLegacy(BlockLegacy& blockLegacy) const override;
		/** @vidx {2} */ MC virtual std::unique_ptr<CompoundTag> buildNetworkTag() const override;
		/** @vidx {3} */ MC virtual void initializeFromNetwork(const CompoundTag& tag) override;
	};

	static_assert(sizeof(PlacementDirection) == 0x10, "Size of BlockTrait::PlacementDirection doesn't match what's expected!");
}