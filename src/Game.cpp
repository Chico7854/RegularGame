#include "Game.h"
#include "Utility/Texture.h"


Game::Game():
    pGraphicsManager(Manager::GraphicsManager::getGraphicsManager()),
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
}

void Game::collisionX()
{
    sf::FloatRect playerHitbox = player1.getHitbox();
    sf::FloatRect platformHitbox = platform.getHitbox();
    for (int i = playerHitbox.top; i < playerHitbox.left + playerHitbox.height; i++) {
        for (int j = playerHitbox.left; j < playerHitbox.left + playerHitbox.width; j++) {
            if (playerHitbox.intersects(platformHitbox)) {
                player1.setCollision(j);
            }
        }
    }
}

void Game::run()
{
    while (pGraphicsManager->isWindowOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        sf::Event event;
        while (pGraphicsManager->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                pGraphicsManager->closeWindow();
            }
        }

        player1.keyboardInput(0);
        // player2.keyboardInput(1);

        collisionX();

        player1.update(time);
        // player2.update(time);

        youkai.update(time);

		saw.animation(time);

        pGraphicsManager->clearWindow();
        pGraphicsManager->draw(background);
        pGraphicsManager->draw(floor);
        platform.draw();
        spike.draw();
		saw.draw();
        // player2.draw();
        player1.draw();
        youkai.draw();
        pGraphicsManager->displayWindow();
    }
}