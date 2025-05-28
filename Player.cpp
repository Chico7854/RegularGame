#include"Player.h"

Player::Player(sf::Texture &texture, int largura_sprite, int altura_sprite):
	dx(0.1), dy(0.1),
    ground(600),
    on_ground(true),
    frame(0),
    speed(0.3f),
    largura(largura_sprite),
    altura(altura_sprite)
{
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, largura, altura));
    sprite.setPosition(0.f, ground + altura);

    hitbox = sf::FloatRect(0, ground - altura, largura, altura);
}
void Player::keyboard_att(int qual_player)
{
    if(qual_player == 0){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            dx = speed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            dx = -speed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && getOnGround()) {
            dy = -speed * 1.3;
        }
    }
    else{
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            dx = speed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            dx = -speed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && getOnGround()) {
            dy = -speed * 1.3;
        }
    }
}
void Player::update(float time)
{
    hitbox.left += dx * time;
    hitbox.top += dy * time;

    if (!on_ground) {
        dy = dy + 0.0006 * time;//define a altura do pulo
        sprite.move(sprite.getPosition().x, dy);
    }

    on_ground = false;

    if (hitbox.top > ground - sprite.getGlobalBounds().height) {
        hitbox.top = ground - sprite.getGlobalBounds().height;
        dy = 0;
        on_ground = true;
    }

    frame += 0.008f * time;//velocidade da animacao
    if (frame >= 8) {
        frame = 0;
    }

    if(on_ground){
        if (dx > 0) {
            sprite.setTextureRect(sf::IntRect(largura * (int)frame, 0, largura, altura));
        }
        if (dx < 0) {
            sprite.setTextureRect(sf::IntRect(largura * ((int)frame + 1) ,0, -largura, altura));
        }
    }

    sprite.setPosition(hitbox.left, hitbox.top);
    dx = 0;
}
