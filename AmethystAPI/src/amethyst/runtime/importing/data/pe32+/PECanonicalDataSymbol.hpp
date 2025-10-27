#pragma once
#include "amethyst/runtime/importing/data/CanonicalSymbol.hpp"

namespace Amethyst::Importing::PE {
	class PECanonicalDataSymbol :
		public CanonicalSymbol
	{
	public:
		uint32_t TargetOffset = 0x0;
		bool HasStorage = false;
		uint32_t StorageOffset = 0x0;
		bool IsVirtualTableAddress = false;
		bool IsVirtualTable = false;
		uint64_t Address = 0x0;
		bool IsSignature = false;
		std::string Signature = "";

		virtual std::string GetFormatType() const override;
		virtual std::string GetKind() const override;
		virtual std::string ToString() const override;
		virtual uintptr_t Compute(const ResolutionContext& ctx) override;
		virtual bool Resolve(const ResolutionContext& ctx) override;
	};
}