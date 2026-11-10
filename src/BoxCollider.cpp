#include "BoxCollider.h"
#include "PhysicsEngine.h"

BoxCollider::BoxCollider(GameObject *parent, Vector2 offset, Vector2 size) : Collider(parent, offset)
{
    corners = new Vector2[2];
    SetSize(size);
}

BoxCollider::~BoxCollider()
{
    delete corners;
}

void BoxCollider::SetSize(Vector2 size)
{
    this->size = size;
}

void BoxCollider::UpdateCorners()
{
    corners[0] = parent->GetPosition() + offset + Vector2(-(size.x / 2), -(size.y / 2));
    corners[1] = parent->GetPosition() + offset + Vector2((size.x / 2), (size.y / 2));
}

Vector2 *BoxCollider::GetCorners()
{
    UpdateCorners();
    return corners;
}

bool BoxCollider::IsColliding(BoxCollider *other)
{
    Vector2 *corners = GetCorners();
    Vector2 *otherCorners = other->GetCorners();

    for (int i = 0; i < 4; i++)
    {
        if (otherCorners[i].x >= corners[0].x &&
            otherCorners[i].x <= corners[1].x &&
            otherCorners[i].y >= corners[0].y &&
            otherCorners[i].y <= corners[1].y)
        {
            return true;
        }
    }

    return false;
}