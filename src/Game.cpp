#include "../include/Game.h"

Game::Game() :
    window(sf::VideoMode(1100, 650), "Simao Game"),
    floorHeight(50),
    speed(0.3f),
    frame2(0.f),
    platform(platformTexture, 86, 24),
    spike(spikeTexture, 25, 17), //uncomment when you have the sprites for the obstacles
	saw(sawTexture, 96, 96)
{
	if (!samuraiTexture.loadFromFile("images/samurai_run.png") || //remember to give credit to the authors of the images
        !shinobiTexture.loadFromFile("images/shinobi_run.png") ||
        !youkaiTexture.loadFromFile("images/youkai_walk.png") ||
        !floorTexture.loadFromFile("images/floor_mine.png") ||
        !platformTexture.loadFromFile("images/platform.png") ||
        !bgTexture.loadFromFile("images/bgsimao.png") ||
        !spikeTexture.loadFromFile("images/spike.png") ||
        !sawTexture.loadFromFile("images/saw.png")) { //find sprites for the oyher enemys
        std::cerr << "Failed to load image file\n";
    }

    player1 = Player(samuraiTexture, 73, 104);
    player2 = Player(shinobiTexture, 80, 82);
    youkai = EasyEnemy(youkaiTexture, 52, 75);

    youkai.setInitialPosition(sf::Vector2f(100.f, window.getSize().y - floorHeight - 75.f));

    player1.setWindow(&window);
    player2.setWindow(&window);
    youkai.setWindow(&window);
    platform.setWindow(&window);
    spike.setWindow(&window);
	saw.setWindow(&window);

    background.setTexture(bgTexture);

    floor.setTexture(floorTexture);
    floor.setPosition(0.f, window.getSize().y - floorHeight);
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
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        player1.keyboardInput(0);
        player2.keyboardInput(1);

        collisionX();

        player1.update(time);
        player2.update(time);

        youkai.update(time);

		saw.animation(time);

        window.clear();
        window.draw(background);
        window.draw(floor);
        platform.draw();
        spike.draw();
		saw.draw();
        //player2.draw();
        player1.draw();
        youkai.draw();
        window.display();
    }
}