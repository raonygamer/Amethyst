#pragma once
#include <memory>

class BlockLegacy;
class CompoundTag;
namespace BlockTrait {
	class ITrait {
	public:
		virtual ~ITrait() = default;
		virtual void applyToBlockLegacy(BlockLegacy& blockLegacy) const = 0;
		virtual std::unique_ptr<CompoundTag> buildNetworkTag() const = 0;
		virtual void initializeFromNetwork(const CompoundTag& tag) = 0;
	};
}