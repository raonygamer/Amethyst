#include "AbstractPEImporterHeader.hpp"

namespace Amethyst::Importing::PE {
	std::string AbstractPEImporterHeader::GetFormatType() const {
		return "pe32+";
	}

	void AbstractPEImporterHeader::ReadFrom(SimpleBinaryReader& reader) {
		AbstractHeader::ReadFrom(reader);
		OldIDT = reader.Read<uint32_t>();
		OldIDTSize = reader.Read<uint32_t>();
		ImportCount = reader.Read<uint32_t>();
	}
}