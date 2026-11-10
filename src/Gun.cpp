#include "Gun.h"
#include "Bullet.h"
#include "GameEngine.h"

Gun *Gun::instance;

Gun::Gun() : cooldown(0)
{
    icon = new Sprite(this, Vector2(), "Images/gun.png", Vector2(100, 100));
    AddComponent(icon);

    inputSystem.keyDown += Movement;
    inputSystem.keyDown += Shoot;

    instance = this;

    Move(Vector2(200, 450));
}

Gun::~Gun()
{
    instance = NULL;

    inputSystem.keyDown -= Movement;
    inputSystem.keyDown -= Shoot;
}

void Gun::Update()
{
    if (cooldown > 0)
    {
        cooldown--;
    }
}

void Gun::Movement(SDL_Keycode key)
{
    switch (key)
    {
    case SDLK_LEFT:
        if (GetInstance()->GetPosition().x > 25)
        {
            GetInstance()->Move(Vector2(-10, 0));
        }

        break;

    case SDLK_RIGHT:
        if (GetInstance()->GetPosition().x < 375)
        {
            GetInstance()->Move(Vector2(10, 0));
        }
        break;

    default:
        break;
    }
}

void Gun::Shoot(SDL_Keycode key)
{
    if (GetInstance()->cooldown > 0)
    {
        return;
    }

    if (key == SDLK_SPACE)
    {
        gameEngine.AddGameObject(new Bullet(GetInstance()));
        GetInstance()->cooldown = 10;
    }
}
