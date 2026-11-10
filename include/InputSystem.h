#include "Event.h"
#include "EngineSystem.h"
#include "Vector2.h"

class InputSystem
{
public:
    void HandleKeyDown(SDL_KeyboardEvent);
    void HandleKeyUp(SDL_KeyboardEvent);
    void HandleMouseDown(SDL_MouseButtonEvent);
    void HandleMouseUp(SDL_MouseButtonEvent);
    Vector2 GetMousePosition();

    Event<SDL_Keycode> keyUp;
    Event<SDL_Keycode> keyDown;
    Event<SDL_Keycode> mouseDown;
    Event<SDL_Keycode> mouseUp;
};

extern InputSystem inputSystem;