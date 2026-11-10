#ifndef LABEL_H
#define LABEL_H

#include "VisualElement.h"
#include <string>

using namespace std;

class Label : public VisualElement
{
public:
    Label(GameObject *, Vector2, string text, int fontSize);
    ~Label();

    void Draw();

    void UpdateTexture();

    string GetText() { return text; };
    int GetFontSize() { return fontSize; };

    void SetText(string);
    void SetFontSize(int);

private:
    string text;
    int fontSize;
    TTF_Font *font;
    SDL_Color color;
    SDL_Surface *surface;
    SDL_Texture *texture;
};

#endif