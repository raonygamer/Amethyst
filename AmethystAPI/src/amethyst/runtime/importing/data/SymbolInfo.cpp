#include "amethyst/runtime/importing/data/SymbolInfo.hpp"

namespace Amethyst::Importing {
	SymbolInfo::SymbolInfo(uint32_t version, const std::string& format, const std::string& kind, const std::string& name) :
		Type(version, format, kind),
		Name(name)
	{
	}

	bool SymbolInfo::Equals(const SymbolInfo& other) const {
		return Type == other.Type && Name == other.Name;
	}

	bool SymbolInfo::operator==(const SymbolInfo& other) const {
		return Equals(other);
	}

	bool SymbolInfo::operator!=(const SymbolInfo& other) const {
		return !Equals(other);
	}

	std::string SymbolInfo::ToString() const {
		return std::format("SymbolInfo[{}, {}]", Type.ToString(), Name);
	}
}