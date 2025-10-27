#pragma once
#include "amethyst/runtime/importing/data/CanonicalHeader.hpp"

namespace Amethyst::Importing {
	class Importer {
	protected:
		void* mModule = nullptr;
		std::unique_ptr<CanonicalHeader> mHeader = {};
	public:
		Importer(void* module);
		virtual ~Importer();
		virtual void ResolveAll() = 0;
		virtual bool IsResolved() const = 0;
	};
}