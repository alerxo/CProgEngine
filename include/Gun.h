#include "GameObject.h"
#include "InputSystem.h"
#include "Sprite.h"

class Gun : public GameObject
{
public:
    Gun();
    ~Gun();

    void Update();

    static Gun *GetInstance() { return instance; };

private:
    static void Movement(SDL_Keycode);
    static void Shoot(SDL_Keycode);
    static Gun *instance;
    Sprite *icon;
    int cooldown;
};