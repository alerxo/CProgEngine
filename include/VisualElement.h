#ifndef VISUALELEMENT_H
#define VISUALELEMENT_H

#include "Component.h"
#include "EngineSystem.h"
#include "Vector2.h"
#include "Constants.h"
#include "GameObject.h"

class VisualElement : public Component
{
public:
    ~VisualElement();

    void OnGameTick();
    virtual void Draw() = 0;

    void SetOffset(Vector2);
    void Move(Vector2);

protected:
    VisualElement(GameObject *, Vector2);

    Vector2 offset;
    SDL_Rect rect;
};

#endif