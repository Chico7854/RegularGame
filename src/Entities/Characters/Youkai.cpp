#include "Entities/Characters/Youkai.h"
#include "Utility/Constants.h"
#include "Entities/Characters/Enemy.h"

namespace Entities {
    Youkai::Youkai():
        Enemy(Texture::Youkai, Constants::YOUKAI_WIDTH, Constants::YOUKAI_HEIGHT, EntityType::Youkai),
        scratchDamage(evilness)
    {}

    Youkai::~Youkai() {}

    void Youkai::setScratchDamage(const int damage) {
        scratchDamage = damage;
    }

    const int Youkai::getScrathDamage() const {
        return scratchDamage;
    }

    void Youkai::damage(Player* player) {
        player->setLife(player->getLife() - scratchDamage);
    }

    void Youkai::save()
    {
        json data = Enemy::saveDataBuffer();
        data["scratchDamage"] = scratchDamage;
        buffer << data.dump(4) << ",\n";
        buffer.flush();
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