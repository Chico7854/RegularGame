#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Entity.h"
#include"Player.h"
#include"Enemy.h"
#include"Platform.h"

class Game
{
private:
    sf::RenderWindow window;
    sf::Texture floorTexture, bgTexture, shinobiTexture, youkaiTexture, samuraiTexture, platformTexture;
    sf::Sprite background;
    sf::Sprite floor;
    sf::Clock clock;
    const float floorHeight, speed;
    float frame2;

    Player player1;
    Player player2;

    Enemy youkai;

    Platform platform;
public:
    Game();
    virtual ~Game() {}
    void collisionX();
    void run();
};