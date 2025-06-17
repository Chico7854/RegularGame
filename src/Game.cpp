#include "Game.h"

Game::Game():
    pGraphicsManager(Manager::GraphicsManager::getGraphicsManager()),
    pEventManager(Manager::EventManager::getEventManager()),
    pStateStack(States::StateStack::getInstance())
    // pStateManager(Manager::StateManager::getStateManager())
    //stage()
{
    Ent::setGraphicsManager(pGraphicsManager);
    // pStateManager->addState(States::StateType::GameDay);
    // pStateManager->addState(States::StateType::GameNight);
    // stage.createMap();
    pStateStack->pushState(States::StateType::Menu);
}

Game::~Game() {
    pGraphicsManager = nullptr;
    pEventManager = nullptr;
    // pStateManager = nullptr;
}

void Game::run()
{
    while (pGraphicsManager->isWindowOpen())
    {
        pGraphicsManager->clearWindow();
        pEventManager->exec();
        // pStateManager->exec();
        pStateStack->exec();
        //stage.exec();
        pGraphicsManager->displayWindow();
    }
}