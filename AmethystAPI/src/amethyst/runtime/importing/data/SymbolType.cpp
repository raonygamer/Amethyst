#include "amethyst/runtime/importing/data/SymbolType.hpp"

namespace Amethyst::Importing {
	SymbolType::SymbolType(uint32_t version, const std::string& format, const std::string& kind) :
		Version(version), 
		Format(format), 
		Kind(kind)
	{
	}

	bool SymbolType::Equals(const SymbolType& other) const {
		return Version == other.Version && Format == other.Format && Kind == other.Kind;
	}

	bool SymbolType::operator==(const SymbolType& other) const {
		return Equals(other);
	}

	bool SymbolType::operator!=(const SymbolType& other) const {
		return !Equals(other);
	}

	std::string SymbolType::ToString() const {
		return std::format("SymbolType[v{}, {}, {}]", Version, Format, Kind);
	}
}