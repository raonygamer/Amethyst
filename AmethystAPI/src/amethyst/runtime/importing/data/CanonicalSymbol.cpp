#include "amethyst/runtime/importing/data/CanonicalSymbol.hpp"

namespace Amethyst::Importing {
	std::string CanonicalSymbol::ToString() const {
		return std::format("CanonicalSymbol[{}, {}, {}, {}]", Name, GetFormatType(), GetKind(), IsShadow);
	}

	template<>
	PE::PECanonicalDataSymbol* CanonicalSymbol::Transform<PE::PECanonicalDataSymbol>() {
		if (GetFormatType() != "pe32+" || GetKind() != "data") {
			Assert(false, "Cannot transform CanonicalSymbol of type {} and kind {} to PECanonicalDataSymbol", GetFormatType(), GetKind());
			return nullptr;
		}
		return reinterpret_cast<PE::PECanonicalDataSymbol*>(this);
	}

	template<>
	PE::PECanonicalFunctionSymbol* CanonicalSymbol::Transform<PE::PECanonicalFunctionSymbol>() {
		if (GetFormatType() != "pe32+" || GetKind() != "function") {
			Assert(false, "Cannot transform CanonicalSymbol of type {} and kind {} to PECanonicalFunctionSymbol", GetFormatType(), GetKind());
			return nullptr;
		}
		return reinterpret_cast<PE::PECanonicalFunctionSymbol*>(this);
	}
}