#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Managers/GraphicsManager.h"
#include "Managers/EventManager.h"
#include "Managers/StateManager.h"
#include "Stage/DayMountainStage.h"

#include "Utility/Constants.h"
#include "Utility/Texture.h"

using namespace Entities;

class Game
{
private:
    Manager::GraphicsManager* pGraphicsManager;
    Manager::EventManager* pEventManager;
    // Manager::StateManager* pStateManager;
    Stage::DayMountainStage stage;
    
public:
    Game();
    ~Game();
    void run();
};