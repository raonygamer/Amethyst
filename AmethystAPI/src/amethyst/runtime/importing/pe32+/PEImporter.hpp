#pragma once
#include "amethyst/runtime/importing/Importer.hpp"

namespace Amethyst::Importing::PE {
	class PEImporter final : 
		public Importer 
	{
		IMAGE_SECTION_HEADER* mRTIHSection = nullptr;
		IMAGE_SECTION_HEADER* mRTISSection = nullptr;
		uint64_t* mState = nullptr;
	public:
		PEImporter(void* module);
		virtual ~PEImporter();
		virtual void ResolveAll() override;
		virtual bool IsResolved() const override;


		static std::unique_ptr<CanonicalHeader> LoadHeader(void* module, IMAGE_SECTION_HEADER* rtih, IMAGE_SECTION_HEADER* rtis);
		static std::unique_ptr<PEImporter> Create(void* module);
		static std::tuple<IMAGE_SECTION_HEADER*, IMAGE_SECTION_HEADER*> GetSections(void* module);
		static uint64_t ReadState(void* module);
		static void WriteState(void* module, uint64_t state);
	};
}