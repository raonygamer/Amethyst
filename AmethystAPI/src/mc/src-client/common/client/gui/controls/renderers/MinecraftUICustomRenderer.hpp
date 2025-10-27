
#pragma once
#include "mc/src-client/common/client/gui/controls/renderers/UICustomRenderer.hpp"

class MinecraftUIRenderContext;

class MinecraftUIRenderContext;

class MinecraftUICustomRenderer : public UICustomRenderer {
public:
    MinecraftUICustomRenderer() : UICustomRenderer() {};

    virtual void frameUpdate(UIFrameUpdateContext& frameCtx, UIControl& control) override
    {
        this->frameUpdate((MinecratUIFrameUpdate&)frameCtx, control);
    };

    virtual void render(UIRenderContext& ctx, IClientInstance& client, UIControl& owner, int32_t pass, RectangleArea& renderAABB) override
    {
        this->render((MinecraftUIRenderContext&)ctx, client, owner, pass, renderAABB);
    }

    virtual void preRenderSetup(UIRenderContext& renderCtx) override 
    {
        this->preRenderSetup((MinecraftUIRenderContext&)renderCtx);
    }

    virtual void frameUpdate(MinecratUIFrameUpdate&, UIControl&) {};
    virtual void render(MinecraftUIRenderContext& ctx, IClientInstance& client, UIControl& owner, int32_t pass, RectangleArea& renderAABB) = 0;
	virtual void preRenderSetup(MinecraftUIRenderContext&) {};
};