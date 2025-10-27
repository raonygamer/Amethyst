#pragma once
#include <string>

namespace Amethyst::Importing {
	class HeaderType {
	public:
		uint32_t Version;
		std::string Type;

		HeaderType() = delete;
		HeaderType(uint32_t version, const std::string& type);

		bool Equals(const HeaderType& other) const;
		bool operator==(const HeaderType& other) const;
		bool operator!=(const HeaderType& other) const;
		std::string ToString() const;
	};
}

namespace std {
	template<>
	struct hash<Amethyst::Importing::HeaderType> {
		size_t operator()(const Amethyst::Importing::HeaderType& headerType) const {
			size_t h1 = std::hash<uint32_t>()(headerType.Version);
			size_t h2 = std::hash<std::string>()(headerType.Type);
			return h1 ^ (h2 << 1);
		}
	};
}