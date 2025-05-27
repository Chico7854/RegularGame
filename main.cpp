#include <SFML/Graphics.hpp>
#include<iostream>
#include"Player.h"

#define LARGURAYOUKAI 54

int main()
{
    sf::RenderWindow window(sf::VideoMode(1100,650), "Prototipo Simao");

    const float height_floor = 50, speed = 0.3f;
    float frame2 = 0.f;

    sf::Texture textfloor, textbg, textshinobi, textyoukai, textsamurai,textplat;
    if (!textsamurai.loadFromFile("imagens/samurai_run.png") ||
        !textshinobi.loadFromFile("imagens/shinobi_run.png") ||
        !textyoukai.loadFromFile("imagens/youkai_walk.png") ||
        !textfloor.loadFromFile("imagens/floor_mine.png") ||
        !textplat.loadFromFile("imagens/platform.png") ||
        !textbg.loadFromFile("imagens/bgsimao.png")) {
        std::cerr << "Falha ao ler arquivo de imagem\n";
        return 0;
    }

    Player player1(window,textsamurai,73,104);
    Player player2(window,textshinobi,80,82);

    sf::Sprite bg;
    bg.setTexture(textbg);

    sf::Sprite floor;
    floor.setTexture(textfloor);
    floor.setPosition(0.f, window.getSize().y - height_floor);

    sf::Sprite platform;
    platform.setTexture(textplat);
    platform.setPosition(600,500);

    sf::Sprite youkai(textyoukai, sf::IntRect(0, 0, LARGURAYOUKAI, 75));
    youkai.setPosition(window.getSize().x / 2 - LARGURAYOUKAI / 2, window.getSize().y - (youkai.getGlobalBounds().height + height_floor));

    sf::Clock clock;

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
        


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player1.dx = speed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player1.dx = -speed ;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player1.getOnGround()) {
            player1.dy = -speed * 1.3;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player2.dx = speed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player2.dx = -speed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player2.getOnGround()) {
            player2.dy = -speed * 1.2;
        }

        player1.update(time);
        player2.update(time);

        window.clear();
        window.draw(bg);
        window.draw(floor);
        window.draw(platform);
        //window.draw(player2.getPlayer());
        window.draw(player1.getPlayer());
        //window.draw(youkai);
        window.display();
    }

    return 0;
}
