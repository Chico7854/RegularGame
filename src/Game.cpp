#include "Game.h"

Game::Game():
    pGraphicsManager(Manager::GraphicsManager::getGraphicsManager()),
    pEventManager(Manager::EventManager::getEventManager()),
    pStateManager(Manager::StateManager::getStateManager())
{
    Ent::setGraphicsManager(pGraphicsManager);
    // pStateManager->addState(States::StateType::GameDay);
    pStateManager->addState(States::StateType::GameNight);
}

Game::~Game() {
    pGraphicsManager = nullptr;
    pEventManager = nullptr;
    pStateManager = nullptr;
}

void Game::run()
{
    while (pGraphicsManager->isWindowOpen())
    {
        pGraphicsManager->clearWindow();
        pEventManager->exec();
        pStateManager->exec();
        pGraphicsManager->displayWindow();
    }
}