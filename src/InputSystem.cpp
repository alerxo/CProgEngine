#include "InputSystem.h"

void InputSystem::HandleKeyDown(SDL_KeyboardEvent key)
{
    keyDown.Invoke(key.keysym.sym);
}

void InputSystem::HandleKeyUp(SDL_KeyboardEvent key)
{
    keyUp.Invoke(key.keysym.sym);
}

void InputSystem::HandleMouseDown(SDL_MouseButtonEvent button)
{
    mouseDown.Invoke(button.button);
}

void InputSystem::HandleMouseUp(SDL_MouseButtonEvent button)
{
    mouseUp.Invoke(button.button);
}

Vector2 InputSystem::GetMousePosition()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    
    return Vector2(x, y);
}

InputSystem inputSystem;