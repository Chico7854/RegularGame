#pragma once
#include "Entity.h"

class Character : public Entity
{
protected:
    int lives;
public:
    Character();
    ~Character();

    virtual void run() = 0;
    virtual void save() = 0;
    virtual void move() = 0;
};