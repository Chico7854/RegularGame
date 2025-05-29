#include "Jogo.h"

Jogo::Jogo():
    window(sf::VideoMode(1100, 650), "Prototipo Simao"), 
    height_floor(50), 
    speed(0.3f),
    frame2 (0.f),
    platform(textplat, 86, 24)
{
    if (!textsamurai.loadFromFile("imagens/samurai_run.png") || //adicionar fonte dos sprites
        !textshinobi.loadFromFile("imagens/shinobi_run.png") ||
        !textyoukai.loadFromFile("imagens/youkai_walk.png") ||
        !textfloor.loadFromFile("imagens/floor_mine.png") ||
        !textplat.loadFromFile("imagens/platform.png") ||
        !textbg.loadFromFile("imagens/bgsimao.png")) {
        std::cerr << "Falha ao ler arquivo de imagem\n";
    }

    player1 = Player(textsamurai, 73, 104);
    player2 = Player(textshinobi, 80, 82);
	youkai = Inimigo(textyoukai, 52, 75);

	youkai.setInitPosition(sf::Vector2f(100.f, window.getSize().y - height_floor - 75.f));

    player1.setWindow(&window);
    player2.setWindow(&window);
    youkai.setWindow(&window);
    platform.setWindow(&window);

    bg.setTexture(textbg);

    floor.setTexture(textfloor);
    floor.setPosition(0.f, window.getSize().y - height_floor);
}
void Jogo::collision_x()
{
	sf::FloatRect hitboxPlayer = player1.getHitbox();
	sf::FloatRect hitboxPlatform = platform.getHitbox();
    for (int i = hitboxPlayer.top; i < hitboxPlayer.left + hitboxPlayer.height; i++) {
        for (int j = hitboxPlayer.left; j < hitboxPlayer.left + hitboxPlayer.width; j++) {
            if (hitboxPlayer.intersects(hitboxPlatform)) {
				player1.setCollision(j);
            }
        }
    }
}

void Jogo::executar()
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

        player1.keyboard_att(0);
        player2.keyboard_att(1);

		collision_x();

        player1.update(time);
        player2.update(time);

		youkai.update(time);

        window.clear();
        window.draw(bg);
        window.draw(floor);
		platform.draw();
        //player2.draw();
        player1.draw();
		youkai.draw();
        window.display();
    }

}
