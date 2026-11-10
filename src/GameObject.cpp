#include "GameObject.h"
#include "GameEngine.h"

using namespace std;

GameObject::GameObject() : Object(nullptr), position(0, 0) {}

GameObject::GameObject(GameObject *p) : Object(p), position(0, 0) {}

GameObject::~GameObject()
{
    gameEngine.RemoveGameObject(this);

    for (Component *component : components)
    {
        delete component;
    }

    for (Component *component : addedComponents)
    {
        delete component;
    }

    for (Component *component : removedComponents)
    {
        delete component;
    }

    components.clear();
    addedComponents.clear();
    removedComponents.clear();
}

void GameObject::OnGameTick()
{
    ProcessObjects();

    for (Component *component : components)
    {
        component->OnGameTick();
    }

    Update();
}

void GameObject::ProcessObjects()
{
    for (Component *component : addedComponents)
    {
        components.push_back(component);
    }

    addedComponents.clear();

    for (Component *component : removedComponents)
    {
        for (vector<Component *>::iterator i = components.begin(); i != components.end();)
        {
            if (*i == component)
            {
                i = components.erase(i);
            }

            else
            {
                i++;
            }
        }
    }

    removedComponents.clear();
}

void GameObject::AddComponent(Component *component)
{
    addedComponents.push_back(component);
}

void GameObject::RemoveComponent(Component *component)
{
    addedComponents.push_back(component);
}

void GameObject::SetParent(GameObject *p)
{
    parent = p;
}

void GameObject::Move(Vector2 distance)
{
    position += distance;
}