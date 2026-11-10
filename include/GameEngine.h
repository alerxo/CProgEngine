#include "GameObject.h"

using namespace std;

class GameEngine
{
public:
    void Run();
    void AddGameObject(GameObject *);
    void RemoveGameObject(GameObject *);

    void SetFps(int);
    void EndGameLoop() { isRunning = false; };
    void Destroy();

private:
    bool isRunning = true;
    int fps = 60;
    vector<GameObject *> gameObjects;
    vector<GameObject *> addedGameObjects;
    vector<GameObject *> removedGameObjects;

    void HandleSDLEvents();
    void HandleGameObjects();
    void WaitForNextTick();
};

extern GameEngine gameEngine;