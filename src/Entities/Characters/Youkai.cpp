#include "Entities/Characters/Youkai.h"
#include "Utility/Constants.h"
#include "Entities/Characters/Enemy.h"

namespace Entities {
    Youkai::Youkai():
        Enemy(Texture::Youkai, Constants::YOUKAI_WIDTH, Constants::YOUKAI_HEIGHT, EntityType::Youkai),
        collisionDamage(evilness)
    {}

    Youkai::~Youkai() {}

    void Youkai::damage(Player* player) {
        player->setLife(player->getLife() - 1);
    }

    void Youkai::save()
    {
        Enemy::saveDataBuffer();
        buffer << std::endl;
    }

    void Youkai::exec()
    {
        dy += Constants::GRAVITY;
        if (sprite.getGlobalBounds().left + dx < 0 || sprite.getGlobalBounds().left + sprite.getGlobalBounds().width + dx > Constants::MAP_WIDTH) {
            dx = -dx; // Reverse direction if hits borders
        }
        moveHitboxSprite(dx, dy);

        if (isHurt) {
            sprite.setColor(sf::Color::Red);
        } else {
            sprite.setColor(sf::Color::White);
        }
    }
}