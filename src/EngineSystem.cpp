#include "EngineSystem.h"

EngineSystem::EngineSystem()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Engine", 100, 100, 400, 500, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    if (TTF_Init() == -1)
    {
        exit(-1);
    }
}

void EngineSystem::Destroy()
{
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

EngineSystem engineSystem;