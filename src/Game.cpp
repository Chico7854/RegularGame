#include "Game.h"
#include "Utility/Texture.h"

Game::Game():
    pGraphicsManager(Manager::GraphicsManager::getGraphicsManager()),
    pEventManager(Manager::EventManager::getEventManager()),
    pCollisionManager(Manager::CollisionManager::getCollisionManager()),
    floorHeight(50),
    floor(Texture::Floor, 2000, 50),
    platform(Texture::Platform, Constants::PLATFORM_WIDTH, Constants::PLATFORM_HEIGHT),
    spike(Texture::Spike, Constants::SPIKE_WIDTH, Constants::SPIKE_HEIGHT), //uncomment when you have the sprites for the obstacles
	saw(Texture::Saw, Constants::SAW_WIDTH, Constants::SAW_HEIGHT),
    player1(Texture::Player1, Constants::P1_WIDTH, Constants::P1_HEIGHT),
    // player2(Texture::Player2, Constants::P2_WIDTH, Constants::P2_HEIGHT),
    youkai(Texture::Youkai, Constants::YOKAI_WIDTH, Constants::YOKAI_HEIGHT)
{
    bgTexture.loadFromFile("../images/bgsimao.png");

    background.setTexture(bgTexture);

    floor.setSpritePosition(0.f, Constants::FLOOR_HEIGHT);
    player1.setSpritePosition(0, Constants::FLOOR_HEIGHT - Constants::P1_HEIGHT);
    youkai.setSpritePosition(200, Constants::FLOOR_HEIGHT - Constants::YOKAI_HEIGHT);
    spike.setSpritePosition(100, Constants::FLOOR_HEIGHT - Constants::SPIKE_HEIGHT);
    saw.setSpritePosition(1000, Constants::FLOOR_HEIGHT - Constants::SAW_HEIGHT);
    platform.setSpritePosition(600, 400);

    pEventManager->setPlayer(&player1);
    pEventManager->setEntity(&youkai);
    pEventManager->setEntity(&platform);
    pEventManager->setEntity(&floor);
    pEventManager->setEntity(&spike);
    pEventManager->setEntity(&saw);
    pEventManager->setPlatform(&platform);
    pEventManager->setFloor(&floor);

    pCollisionManager->setPlayer(&player1);
    pCollisionManager->appendEnemy(&youkai);
    pCollisionManager->appendObstacle(&platform);
    pCollisionManager->appendObstacle(&floor);
    pCollisionManager->appendObstacle(&spike);
    pCollisionManager->appendObstacle(&saw);
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

        sf::Vector2f playerPos = player1.getSprite()->getPosition();
        pGraphicsManager->setViewCenter(playerPos.x);
        background.setPosition(pGraphicsManager->getViewPosition());
        pGraphicsManager->draw(background);

        pEventManager->exec();
        pGraphicsManager->displayWindow();
    }
}