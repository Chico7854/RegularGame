#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Managers/GraphicsManager.h"
#include "Managers/EventManager.h"

#include "States/Menus/MenuState.h"
#include "States/Stages/DayMountainStage.h"
#include "States/Stages/NightMountainStage.h"

#include "Utility/Constants.h"
#include "Utility/Texture.h"

using namespace Entities;

class Game
{
private:
    Manager::GraphicsManager* pGraphicsManager;
    Manager::EventManager* pEventManager;
    // Manager::StateManager* pStateManager;
    //Stage::DayMountainStage stage;
    States::StateStack* pStateStack;
    
public:
    Game();
    ~Game();
    void run();
};