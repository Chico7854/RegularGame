#include"Player.h"

Player::Player(sf::RenderWindow& window,sf::Texture &texture, int largura_sprite, int altura_sprite):
	dx(0.1), dy(0.1),
	ground(window.getSize().y - 50),
    on_ground(true),
    frame(0),
    speed(0.3f),
    largura(largura_sprite),
    altura(altura_sprite)
{
    player.setTexture(texture);
    player.setTextureRect(sf::IntRect(0, 0, largura, altura));
    player.setPosition(0.f, window.getSize().y - (altura + 50));

    rect = sf::FloatRect(0, ground - altura, largura, altura);
}
void Player::update(float time) 
{
    rect.left += dx * time;
    rect.top += dy * time;

    if (!on_ground) {
        dy = dy + 0.0006 * time;//define a altura do pulo
        player.move(player.getPosition().x, dy);
    }

    on_ground = false;

    if (rect.top > ground - player.getGlobalBounds().height) {
        rect.top = ground - player.getGlobalBounds().height;
        dy = 0;
        on_ground = true;
    }

    frame += 0.008f * time;//velocidade da animacao
    if (frame >= 8) {
        frame = 0;
    }

    if(on_ground){
        if (dx > 0) {
            player.setTextureRect(sf::IntRect(largura * (int)frame, 0, largura, altura));
        }
        if (dx < 0) {
            player.setTextureRect(sf::IntRect(largura * ((int)frame + 1) ,0, -largura, altura));
        }
    }

    player.setPosition(rect.left, rect.top);
    dx = 0;
}
