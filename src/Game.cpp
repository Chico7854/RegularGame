#include "Game.h"

Game::Game():
    pGraphicsManager(Manager::GraphicsManager::getGraphicsManager()),
    pEventManager(Manager::EventManager::getEventManager()),
    pStateStack(States::StateStack::getInstance())
{
    Ent::setGraphicsManager(pGraphicsManager);
    pStateStack->pushState(States::StateType::Menu);
}

Game::~Game() {
    pGraphicsManager = nullptr;
    pEventManager = nullptr;
    pStateStack = nullptr;
}

void Game::run()
{
    while (pGraphicsManager->isWindowOpen())
    {
        pGraphicsManager->clearWindow();
        pEventManager->exec();
        pStateStack->exec();
        pGraphicsManager->displayWindow();
    }
}