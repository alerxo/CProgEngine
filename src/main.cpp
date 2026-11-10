#include "GameEngine.h"
#include "Gun.h"
#include "ShipManager.h"

int main(int argc, char *argv[])
{
	gameEngine.AddGameObject(new Gun());
	gameEngine.AddGameObject(new ShipManager());

	gameEngine.SetFps(60);

	gameEngine.Run();
	gameEngine.Destroy();

	return 0;
}