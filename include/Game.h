#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Entity.h"
#include"Player.h"
#include"Enemy.h"
#include"Platform.h"
#include"HardObstacle.h"
#include"MediumObstacle.h"
#include"EasyEnemy.h"
#include "Utility/Constants.h"
#include "Managers/GraphicsManager.h"

class Game
{
private:
    Manager::GraphicsManager* pGraphicsManager;
    sf::Texture floorTexture, bgTexture;
    sf::Sprite background;
    sf::Sprite floor;
    sf::Clock clock;
    const float floorHeight, speed;
    float frame2;

    Player player1;
    // Player player2;

    EasyEnemy youkai;

    Platform platform;
    MediumObstacle spike;
	HardObstacle saw;
public:
    Game();
    virtual ~Game() {}
    void collisionX();
    void run();
};