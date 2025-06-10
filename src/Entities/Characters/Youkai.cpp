#include "Entities/Characters/Youkai.h"
#include "Utility/Constants.h"
#include "Entities/Characters/Enemy.h"

namespace Entities {
    Youkai::Youkai(const Texture::ID id, const int width, const int height):
        Enemy(id, width, height, EntityType::Youkai),
        collisionDamage(evilness)
    {}

    Youkai::Youkai():
        collisionDamage(-1)    
    {}

    Youkai::~Youkai() {}

    void Youkai::run()
    {
    }

    void Youkai::save()
    {
    }

    void Youkai::update()
    {
        /*GAMBIARRA*/
        dy += Constants::GRAVITY;
        if (sprite.getGlobalBounds().left + dx < 0 || sprite.getGlobalBounds().left + sprite.getGlobalBounds().width + dx > Constants::WINDOW_WIDTH) {
            dx = -dx; // Reverse direction if hits borders
        }
        moveHitboxSprite(dx, dy);

        // frame += 0.008f * time; // Animation speed
        // if (frame >= 6) {
        //     frame = 0;
        // }

        // if (dx > 0) {
        //     sprite.setTextureRect(sf::IntRect(width * (int)frame, 0, width, height));
        // }
        // if (dx < 0) {
        //     sprite.setTextureRect(sf::IntRect(width * ((int)frame + 1), 0, -width, height));
        // }
    }
}