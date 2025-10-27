#include "amethyst/runtime/importing/data/HeaderType.hpp"

namespace Amethyst::Importing {
	HeaderType::HeaderType(uint32_t version, const std::string& type) : 
		Version(version), 
		Type(type) 
	{
	}

	bool HeaderType::Equals(const HeaderType& other) const {
		return Version == other.Version && Type == other.Type;
	}

	bool HeaderType::operator==(const HeaderType& other) const {
		return Equals(other);
	}

	bool HeaderType::operator!=(const HeaderType& other) const {
		return !Equals(other);
	}

	std::string HeaderType::ToString() const {
		return std::format("HeaderType[v{}, {}]", Version, Type);
	}
}