#pragma once
#include <unordered_map>
#include <functional>

namespace Amethyst::Importing {
	class SymbolType;
	class AbstractSymbol;
	class SymbolFactory {
		using Constructor = std::function<std::unique_ptr<AbstractSymbol>()>;
		static std::unordered_map<SymbolType, Constructor> Constructors;
		static void Initialize();
	public:
		SymbolFactory() = delete;
		static void Register(const SymbolType& type, const Constructor& constructor);
		static std::unique_ptr<AbstractSymbol> Create(const SymbolType& type);
	};
}