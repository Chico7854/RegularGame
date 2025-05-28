#include "Jogo.h"

Jogo::Jogo():
    window(sf::VideoMode(1100, 650), "Prototipo Simao"), 
    height_floor(50), 
    speed(0.3f),
    frame2 (0.f),
    player1(textsamurai, 73, 104),
    player2(textshinobi, 80, 82)
{
    player1.setWindow(&window);
    player2.setWindow(&window);

    if (!textsamurai.loadFromFile("imagens/samurai_run.png") || //adicionar fonte dos sprites
        !textshinobi.loadFromFile("imagens/shinobi_run.png") ||
        !textyoukai.loadFromFile("imagens/youkai_walk.png") ||
        !textfloor.loadFromFile("imagens/floor_mine.png") ||
        !textplat.loadFromFile("imagens/platform.png") ||
        !textbg.loadFromFile("imagens/bgsimao.png")) {
        std::cerr << "Falha ao ler arquivo de imagem\n";
    }

    bg.setTexture(textbg);

    floor.setTexture(textfloor);
    floor.setPosition(0.f, window.getSize().y - height_floor);
}

void Jogo::executar()
{
    platform.setTexture(textplat);
    platform.setPosition(600, 500);

    //sf::Sprite youkai(textyoukai, sf::IntRect(0, 0, LARGURAYOUKAI, 75)); largura youkai = 54
    //youkai.setPosition(window.getSize().x / 2 - LARGURAYOUKAI / 2, window.getSize().y - (youkai.getGlobalBounds().height + height_floor));

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

        player1.keyboard_att(0);
        player2.keyboard_att(1);

        player1.update(time);
        player2.update(time);

        window.clear();
        window.draw(bg);
        window.draw(floor);
        window.draw(platform);
        player1.draw();
        player2.draw();
        //window.draw(youkai);
        window.display();
    }

}
