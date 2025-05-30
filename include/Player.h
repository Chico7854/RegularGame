#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Player : public Character
{
private:
    int ground;
    bool on_ground;
    float frame, speed;
    int width, height;
    float dx, dy;

public:
    Player() {}
    Player(sf::Texture& texture, int sprite_width, int sprite_height);
    virtual ~Player() {}

    void run() override;
    void save() override;
    void move() override;

    void setCollision(int position);
    void keyboardInput(int playerNumber);
    void update(float time);
    sf::Sprite getPlayer() { return sprite; }
    bool getOnGround() { return on_ground; }
};