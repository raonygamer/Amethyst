#pragma once
#include <amethyst/runtime/events/EventBus.hpp>

class LevelRenderer;
class ScreenContext;
struct FrameRenderObject;
class ScreenView;
class MinecraftUIRenderContext;

class BeforeRenderUIEvent : public BaseEvent {
public:
    ScreenView& screen;
    MinecraftUIRenderContext& ctx;

    BeforeRenderUIEvent(ScreenView& screen, MinecraftUIRenderContext& ctx) 
        : screen(screen), ctx(ctx) {}
};

class AfterRenderUIEvent : public BaseEvent {
public:
    ScreenView& screen;
    MinecraftUIRenderContext& ctx;

    AfterRenderUIEvent(ScreenView& screen, MinecraftUIRenderContext& ctx)
        : screen(screen), ctx(ctx) {}
};

class BeforeRenderLevelEvent : public BaseEvent {
public:
    LevelRenderer& mLevelRenderer;
    ScreenContext& mScreenContext;
    FrameRenderObject& mFrameRenderObject;

    BeforeRenderLevelEvent(LevelRenderer& levelRenderer, ScreenContext& screenContext, FrameRenderObject& frameRenderObj)
        : mLevelRenderer(levelRenderer), mScreenContext(screenContext), mFrameRenderObject(frameRenderObj) {}
};


class AfterRenderLevelEvent : public BaseEvent {
public:
    LevelRenderer& mLevelRenderer;
    ScreenContext& mScreenContext;
    FrameRenderObject& mFrameRenderObject;

    AfterRenderLevelEvent(LevelRenderer& levelRenderer, ScreenContext& screenContext, FrameRenderObject& frameRenderObj)
        : mLevelRenderer(levelRenderer), mScreenContext(screenContext), mFrameRenderObject(frameRenderObj) {}
};
