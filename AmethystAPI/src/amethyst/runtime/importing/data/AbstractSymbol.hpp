#pragma once
#include <string>
#include "amethyst/runtime/utility/SimpleBinaryReader.hpp"
#include "amethyst/runtime/importing/data/SymbolInfo.hpp"
#include "amethyst/runtime/importing/data/CanonicalSymbol.hpp"

namespace Amethyst::Importing {
	class AbstractSymbol {
	public:
		std::string Name = "";

		virtual ~AbstractSymbol() = default;
		virtual std::string GetFormatType() const = 0;
		virtual uint32_t GetFormatVersion() const = 0;
		virtual std::string GetKind() const = 0;
		virtual bool IsShadowSymbol() const = 0;
		virtual std::unique_ptr<CanonicalSymbol> Canonize() const = 0;
		virtual void ReadFrom(SimpleBinaryReader& reader);
		virtual std::string ToString() const;

		static SymbolInfo PeekInfo(SimpleBinaryReader& reader);
	};
}