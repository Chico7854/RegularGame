#pragma once
#include "Obstacle.h"

class Platform : public Obstacle
{
public:
    Platform() {}
    Platform(sf::Texture& texture, int sprite_width, int sprite_height): Obstacle(texture, sprite_width, sprite_height)
    {
        sprite.setPosition(600, 500);
    }
    virtual ~Platform() {}

    void run() override {}
    void save() override {}
};