#pragma once
#include "amethyst/runtime/importing/data/CanonicalHeader.hpp"

namespace Amethyst::Importing::PE {
	class PECanonicalHeader : 
		public CanonicalHeader 
	{
	public:
		uint32_t OldIDT = 0;
		uint32_t OldIDTSize = 0;
		uint32_t ImportCount = 0;

		virtual std::string GetFormatType() const override;
		virtual std::string ToString() const override;
	};
}