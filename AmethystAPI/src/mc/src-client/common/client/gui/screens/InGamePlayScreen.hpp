/// @symbols
#pragma once
#include <amethyst/Imports.hpp>

class ScreenContext;
class ClientInstance;
struct FrameRenderObject;
class InGamePlayScreen {
public:
	/* this + 000 */ std::byte padding0[376];
	/* this + 376 */ ClientInstance* mClient;

	/** @sig {48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 89 44 24 ? 4C 8B FA 48 89 4C 24} */
	MC void _renderLevel(ScreenContext& screenContext, const FrameRenderObject& renderObj);
};