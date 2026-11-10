#include "Sprite.h"

Sprite::Sprite(GameObject *parent, Vector2 offset, std::string texturePath, Vector2 size) : VisualElement(parent, offset)
{
    texture = IMG_LoadTexture(engineSystem.renderer, (constants::gResourcePath + texturePath).c_str());

    SetSize(size);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
}

void Sprite::Draw()
{
    UpdateRect();

    SDL_RenderCopy(engineSystem.renderer, texture, NULL, &rect);
}

void Sprite::Move(Vector2 distance)
{
    offset += distance;
}

void Sprite::SetSize(Vector2 size)
{
    this->size = size;
}

void Sprite::UpdateRect()
{
    rect.x = (int)this->offset.x - (size.x / 2) + parent->GetPosition().x;
    rect.y = (int)this->offset.y - (size.y / 2) + parent->GetPosition().y;

    rect.h = (int)this->size.x;
    rect.w = (int)this->size.y;
}