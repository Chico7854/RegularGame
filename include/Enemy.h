#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"
#include "Utility/Texture.h"

class Enemy : public Character
{
protected:
    float frame, speed;
    float dx, dy;
    int ground;

public:
    Enemy() {}
    Enemy(Texture::ID id, int sprite_width, int sprite_height);
    virtual ~Enemy() {}
    virtual void setInitialPosition(sf::Vector2f pos){}
    void run() override;
    void save() override;
    void move() override;
    virtual void update(float time){}
    sf::Sprite getEnemy() { return sprite; }
};