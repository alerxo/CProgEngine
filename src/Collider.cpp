#include "Collider.h"
#include "PhysicsEngine.h"

Collider::Collider(GameObject *p, Vector2 offset) : Component(p)
{
    SetOffset(offset);
    physicsEngine.AddCollider(this);
}

Collider::~Collider()
{
    physicsEngine.RemoveCollider(this);
}

void Collider::SetOffset(Vector2 offset)
{
    this->offset = offset;
}