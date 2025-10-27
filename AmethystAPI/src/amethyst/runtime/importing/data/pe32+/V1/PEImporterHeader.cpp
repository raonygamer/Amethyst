#include "amethyst/runtime/importing/data/pe32+/V1/PEImporterHeader.hpp"
#include "amethyst/runtime/importing/data/pe32+/PECanonicalHeader.hpp"

namespace Amethyst::Importing::PE::V1 {
	uint32_t PEImporterHeader::GetFormatVersion() const {
		return 1;
	}

	std::unique_ptr<CanonicalHeader> PEImporterHeader::Canonize() const {
		auto canon = std::make_unique<PECanonicalHeader>();
		canon->OldIDT = OldIDT;
		canon->OldIDTSize = OldIDTSize;
		canon->ImportCount = ImportCount;
		canon->Symbols.reserve(Symbols.size());
		for (const auto& sym : Symbols) {
			canon->Symbols.push_back(sym->Canonize());
		}
		return canon;
	}

	std::string PEImporterHeader::ToString() const {
		return std::format("{} -> PEImporterHeader[IDT: {:x}, IDT Size: {:x}, Import Count: {}]", AbstractHeader::ToString(), OldIDT, OldIDTSize, ImportCount);
	}
}