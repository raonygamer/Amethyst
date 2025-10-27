/// @symbolgeneration
#pragma once
#include <memory>
#include "amethyst/Imports.hpp"
#include "mc/src-client/common/client/gui/screens/ScreenController.hpp"
#include "mc/src-deps/core/utility/NonOwnerPointer.hpp"

namespace Social {
enum class UserPlatformConnectionResult;
}

enum class PickCustomSkinResult;

enum class ScreenExitBehavior : int {
    LeaveScreen = 0x0000,
    ExitGame = 0x0001,
    GoToStartScreen = 0x0002,
    DoNothing = 0x0003
};

enum class HoloUIInputMode : uint32_t {
    Unknown = 0x0000,
    Controller = 0x0001,
    Gaze = 0x0002,
    Mouse = 0x0003
};

class MinecraftScreenModel;

/// @vptr {0x4D03830}
class MinecraftScreenController :
	public ScreenController,
	public Bedrock::EnableNonOwnerReferences,
    public std ::enable_shared_from_this<MinecraftScreenController> 
{
public:
    MC static uintptr_t $vtable_for_this;

    struct LeaveScreenInfo {
        std::byte padding0[0x28];
    };

    std::shared_ptr<MinecraftScreenModel> mMinecraftScreenModel;
    ScreenExitBehavior mExitBehavior;
    InputMode mInputMode;
    HoloUIInputMode mHoloUIInputMode;
    InputMode mPreviousInputMode;
    HoloUIInputMode mPreviousHoloUIInputMode;
    bool mPlayerDied;
    std::function<void(enum ModalScreenButtonId)> mModalDialogResultCallback;
    std::string mTTSTitle;
    std::string mTTSDialogMessage;
    MinecraftScreenController::LeaveScreenInfo mLeaveScreen;
    bool mRayTracingActive;
    std::unordered_map<std::string, std::vector<bool>> mDropDownActive;
    std::unordered_map<std::string, int> mStepSliderValues;
    bool mIsShowErrorScreenInProgress;

    /// @signature {48 89 5C 24 ? 48 89 54 24 ? 48 89 4C 24 ? 55 56 57 41 56 41 57 48 83 EC ? 41 0F B6 E9 41 8B F8}
    MC MinecraftScreenController(std::shared_ptr<MinecraftScreenModel> model, ScreenExitBehavior exitBehavior, bool flag);

    /// @vidx {inherit}
    MC virtual ~MinecraftScreenController() override;

    /// @vidx {inherit}
    MC virtual ui::DirtyFlag tick() override;

    /// @vidx {inherit}
    MC virtual void onOpen() override;

    /// @vidx {inherit}
    MC virtual void onInit() override;

    /// @vidx {inherit}
    MC virtual void onDelete() override;

    /// @vidx {inherit}
    MC virtual ui::ViewRequest tryExit() override;

    /// @vidx {inherit}
    MC virtual void leaveScreen(const std::string&) override;

    /// @vidx {inherit}
    MC virtual bool bind(const std::string&, uint32_t, const std::string&, UIPropertyBag&) override;

    /// @vidx {inherit}
    MC virtual bool bind(const std::string&, uint32_t, int, const std::string&, uint32_t, const std::string&, UIPropertyBag&) override;
    
    /// @vidx {inherit}
    MC virtual void onDictationEvent(const std::string&) override;

    /// @vidx {inherit}
    MC virtual void setSuspendInput(bool) override;

    /// @vidx {inherit}
    MC virtual uint32_t getSceneId() override;

    /// @vidx {inherit}
    MC virtual bool _doesScreenHaveExitBehavior() override;

    /// @vidx {39}
    MC virtual bool _isStillValid();

    /// @vidx {40}
    MC virtual bool _getGamepadHelperVisible();

    /// @vidx {41}
    MC virtual bool _getMixedHelperVisible();

    /// @vidx {42}
    MC virtual bool _getKeyboardHelperVisible();

    /// @vidx {43}
    MC virtual bool _getGestureControlEnabled();

    /// @vidx {44}
    MC virtual std::string _getButtonStartDescription();

    /// @vidx {45}
    MC virtual std::string _getButtonADescription();

    /// @vidx {46}
    MC virtual std::string _getButtonBDescription();

    /// @vidx {47}
    MC virtual std::string _getButtonXDescription();

    /// @vidx {48}
    MC virtual std::string _getButtonYDescription();

    /// @vidx {49}
    MC virtual std::string _getButtonKeyboardDescription();

    /// @vidx {50}
    MC virtual void showPickCustomSkinDialog(std::function<void(PickCustomSkinResult)>);

    /// @vidx {51}
    MC virtual std::string _getScreenName();

    /// @vidx {52}
    MC virtual ui::ViewRequest promptConnect(bool, std::function<void(Social::UserPlatformConnectionResult)>);
};

static_assert(sizeof(MinecraftScreenController) == 0xC20);