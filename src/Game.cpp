#include "Game.h"
#include "Utility/Texture.h"

Game::Game():
    pGraphicsManager(Manager::GraphicsManager::getGraphicsManager()),
    pEventManager(Manager::EventManager::getEventManager()),
    pCollisionManager(Manager::CollisionManager::getCollisionManager()),
    stage()
{
    Ent::setGraphicsManager(pGraphicsManager);
    stage.createMap();
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

        pGraphicsManager->setViewCenter(stage.getPlayer()->getGlobalHitbox().left);
        stage.setSpritePosition(pGraphicsManager->getViewPositionX(), 0.f);
        pEventManager->exec();
        stage.draw();
        stage.exec();
        pGraphicsManager->displayWindow();
    }
}