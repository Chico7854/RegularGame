#include "Entities/Characters/Player.h"
#include "Utility/Constants.h"

namespace Entities {
    Player::Player(Texture::ID id, const int width, const int height):
        Character(id, width, height, EntityType::Player)
    {
    }

    void Player::run()
    {
    }

    void Player::save()
    {
    }

    void Player::update()
    {
        dy += Constants::GRAVITY;
        moveHitboxSprite(dx, dy);
        if (!isHurt) {
            dx = 0;
        }

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
    }
}