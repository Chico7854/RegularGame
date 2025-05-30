#pragma once
#include "Obstacle.h"

class Platform : public Obstacle
{
private:
    int width, height;

public:
    Platform() {}
    Platform(sf::Texture& texture, int sprite_width, int sprite_height) :
        width(sprite_width),
        height(sprite_height)
    {
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, width, height));
        sprite.setPosition(600, 500);
        hitbox = sf::FloatRect(600, 500, width, height);
    }
    virtual ~Platform() {}

    void run() override {}
    void save() override {}
};