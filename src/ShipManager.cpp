#include "ShipManager.h"
#include "GameEngine.h"
#include "Ship.h"

ShipManager *ShipManager::instance;

ShipManager::ShipManager() : counter(0), spawnCooldown(90), hpCount(10), scoreCount(0)
{
    instance = this;

    hp = new Label(this, Vector2(50, 50), "hp: 10", 30);
    AddComponent(hp);

    score = new Label(this, Vector2(250, 50), "score: 0", 30);
    AddComponent(score);
}

ShipManager::~ShipManager()
{
    instance = NULL;
}

void ShipManager::Update()
{
    counter++;

    if (counter > spawnCooldown)
    {
        int x = (rand() % 300) + 50;

        Vector2 startPosition = Vector2(x, -50);

        gameEngine.AddGameObject(new Ship(this, startPosition));

        scoreCount++;
        score->SetText("score: " + to_string(scoreCount));

        counter = 0;

        if (spawnCooldown > 10)
        {
            spawnCooldown--;
        }
    }
}

bool ShipManager::Score()
{
    hpCount--;
    hp->SetText("hp: " + to_string(hpCount));

    if (hpCount == 0)
    {
        gameEngine.EndGameLoop();
        return true;
    }

    return false;
}