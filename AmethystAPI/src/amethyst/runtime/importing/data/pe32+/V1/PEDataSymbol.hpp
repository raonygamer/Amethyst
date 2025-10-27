#pragma once
#include "amethyst/runtime/importing/data/pe32+/AbstractPEImportedSymbol.hpp"

namespace Amethyst::Importing::PE::V1 {
	class PEDataSymbol :
		public AbstractPEImportedSymbol
	{
	public:
		bool IsVirtualTableAddress = false;
		bool IsVirtualTable = false;
		uint64_t Address = 0x0;

		virtual std::string GetKind() const override;
		virtual bool IsShadowSymbol() const override;
		virtual uint32_t GetFormatVersion() const override;
		virtual std::unique_ptr<CanonicalSymbol> Canonize() const override;
		virtual void ReadFrom(SimpleBinaryReader& reader) override;
		virtual std::string ToString() const override;
	};
}