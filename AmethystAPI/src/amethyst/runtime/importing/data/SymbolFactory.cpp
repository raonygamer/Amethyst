#include "amethyst/runtime/importing/data/SymbolFactory.hpp"
#include "amethyst/runtime/importing/data/SymbolType.hpp"
#include "amethyst/runtime/importing/data/AbstractSymbol.hpp"

#include "amethyst/runtime/importing/data/pe32+/V1/PEFunctionSymbol.hpp"
#include "amethyst/runtime/importing/data/pe32+/V1/PEDataSymbol.hpp"
#include "amethyst/runtime/importing/data/pe32+/V2/PEDataSymbol.hpp"

namespace Amethyst::Importing {
	std::unordered_map<SymbolType, SymbolFactory::Constructor> SymbolFactory::Constructors;
	void SymbolFactory::Initialize() {
		Register({ 1, "pe32+", "function" }, []() { return std::make_unique<PE::V1::PEFunctionSymbol>(); });
		Register({ 1, "pe32+", "data" }, []() { return std::make_unique<PE::V1::PEDataSymbol>(); });
		Register({ 2, "pe32+", "data" }, []() { return std::make_unique<PE::V2::PEDataSymbol>(); });
	}

	void SymbolFactory::Register(const SymbolType& type, const Constructor& constructor) {
		Constructors[type] = constructor;
	}

	std::unique_ptr<AbstractSymbol> SymbolFactory::Create(const SymbolType& type) {
		if (Constructors.empty()) {
			Initialize();
		}

		auto it = Constructors.find(type);
		if (it != Constructors.end()) {
			return it->second();
		}
		AssertFail("No constructor registered for {}", type.ToString());
	}
}