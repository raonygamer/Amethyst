#pragma once
#include "amethyst/runtime/importing/data/pe32+/AbstractPEImporterHeader.hpp"

namespace Amethyst::Importing::PE::V1 {
	class PEImporterHeader : 
		public AbstractPEImporterHeader 
	{
	public:
		virtual uint32_t GetFormatVersion() const override;
		virtual std::unique_ptr<CanonicalHeader> Canonize() const override;
		virtual std::string ToString() const override;
	};
}