#include "Constants.h"
#include "GameEngine.h"
#include "EngineSystem.h"
#include "PhysicsEngine.h"
#include "InputSystem.h"

void GameEngine::Run()
{
    while (isRunning)
    {
        HandleGameObjects();

        SDL_SetRenderDrawColor(engineSystem.renderer, 255, 255, 255, 255);
        SDL_RenderClear(engineSystem.renderer);

        HandleSDLEvents();

        for (GameObject *gameObject : gameObjects)
        {
            gameObject->OnGameTick();
        }

        physicsEngine.Run();

        SDL_RenderPresent(engineSystem.renderer);

        WaitForNextTick();
    }
}

void GameEngine::HandleSDLEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_END)
            {
                isRunning = true;
            }
            inputSystem.HandleKeyDown(event.key);
            break;

        case SDL_KEYUP:
            inputSystem.HandleKeyUp(event.key);
            break;

        case SDL_MOUSEBUTTONDOWN:
            inputSystem.HandleMouseDown(event.button);
            break;

        case SDL_MOUSEBUTTONUP:
            inputSystem.HandleMouseUp(event.button);
            break;

        default:
            break;
        }
    }
}

void GameEngine::HandleGameObjects()
{
    for (GameObject *gameObject : addedGameObjects)
    {
        gameObjects.push_back(gameObject);
    }

    addedGameObjects.clear();

    for (GameObject *gameObject : removedGameObjects)
    {
        for (vector<GameObject *>::iterator i = gameObjects.begin(); i != gameObjects.end();)
        {
            if (*i == gameObject)
            {
                i = gameObjects.erase(i);
            }

            else
            {
                i++;
            }
        }
    }

    removedGameObjects.clear();
}

void GameEngine::AddGameObject(GameObject *gameObject)
{
    addedGameObjects.push_back(gameObject);
}

void GameEngine::RemoveGameObject(GameObject *gameObject)
{
    if (!isRunning)
    {
        return;
    }

    removedGameObjects.push_back(gameObject);
}

void GameEngine::WaitForNextTick()
{
    int tickInterval = 1000 / fps;

    Uint32 nextTick = SDL_GetTicks() + tickInterval;

    int delay = nextTick - SDL_GetTicks();

    if (delay > 0)
    {
        SDL_Delay(delay);
    }
}

void GameEngine::SetFps(int fps)
{
    this->fps = fps;
}

void GameEngine::Destroy()
{
    for (GameObject *gameObject : addedGameObjects)
    {
        delete gameObject;
    }

    for (GameObject *gameObject : removedGameObjects)
    {
        delete gameObject;
    }

    for (GameObject *gameObject : gameObjects)
    {
        delete gameObject;
    }

    gameObjects.clear();
    addedGameObjects.clear();
    removedGameObjects.clear();

    physicsEngine.Destroy();
    engineSystem.Destroy();
}

GameEngine gameEngine;