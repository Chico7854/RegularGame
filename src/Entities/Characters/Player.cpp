#include "Entities/Characters/Player.h"

namespace Entities {
    Player::Player(Texture::ID id, const int width, const int height):
        Character(id, width, height),
        onGround(true)
    {}

    void Player::run()
    {
    }

    void Player::save()
    {
    }

    void Player::update(float time)
    {

        if (!onGround) {
            dy = dy + 0.0006 * time; // Jump height calculation
        }

        onGround = false;

        if (sprite.getGlobalBounds().top > ground - sprite.getGlobalBounds().height) {
            dy = 0;
            onGround = true;
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

    const bool Player::getOnGround() const {
        return onGround;
    }
}