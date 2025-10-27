#pragma once
#include <cstdint>
#include <mc/src-deps/input/InputMode.hpp>
#include <mc/src-deps/input/InputHandler.hpp>

class UIPropertyBag;

enum class ScreenEventType : int32_t {
    Undefined = 0,
    ButtonEvent = 1,
    TextEditChange = 12,
    ToggleChangeEvent = 13,
    SliderChangeEvent = 16,

    //ButtonMoveEvent = 0x0002,
    //PointerMoveInEvent = 0x0003,
    //PointerMoveOutEvent = 0x0004,
    //HoverEvent = 0x0005,
    //PointerMoveEvent = 0x0006,
    //PointerHeldEvent = 0x0007,
    //FocusMoveEvent = 0x0008,
    //PreCollectionRefresh = 0x0009,
    //InputModeChangeEvent = 0x000a,
    //HoloInputModeChangeEvent = 0x000b,
    //ScreenViewRefresh = 0x000c,
    //ScrollDirectionEvent = 0x000d,
    //ScrollRequestEvent = 0x000e,
    //ToggleChangeEvent = 0x0010,
    //ControllerDirectionEvent = 0x0011,
    //RawInputEvent = 0x0012,
    //
    //AnimationEvent = 0x0014,
    //LockedStateEvent = 0x0015,
    //ClippedCollectionRange = 0x0016,
    //ClipStateChangeEvent = 0x0017,
    //TextEditSelectedStateChangeEvent = 0x0018,
    //CustomRendererEvent = 0x0019,
    //ScreenEventTypeCount = 0x001a,
};

struct ButtonScreenEventData {
public:
    int32_t id;
    int32_t fromButtonId;
    ButtonState previousState;
    ButtonState state;
    bool handleDeselection;
    bool handleSelection;
    UIPropertyBag* properties;
    float cursorPosition[2];
    bool isInteracted;
    InputMode inputMode;
};

struct ToggleChangeEventData {
public:
    int32_t id;
    int index;
    bool state;
    bool toggledByButtonClick;
    UIPropertyBag* properties;
    uint64_t itemStringHash;
};

struct SliderChangeEventData {
public:
    int32_t id;
    int index;
    float value;
    bool finalized;
    UIPropertyBag* properties;
};

enum class TextCharEventResult : int32_t {
	None = 0x0000,
	EnterPressed = 0x0001,
	BackspacePressed = 0x0002,
	Succcess = 0x0003,
	Failed = 0x0004,
};

struct TextEditScreenEventData {
	int id;
	int index;
	bool finished;
	UIPropertyBag* properties;
	TextCharEventResult result;
	bool hasSelectedTextBox;
};

union ScreenEventData {
    ButtonScreenEventData button;
    ToggleChangeEventData toggle;
    SliderChangeEventData slider;
    TextEditScreenEventData textEdit;

    //HoverScreenEventData hover;
    //PointerMoveScreenEventData pointerMove;
    //PointerHeldScreenEventData pointerHeld;
    //FocusMoveScreenEventData focusMove;
    //InputModeChangeScreenEventData inputMode;
    //HoloInputModeChangeScreenEventData holoInputMode;
    //ScrollRequestScreenEventData scrollRequest;
    //ScrollDirectionEventData scrollDirectionRequest;
    //ControllerDirectionEventData controllerDirectionEventData;
    //RawInputScreenEventData rawInput;
    //SliderChangeEventData slider;
    //AnimationEventData animEventData;
    //LockedStateEventData locked;
    //ClippedCollectionEventData clippedCollection;
    //ClipStateChangeEventData clipStateChangeEventData;
    //TextEditSelectedStateChangeEventData textEditSelectedStateChangeEventData;
    //CustomRendererEventData customRendererEventData;
};

enum class ScreenEventScope : char {
    Controller = 0x0000,
    View = 0x0001,
};

class ScreenEvent {
public:
    ScreenEventType type;
    ScreenEventData data;
    ScreenEventScope scope;
    bool localEvent;
};