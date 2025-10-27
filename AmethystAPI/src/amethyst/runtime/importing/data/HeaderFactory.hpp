#pragma once
#include <unordered_map>
#include <functional>

namespace Amethyst::Importing {
	class HeaderType;
	class AbstractHeader;
	class HeaderFactory {
		using Constructor = std::function<std::unique_ptr<AbstractHeader>()>;
		static std::unordered_map<HeaderType, Constructor> Constructors;
		static void Initialize();
	public:
		HeaderFactory() = delete;
		static void Register(const HeaderType& type, const Constructor& constructor);
		static std::unique_ptr<AbstractHeader> Create(const HeaderType& type);
	};
}