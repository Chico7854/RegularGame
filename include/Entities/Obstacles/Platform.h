#pragma once

#include "Obstacle.h"
#include "Utility/Texture.h"

class Platform : public Obstacle
{
public:
    Platform() {}
    Platform(Texture::ID id, int sprite_width, int sprite_height): Obstacle(id, sprite_width, sprite_height)
    {
        sprite.setPosition(600, 500);
    }
    virtual ~Platform() {}

    void run() override {}
    void save() override {}
};