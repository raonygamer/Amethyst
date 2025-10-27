#include "amethyst/runtime/importing/data/pe32+/V1/PEDataSymbol.hpp"
#include "amethyst/runtime/importing/data/pe32+/PECanonicalDataSymbol.hpp"

namespace Amethyst::Importing::PE::V1 {
	std::string PEDataSymbol::GetKind() const {
		return "data";
	}

	bool PEDataSymbol::IsShadowSymbol() const {
		return IsVirtualTable;
	}

	uint32_t PEDataSymbol::GetFormatVersion() const {
		return 1;
	}

	std::unique_ptr<CanonicalSymbol> PEDataSymbol::Canonize() const {
		auto canon = std::make_unique<PECanonicalDataSymbol>();
		canon->TargetOffset = TargetOffset;
		canon->HasStorage = HasStorage;
		canon->StorageOffset = StorageOffset;
		canon->IsVirtualTableAddress = IsVirtualTableAddress;
		canon->Name = Name;
		canon->IsShadow = IsShadowSymbol();
		canon->IsVirtualTable = IsVirtualTable;
		canon->Address = Address;
		return canon;
	}

	void PEDataSymbol::ReadFrom(SimpleBinaryReader& reader) {
		AbstractPEImportedSymbol::ReadFrom(reader);
		IsVirtualTableAddress = reader.Read<uint8_t>() != 0;
		IsVirtualTable = reader.Read<uint8_t>() != 0;
		Address = reader.Read<uint64_t>();
	}

	std::string PEDataSymbol::ToString() const {
		std::stringstream fields;
		if (IsVirtualTable) {
			fields << "VirtualTable, ";
		}
		if (IsVirtualTableAddress) {
			fields << "VirtualTableAddress, ";
		}
		fields << std::format("Address[{:x}]", Address);
		return std::format("{} -> PEDataSymbol[{}]", AbstractPEImportedSymbol::ToString(), fields.str());
	}
}