#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

struct EngineSystem
{
    EngineSystem();
    void Destroy();

    SDL_Window *window;
    SDL_Renderer *renderer;
};

extern EngineSystem engineSystem;

#endif