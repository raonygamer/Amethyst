#pragma once
#include "amethyst/runtime/importing/data/AbstractSymbol.hpp"

namespace Amethyst::Importing::PE {
	class AbstractPEImportedSymbol : 
		public AbstractSymbol 
	{
	public:
		uint32_t TargetOffset = 0x0;
		bool HasStorage = false;
		uint32_t StorageOffset = 0x0;

		virtual std::string GetFormatType() const override;
		virtual void ReadFrom(SimpleBinaryReader& reader) override;
		virtual std::string ToString() const override;
	};
}