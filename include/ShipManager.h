#include "GameObject.h"
#include "Label.h"

class ShipManager : public GameObject
{
public:
    ShipManager();
    ~ShipManager();

    void Update();
    bool Score();

    static ShipManager *GetInstance() { return instance; };

private:
    static ShipManager *instance;
    Label *hp;
    Label *score;
    int counter;
    int spawnCooldown;
    int hpCount;
    int scoreCount;
};