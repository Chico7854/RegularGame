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

        // sf::Vector2f playerPos = player1.getSprite()->getPosition();
        // pGraphicsManager->setViewCenter(playerPos.x);
        // background.setPosition(pGraphicsManager->getViewPosition());
        // pGraphicsManager->draw(background);
        pEventManager->exec();
        stage.draw();
        stage.exec();
        pGraphicsManager->displayWindow();
    }
}