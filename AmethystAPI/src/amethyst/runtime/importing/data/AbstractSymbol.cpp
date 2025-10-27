#include "amethyst/runtime/importing/data/AbstractSymbol.hpp"
#include "AbstractHeader.hpp"

namespace Amethyst::Importing {
	void AbstractSymbol::ReadFrom(SimpleBinaryReader& reader) {
		auto ver = reader.Read<uint32_t>();
		Assert(ver == GetFormatVersion(), "Unsupported AbstractSymbol version {}", ver);
		auto fmt = reader.ReadPrefixedString();
		Assert(fmt == GetFormatType(), "Mismatched AbstractSymbol format type {}, expected {}", fmt, GetFormatType());
		auto kind = reader.ReadPrefixedString();
		Assert(kind == GetKind(), "Mismatched AbstractSymbol kind {}, expected {}", kind, GetKind());
		Name = reader.ReadPrefixedString();
	}

	std::string AbstractSymbol::ToString() const {
		return std::format("Symbol[v{}, {}, {}, {}]", GetFormatVersion(), GetFormatType(), Name, GetKind());
	}

	SymbolInfo AbstractSymbol::PeekInfo(SimpleBinaryReader& reader) {
		SeekGuard guard(reader.GetStream(), reader.GetStream().tellg());
		auto ver = reader.Read<uint32_t>();
		auto fmt = reader.ReadPrefixedString();
		auto kind = reader.ReadPrefixedString();
		auto name = reader.ReadPrefixedString();
		return { ver, fmt, kind, name };
	}
}