#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Object.h"
#include "Component.h"
#include <vector>
#include "Vector2.h"

class GameObject : public Object
{
public:
    virtual ~GameObject();

    void OnGameTick();

    void AddComponent(Component *);
    void RemoveComponent(Component *);

    void SetParent(GameObject *);

    Vector2 GetPosition() { return position; };
    void Move(Vector2);

protected:
    GameObject();
    GameObject(GameObject *);

    virtual void Update(){};

private:
    void ProcessObjects();

    std::vector<Component *> components;
    std::vector<Component *> addedComponents;
    std::vector<Component *> removedComponents;

    Vector2 position;
};

#endif