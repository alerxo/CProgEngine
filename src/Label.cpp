#include "Label.h"

Label::Label(GameObject *parent, Vector2 offset, string text, int fontSize) : VisualElement(parent, offset), text(text), fontSize(fontSize), color{0, 0, 0}
{
    font = TTF_OpenFont((constants::gResourcePath + "Fonts/times.ttf").c_str(), fontSize);
    surface = TTF_RenderText_Solid(font, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(engineSystem.renderer, surface);

    rect.x = GetParent()->GetPosition().x + offset.x;
    rect.y = GetParent()->GetPosition().y + offset.y;

    rect.h = surface->h;
    rect.w = surface->w;
}

Label::~Label()
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}

void Label::UpdateTexture()
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);

    font = TTF_OpenFont((constants::gResourcePath + "Fonts/times.ttf").c_str(), fontSize);
    surface = TTF_RenderText_Solid(font, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(engineSystem.renderer, surface);

    rect.x = GetParent()->GetPosition().x + offset.x;
    rect.y = GetParent()->GetPosition().y + offset.y;

    rect.h = surface->h;
    rect.w = surface->w;
}

void Label::Draw()
{
    SDL_RenderCopy(engineSystem.renderer, texture, NULL, &rect);
}

void Label::SetText(string text)
{
    this->text = text;

    UpdateTexture();
}

void Label::SetFontSize(int fontSize)
{
    this->fontSize = fontSize;

    UpdateTexture();
}