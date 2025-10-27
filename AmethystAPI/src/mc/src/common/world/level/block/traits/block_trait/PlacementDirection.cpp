#include "mc/src/common/world/level/block/traits/block_trait/PlacementDirection.hpp"

namespace BlockTrait {
	PlacementDirection::PlacementDirection(const EnabledStates& states, float rotationOffset) : 
		mStates(states), 
		mRotationOffset(rotationOffset) 
	{
	}
}