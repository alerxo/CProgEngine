#include "Collider.h"
#include <vector>

using namespace std;

class PhysicsEngine
{
public:
    void Run();
    void AddCollider(Collider *);
    void RemoveCollider(Collider *);
    void Destroy();

private:
    vector<Collider *> colliders;
    vector<Collider *> addedColliders;
    vector<Collider *> removedColliders;

    void HandleColliders();
    void CheckForCollisions();
};

extern PhysicsEngine physicsEngine;