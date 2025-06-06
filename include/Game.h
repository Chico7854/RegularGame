#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entities/Entity.h"
#include "Entities/Characters/Player.h"
#include "Entities/Characters/Enemy.h"
#include "Entities/Projectile.h"
#include "Utility/Constants.h"
#include "Managers/GraphicsManager.h"
#include "Managers/EventManager.h"
#include "Managers/CollisionManager.h"
#include "Managers/StateManager.h"
#include "Stage/Stage.h"

#include "Utility/Constants.h"

using namespace Entities;

class Game
{
private:
    Manager::GraphicsManager* pGraphicsManager;
    Manager::EventManager* pEventManager;
    Manager::StateManager* pStateManager;
    // sf::Texture floorTexture, bgTexture;
    // sf::Sprite background;
    // const float floorHeight;

    // Player player1;
    // // Player player2;

    // Youkai youkai;

    // Platform floor, platform;
    // MediumObstacle spike;
	// HardObstacle saw;
public:
    Game();
    ~Game();
    void run();
};