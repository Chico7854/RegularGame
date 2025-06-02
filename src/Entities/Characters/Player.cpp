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
            dy += 6.f;
        }

        onGround = false;

        if (sprite.getGlobalBounds().top + sprite.getGlobalBounds().height + dy > ground) {
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