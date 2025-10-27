#pragma once
#include <vector>
#include <string>
#include "amethyst/runtime/importing/data/AbstractSymbol.hpp"
#include "amethyst/runtime/importing/data/HeaderType.hpp"
#include "amethyst/runtime/importing/data/CanonicalHeader.hpp"

namespace Amethyst::Importing {
	class AbstractHeader {
	public:
		inline static const std::string MagicSignature = "AME_RTI";
		
		std::vector<std::unique_ptr<AbstractSymbol>> Symbols;

		virtual ~AbstractHeader() = default;
		virtual std::string GetFormatType() const = 0;
		virtual uint32_t GetFormatVersion() const = 0;
		virtual std::unique_ptr<CanonicalHeader> Canonize() const = 0;
		virtual void ReadFrom(SimpleBinaryReader& reader);
		virtual std::string ToString() const;

		static HeaderType PeekInfo(SimpleBinaryReader& reader);
	};
}