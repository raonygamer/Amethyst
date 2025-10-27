/// @symbols
#pragma once
#include <amethyst/Imports.hpp>
#include <cstdint>
#include <mc/src/common/world/phys/Vec3.hpp>

class BaseActorRenderContext;
class ScreenContext;
class BlockSource;
class BlockPos;
class Block;
class LevelRendererPlayer {
public:
    std::byte padding[0x5E4];
    Vec3 cameraPos;

    // virtual - 48 8B C4 48 89 58 ? 48 89 70 ? 57 48 81 EC ? ? ? ? 0F 29 70 ? 0F 29 78 ? 44 0F 29 40 ? 44 0F 29 48 ? 48 8B 05
    float getFov(float, bool);
	/** @sig {40 55 56 41 55 41 56 41 57 48 83 EC ? 49 8B 00} */
	MC void renderHitSelect(BaseActorRenderContext& renderContext, BlockSource& region, const BlockPos& pos, bool fancyGraphics);
	/** @sig {E8 ? ? ? ? 48 83 C4 ? 41 5F 41 5E 41 5D 5E 5D C3 E8} */
	MC void _renderHighlightSelection(BaseActorRenderContext& renderContext, BlockSource& region, const Block& block, const BlockPos& pos, bool renderSecondPart, bool fancyGraphics);
	/** @sig {E8 ? ? ? ? 48 83 C4 ? 41 5F 41 5E 41 5D 5E 5D C3 0F B6 84 24} */
	MC void _renderOutlineSelection(ScreenContext& screenContext, const Block& block, BlockSource& region, const BlockPos& pos);
};