#include "PhysicsEngine.h"
#include "BoxCollider.h"

void PhysicsEngine::Run()
{
    HandleColliders();
    CheckForCollisions();
}

void PhysicsEngine::HandleColliders()
{
    for (Collider *collider : addedColliders)
    {
        colliders.push_back(collider);
    }

    addedColliders.clear();

    for (Collider *collider : removedColliders)
    {
        for (vector<Collider *>::iterator i = colliders.begin(); i != colliders.end();)
        {
            if (*i == collider)
            {
                i = colliders.erase(i);
            }

            else
            {
                i++;
            }
        }
    }

    removedColliders.clear();
}

void PhysicsEngine::AddCollider(Collider *collider)
{
    addedColliders.push_back(collider);
}

void PhysicsEngine::RemoveCollider(Collider *collider)
{
    removedColliders.push_back(collider);
}

void PhysicsEngine::CheckForCollisions()
{
    struct Collision
    {
        Collider *collider;
        Collider *other;
    };

    vector<Collision> collisions;

    for (Collider *collider : colliders)
    {
        for (Collider *other : colliders)
        {
            if (collider->GetParent() == other->GetParent())
            {
                continue;
            }

            if (collider->IsColliding(dynamic_cast<BoxCollider *>(other)))
            {
                collisions.push_back(Collision{collider, other});
            }
        }
    }

    for (Collision collision : collisions)
    {
        collision.collider->OnCollision(collision.other);
    }
}

void PhysicsEngine::Destroy()
{
    colliders.clear();
    addedColliders.clear();
    removedColliders.clear();
}

PhysicsEngine physicsEngine;
