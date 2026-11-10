#include "Bullet.h"

void BulletHit(Collider *collider)
{
    delete collider->GetParent();
}

Bullet::Bullet(GameObject *parent) : GameObject(parent)
{
    icon = new Sprite(this, Vector2(), "Images/bullet.png", Vector2(50, 50));
    AddComponent(icon);

    collider = new BoxCollider(this, Vector2(), Vector2(50, 50));
    AddComponent(collider);

    collider->onCollision += BulletHit;

    Move(parent->GetPosition());
}

Bullet::~Bullet() {}

void Bullet::Update()
{
    Move(Vector2(0, -5));

    if (GetPosition().y < -100)
    {
        delete this;
    }
}