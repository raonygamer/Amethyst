#pragma once
#include <string>

namespace Amethyst::Importing {
	class SymbolType {
	public:
		uint32_t Version;
		std::string Format;
		std::string Kind;

		SymbolType() = delete;
		SymbolType(uint32_t version, const std::string& format, const std::string& kind);

		bool Equals(const SymbolType& other) const;
		bool operator==(const SymbolType& other) const;
		bool operator!=(const SymbolType& other) const;
		std::string ToString() const;
	};
}

namespace std {
	template<>
	struct hash<Amethyst::Importing::SymbolType> {
		size_t operator()(const Amethyst::Importing::SymbolType& symbolType) const {
			size_t h1 = std::hash<uint32_t>()(symbolType.Version);
			size_t h2 = std::hash<std::string>()(symbolType.Format);
			size_t h3 = std::hash<std::string>()(symbolType.Kind);
			return h1 ^ (h2 << 1) ^ (h3 << 2);
		}
	};
}