#include "Entities/Characters/Player.h"

namespace Entities {
    Player::Player(Texture::ID id, const int width, const int height):
        Character(id, width, height),
        on_ground(true)
    {}

    void Player::run()
    {
    }

    void Player::save()
    {
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

        if (!on_ground) {
            dy = dy + 0.0006 * time; // Jump height calculation
        }

        on_ground = false;

        if (sprite.getGlobalBounds().top > ground - sprite.getGlobalBounds().height) {
            dy = 0;
            on_ground = true;
        }

        sprite.move(dx, dy);

        // frame += 0.008f * time; // Animation speed
        // if (frame >= 8) {
        //     frame = 0;
        // }

        // /*animation*/
        // if (dx > 0) {
        //     sprite.setTextureRect(sf::IntRect(width * (int)frame, 0, width, height));
        // }
        // if (dx < 0) {
        //     sprite.setTextureRect(sf::IntRect(width * ((int)frame + 1), 0, -width, height));
        // }

        dx = 0;
    }
}