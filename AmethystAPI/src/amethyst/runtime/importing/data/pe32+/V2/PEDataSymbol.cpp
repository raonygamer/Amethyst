#include "amethyst/runtime/importing/data/pe32+/V2/PEDataSymbol.hpp"
#include "amethyst/runtime/importing/data/pe32+/PECanonicalDataSymbol.hpp"

namespace Amethyst::Importing::PE::V2 {
	uint32_t PEDataSymbol::GetFormatVersion() const {
		return 2;
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
		canon->IsSignature = IsSignature;
		canon->Signature = Signature;
		return canon;
	}

	void PEDataSymbol::ReadFrom(SimpleBinaryReader& reader) {
		V1::PEDataSymbol::ReadFrom(reader);
		IsSignature = reader.Read<uint8_t>() != 0;
		if (IsSignature) {
			Signature = reader.ReadPrefixedString();
		}
	}

	std::string PEDataSymbol::ToString() const {
		std::stringstream fields;
		if (IsSignature) {
			fields << "Signature [{" << Signature << "}], ";
		}
		return std::format("{} -> PEDataSymbol[{}]", V1::PEDataSymbol::ToString(), fields.str());
	}
}