#include "GameObject.h"
#include "Sprite.h"
#include "BoxCollider.h"

class Ship : public GameObject
{
public:
    Ship(GameObject *, Vector2);
    ~Ship();

    void Update();

private:
    Sprite *icon;
    BoxCollider *collider;
};