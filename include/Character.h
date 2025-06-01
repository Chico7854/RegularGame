#pragma once

#include "Entity.h"
#include "Utility/Texture.h"

class Character : public Entity
{
protected:
    int lives;
public:
    Character();
    Character(Texture::ID id, const int width, const int height);
    ~Character();

    virtual void run() = 0;
    virtual void save() = 0;
    virtual void move() = 0;
};