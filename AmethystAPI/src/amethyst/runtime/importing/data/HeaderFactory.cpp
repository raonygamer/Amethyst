#include "amethyst/runtime/importing/data/HeaderFactory.hpp"
#include "amethyst/runtime/importing/data/HeaderType.hpp"
#include "amethyst/runtime/importing/data/AbstractHeader.hpp"

#include "amethyst/runtime/importing/data/pe32+/V1/PEImporterHeader.hpp"

namespace Amethyst::Importing {
	std::unordered_map<HeaderType, HeaderFactory::Constructor> HeaderFactory::Constructors = {};
	void HeaderFactory::Initialize() {
		Register({ 1, "pe32+" }, []() { return std::make_unique<PE::V1::PEImporterHeader>(); });
	}

	void HeaderFactory::Register(const HeaderType& type, const Constructor& constructor) {
		Constructors[type] = constructor;
	}

	std::unique_ptr<AbstractHeader> HeaderFactory::Create(const HeaderType& type) {
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