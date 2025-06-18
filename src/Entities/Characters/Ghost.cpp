#include "Entities/Characters/Ghost.h"

namespace Entities {
    Ghost::Ghost():
        Enemy(Texture::Ghost, Constants::GHOST_WIDTH, Constants::GHOST_HEIGHT, EntityType::Ghost),
        bloodDamage(1)
    {}

    Ghost::~Ghost() {}

    const int Ghost::getBloodDamage() const {
        return bloodDamage;
    }

    void Ghost::damage(Player* player) {
        const sf::FloatRect charCoordinates = player->getGlobalHitbox();
        const sf::FloatRect obstacleCoordinates = getGlobalHitbox();


        if (charCoordinates.intersects(obstacleCoordinates)) {
            const float middlePointPlayer = charCoordinates.left + (charCoordinates.width / 2);
            const float middlePointEntity = obstacleCoordinates.left + (obstacleCoordinates.width / 2);

            const float playerDy = Constants::JUMP_SPEED / 1.5;
            float playerDx = Constants::SPEED * 2;

            if (middlePointPlayer < middlePointEntity) {
                playerDx *= -1;
            }

            player->setDy(playerDy);
            player->setDx(playerDx);
            player->setIsHurt(true);
            player->moveHitboxSprite(playerDx, playerDy);

            dx *= -1;
        }
    }
}