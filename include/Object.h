#ifndef OBJECT_H
#define OBJECT_H

class GameObject;

class Object
{
public:
    virtual void OnGameTick(){};
    virtual ~Object() = default;
    GameObject *GetParent() { return parent; };

protected:
    Object(GameObject *);
    GameObject *parent;
};

#endif