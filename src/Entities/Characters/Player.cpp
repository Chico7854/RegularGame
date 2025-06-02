#include "Entities/Characters/Player.h"

namespace Entities {
    Player::Player(Texture::ID id, const int width, const int height):
        Character(id, width, height),
        dx(0.1), dy(0.1),
        on_ground(true),
        frame(0),
        speed(0.3f)
    {
        sprite.setPosition(0.f, ground + height);

        hitbox = sf::FloatRect(0, ground - height, width, height);
    }

    void Player::run()
    {
    }

    void Player::save()
    {
    }

    void Player::setCollision(int position)
    {
        if (dx > 0) {
            hitbox.left = position - width;
        }
        if (dx < 0) {
            hitbox.left = position + width;
        }
    }

    void Player::keyboardInput(int playerNumber)
    {
        if (playerNumber == 0) {
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
        else {
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
            dy = dy + 0.0006 * time; // Jump height calculation
            sprite.move(sprite.getPosition().x, dy);
        }

        on_ground = false;

        if (hitbox.top > ground - sprite.getGlobalBounds().height) {
            hitbox.top = ground - sprite.getGlobalBounds().height;
            dy = 0;
            on_ground = true;
        }

        sprite.setPosition(hitbox.left, hitbox.top);

        frame += 0.008f * time; // Animation speed
        if (frame >= 8) {
            frame = 0;
        }

        /*animation*/
        if (dx > 0) {
            sprite.setTextureRect(sf::IntRect(width * (int)frame, 0, width, height));
        }
        if (dx < 0) {
            sprite.setTextureRect(sf::IntRect(width * ((int)frame + 1), 0, -width, height));
        }

        dx = 0;
    }
}