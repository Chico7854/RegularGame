#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"
#include "Utility/Texture.h"

class Player : public Character
{
private:
    bool on_ground;
    float frame, speed;
    float dx, dy;

public:
    Player() {}
    Player(Texture::ID id, const int width, const int height);
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