#include "amethyst/runtime/importing/Importer.hpp"

namespace Amethyst::Importing {
	Importer::Importer(void* module) : 
		mModule(module) 
	{
		Assert(mModule != nullptr, "Importer module handle cannot be null");
	}

	Importer::~Importer() = default;
}