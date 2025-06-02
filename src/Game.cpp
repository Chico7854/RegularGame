#include "Game.h"
#include "Utility/Texture.h"

Game::Game():
    pGraphicsManager(Manager::GraphicsManager::getGraphicsManager()),
    pEventManager(Manager::EventManager::getEventManager()),
    pCollisionManager(Manager::CollisionManager::getCollisionManager()),
    floorHeight(50),
    platform(Texture::Platform, Constants::PLATFORM_WIDTH, Constants::PLATFORM_HEIGHT),
    spike(Texture::Spike, Constants::SPIKE_WIDTH, Constants::SPIKE_HEIGHT), //uncomment when you have the sprites for the obstacles
	saw(Texture::Saw, Constants::SAW_WIDTH, Constants::SAW_HEIGHT),
    player1(Texture::Player1, Constants::P1_WIDTH, Constants::P1_HEIGHT),
    // player2(Texture::Player2, Constants::P2_WIDTH, Constants::P2_HEIGHT),
    youkai(Texture::Youkai, Constants::YOKAI_WIDTH, Constants::YOKAI_HEIGHT)
{
    #ifdef _WIN32
        floorTexture.loadFromFile("images/floor_mine.png");
        bgTexture.loadFromFile("images/bgsimao.png");
    #else
        floorTexture.loadFromFile("../images/floor_mine.png");
        bgTexture.loadFromFile("../images/bgsimao.png");
    #endif

    background.setTexture(bgTexture);

    floor.setTexture(floorTexture);
    floor.setPosition(0.f, Constants::WINDOW_HEIGHT - floorHeight);

    pEventManager->setPlayer(&player1);
    pEventManager->setEntity(&youkai);
    pEventManager->setEntity(&platform);
    pEventManager->setEntity(&spike);
    pEventManager->setEntity(&saw);
    pCollisionManager->appendEnemy(&youkai);
    pCollisionManager->appendObstacle(&platform);

    platform.setSpritePosition(600, 400);
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
        pGraphicsManager->draw(background);
        pGraphicsManager->draw(floor);
        pEventManager->exec();
        pCollisionManager->verifyCollision(std::make_pair(&player1, &platform));
        pGraphicsManager->displayWindow();
    }
}