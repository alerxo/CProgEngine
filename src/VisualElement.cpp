#include "VisualElement.h"
#include "Constants.h"
#include "GameObject.h"

VisualElement::VisualElement(GameObject *p, Vector2 offset) : Component(p), rect{0, 0, 0, 0}
{
    SetOffset(offset);
}

VisualElement::~VisualElement() {}

void VisualElement::OnGameTick()
{
    Draw();
}

void VisualElement::SetOffset(Vector2 offset)
{
    this->offset = offset;
}

void VisualElement::Move(Vector2 distance)
{
    offset += distance;
}
