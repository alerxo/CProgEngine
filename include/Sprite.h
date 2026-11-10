#ifndef SPRITE_H
#define SPRITE_H

#include "VisualElement.h"
#include <string>

class Sprite : public VisualElement
{
public:
    Sprite(GameObject *, Vector2, std::string, Vector2);

    ~Sprite();

    void Draw();

    void Move(Vector2);
    void SetSize(Vector2);

private:
    void UpdateRect();

    Vector2 size;
    SDL_Texture *texture;
};

#endif