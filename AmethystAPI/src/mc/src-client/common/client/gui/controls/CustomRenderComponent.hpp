#pragma once
#include <mc/src-client/common/client/gui/controls/RenderableComponent.hpp>
#include <mc/src-client/common/client/gui/controls/renderers/UICustomRenderer.hpp>
#include <mc/src-deps/core/utility/StringUtils.hpp>

class CustomRenderComponent : public RenderableComponent {
private:
    std::shared_ptr<UICustomRenderer> mRenderer;
    std::string someString;

public:
    CustomRenderComponent(UIControl& control) : RenderableComponent(control), mRenderer(nullptr), someString() {}

    std::unique_ptr<UIComponent> clone(UIControl& owner) override {
        auto newComp = std::make_unique<CustomRenderComponent>(owner);
        if (mRenderer)
            newComp->mRenderer = mRenderer->clone();
        return newComp;
    }

    void reset() override {}

    virtual void onVisibilityChanged(bool) override {};                                       
    virtual const std::string& getTextToSpeechComponentValue() const override { return Util::EmptyString; };

    virtual UIBatchType getBatchType() const;
    virtual int32_t getCustomId() const;
    virtual int32_t getNumRenderPasses() const;
    virtual UIMaterialType getUIMaterialType(int32_t) const;
    virtual ResourceLocation getResourceLocation(int32_t, int32_t) const;
    virtual bool getRequiresPreRenderSetup(int32_t) const;
    virtual void collectScreenEvents(std::queue<ScreenEvent>&);

    virtual uint64_t getItemRenderInfo() const {
        if (mRenderer) {
            return mRenderer->getItemRenderInfo();
        }

        return 0;
    };

    void setRenderer(std::shared_ptr<UICustomRenderer> renderer) { mRenderer = renderer; }
};