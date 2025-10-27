#include "amethyst/runtime/importing/data/CanonicalHeader.hpp"

namespace Amethyst::Importing {
	std::string CanonicalHeader::ToString() const {
		return std::format("CanonicalHeader[{}, {} symbols]", GetFormatType(), Symbols.size());
	}

	template<>
	PE::PECanonicalHeader* CanonicalHeader::Transform<PE::PECanonicalHeader>() {
		if (GetFormatType() != "pe32+") {
			Assert(false, "Cannot transform CanonicalHeader of type {} to PECanonicalHeader", GetFormatType());
			return nullptr;
		}
		return reinterpret_cast<PE::PECanonicalHeader*>(this);
	}
}