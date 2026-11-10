#include "GameObject.h"
#include "Sprite.h"
#include "BoxCollider.h"

class Bullet : public GameObject
{
public:
    Bullet(GameObject *);
    ~Bullet();

    void Update();

private:
    Sprite *icon;
    BoxCollider *collider;
};