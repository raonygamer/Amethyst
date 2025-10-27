#pragma once
#include "amethyst/runtime/importing/data/AbstractHeader.hpp"

namespace Amethyst::Importing::PE {
	class AbstractPEImporterHeader : 
		public AbstractHeader 
	{
	public:
		uint32_t OldIDT = 0;
		uint32_t OldIDTSize = 0;
		uint32_t ImportCount = 0;

		virtual std::string GetFormatType() const override;
		virtual void ReadFrom(SimpleBinaryReader& reader) override;
	};
}