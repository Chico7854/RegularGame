#include "Game.h"
#include "Utility/Texture.h"

Game::Game():
    pGraphicsManager(Manager::GraphicsManager::getGraphicsManager()),
    pEventManager(Manager::EventManager::getEventManager()),
    pStateManager(Manager::StateManager::getStateManager())
{
    Ent::setGraphicsManager(pGraphicsManager);
    pStateManager->addState(States::StateType::Game);
}

Game::~Game() {
    pGraphicsManager = nullptr;
    pEventManager = nullptr;
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