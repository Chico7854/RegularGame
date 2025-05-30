#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>
#include<iostream>

class Enemy : public Character
{
private:
    int ground;
    float frame, speed;
    int width, height;
    float dx, dy;
public:
    Enemy() {}
    Enemy(sf::Texture& texture, int sprite_width, int sprite_height);
    virtual ~Enemy() {}
    void setInitialPosition(sf::Vector2f pos);
    void run() override;
    void save() override;
    void move() override;
    void update(float time);
    sf::Sprite getEnemy() { return sprite; }
};