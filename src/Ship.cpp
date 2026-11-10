#include "Ship.h"
#include "ShipManager.h"

Ship::Ship(GameObject *parent, Vector2 startPosition) : GameObject(parent)
{
    icon = new Sprite(this, Vector2(), "Images/ship.png", Vector2(50, 50));
    AddComponent(icon);

    collider = new BoxCollider(this, Vector2(), Vector2(50, 50));
    AddComponent(collider);

    Move(startPosition);
}

Ship::~Ship() {}

void Ship::Update()
{
    Move(Vector2(0, 4));

    if (GetPosition().y > 550)
    {
        if (!ShipManager::GetInstance()->Score())
        {
            delete this;
        }
    }
}