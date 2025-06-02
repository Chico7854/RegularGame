#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entities/Entity.h"
#include "Entities/Characters/Player.h"
#include "Entities/Characters/Enemy.h"
#include "Entities/Obstacles/Platform.h"
#include "Entities/Obstacles/HardObstacle.h"
#include "Entities/Obstacles/MediumObstacle.h"
#include "Entities/Characters/EasyEnemy.h"
#include "Utility/Constants.h"
#include "Managers/GraphicsManager.h"
#include "Managers/EventManager.h"
#include "Managers/CollisionManager.h"
using namespace Entities;

class Game
{
private:
    Manager::GraphicsManager* pGraphicsManager;
    Manager::EventManager* pEventManager;
    Manager::CollisionManager* pCollisionManager;
    sf::Texture floorTexture, bgTexture;
    sf::Sprite background;
    sf::Sprite floor;
    const float floorHeight;

    Player player1;
    // Player player2;

    EasyEnemy youkai;

    Platform platform;
    MediumObstacle spike;
	HardObstacle saw;
public:
    Game();
    ~Game();
    void collisionX();
    void run();
};