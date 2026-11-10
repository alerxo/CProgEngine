#ifndef COLLIDER_H
#define COLLIDER_H

#include "Vector2.h"
#include "Component.h"
#include "GameObject.h"
#include "Event.h"

class BoxCollider;

class Collider : public Component
{
public:
    ~Collider();

    void SetOffset(Vector2);
    virtual bool IsColliding(BoxCollider *) = 0;
    void OnCollision(Collider *other) { onCollision.Invoke(other); };

    Event<Collider *> onCollision;

protected:
    Collider(GameObject *, Vector2);
    Vector2 offset;
};

#endif