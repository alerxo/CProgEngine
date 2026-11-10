#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "Collider.h"

class BoxCollider : public Collider
{
private:
    Vector2 size;
    Vector2 *corners;

public:
    BoxCollider(GameObject *, Vector2, Vector2);
    ~BoxCollider();

    void SetSize(Vector2);
    void UpdateCorners();
    Vector2 *GetCorners();

    bool IsColliding(BoxCollider *);
};

#endif