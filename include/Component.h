#ifndef COMPONENT_H
#define COMPONENT_H

#include "Object.h"

class Component : public Object
{
public:
    virtual ~Component();

    virtual void OnGameTick(){};

protected:
    Component(GameObject *);
};

#endif