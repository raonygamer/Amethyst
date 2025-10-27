#pragma once
#include <string>
#include "amethyst/runtime/importing/data/SymbolType.hpp"

namespace Amethyst::Importing {
	class SymbolInfo {
	public:
		SymbolType Type;
		std::string Name;

		SymbolInfo() = delete;
		SymbolInfo(uint32_t version, const std::string& format, const std::string& kind, const std::string& name);

		bool Equals(const SymbolInfo& other) const;
		bool operator==(const SymbolInfo& other) const;
		bool operator!=(const SymbolInfo& other) const;
		std::string ToString() const;
	};
}