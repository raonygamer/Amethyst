#include "amethyst/runtime/importing/data/AbstractHeader.hpp"
#include "amethyst/runtime/importing/data/SymbolFactory.hpp"

namespace Amethyst::Importing {
	void AbstractHeader::ReadFrom(SimpleBinaryReader& reader) {
		auto magic = reader.ReadPrefixedString();
		Assert(magic == MagicSignature, "Invalid magic signature '{}', expected '{}'.", magic, MagicSignature);
		auto ver = reader.Read<uint32_t>();
		Assert(ver == GetFormatVersion(), "Incompatible version {}, expected {}.", ver, GetFormatVersion());
		auto fmt = reader.ReadPrefixedString();
		Assert(fmt == GetFormatType(), "Incompatible format type '{}', expected '{}'.", fmt, GetFormatType());
		auto symbolCount = reader.Read<uint32_t>();
		Symbols.clear();
		Symbols.reserve(symbolCount);
		for (uint32_t i = 0; i < symbolCount; i++) {
			auto symbol = SymbolFactory::Create(AbstractSymbol::PeekInfo(reader).Type);
			symbol->ReadFrom(reader);
			Symbols.push_back(std::move(symbol));
		}
	}

	std::string AbstractHeader::ToString() const {
		return std::format("Header[v{}, {}, {} symbols]", GetFormatVersion(), GetFormatType(), Symbols.size());
	}

	HeaderType AbstractHeader::PeekInfo(SimpleBinaryReader& reader) {
		SeekGuard guard(reader.GetStream(), reader.GetStream().tellg());
		auto magic = reader.ReadPrefixedString();
		Assert(magic == MagicSignature, "Invalid magic signature '{}', expected '{}'.", magic, MagicSignature);
		auto ver = reader.Read<uint32_t>();
		auto fmt = reader.ReadPrefixedString();
		return { ver, fmt };
	}
}