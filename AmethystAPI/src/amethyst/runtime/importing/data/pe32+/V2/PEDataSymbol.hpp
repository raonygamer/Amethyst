#pragma once
#include "amethyst/runtime/importing/data/pe32+/V1/PEDataSymbol.hpp"

namespace Amethyst::Importing::PE::V2 {
	class PEDataSymbol :
		public V1::PEDataSymbol {
	public:
		bool IsSignature = false;
		std::string Signature = "";

		virtual uint32_t GetFormatVersion() const override;
		virtual std::unique_ptr<CanonicalSymbol> Canonize() const override;
		virtual void ReadFrom(SimpleBinaryReader& reader) override;
		virtual std::string ToString() const override;
	};
}