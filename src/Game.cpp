#include "Game.h"
#include "Utility/Texture.h"

Game::Game():
    pGraphicsManager(Manager::GraphicsManager::getGraphicsManager()),
    pEventManager(Manager::EventManager::getEventManager()),
    floorHeight(50),
    speed(0.3f),
    frame2(0.f),
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

    youkai.setInitialPosition(sf::Vector2f(100.f, Constants::WINDOW_HEIGHT - floorHeight - 75.f));

    background.setTexture(bgTexture);

    floor.setTexture(floorTexture);
    floor.setPosition(0.f, Constants::WINDOW_HEIGHT - floorHeight);

    pEventManager->setPlayer(&player1);
    pEventManager->setEntity(&youkai);
    pEventManager->setEntity(&platform);
    pEventManager->setEntity(&spike);
    pEventManager->setEntity(&saw);
}

Game::~Game() {
    delete pGraphicsManager;
    delete pEventManager;
}

void Game::run()
{
    while (pGraphicsManager->isWindowOpen())
    {
        pGraphicsManager->clearWindow();
        pGraphicsManager->draw(background);
        pGraphicsManager->draw(floor);
        pEventManager->exec();
        pGraphicsManager->displayWindow();
    }
}