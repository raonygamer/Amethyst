#include "amethyst/runtime/importing/data/pe32+/PECanonicalHeader.hpp"

namespace Amethyst::Importing::PE {
	std::string PECanonicalHeader::GetFormatType() const {
		return "pe32+";
	}

	std::string PECanonicalHeader::ToString() const {
		return std::format("{} -> PECanonicalHeader[IDT: {:x}, IDT Size: {:x}, Import Count: {}]", CanonicalHeader::ToString(), OldIDT, OldIDTSize, ImportCount);
	}
}