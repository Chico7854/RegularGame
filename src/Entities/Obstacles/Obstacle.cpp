#include "Entities/Obstacles/Obstacle.h"

namespace Entities {
    Obstacle::Obstacle(const Texture::ID id, const int sprite_width, const int sprite_height, const EntityType type, const bool harmful):
        Entity(id, sprite_width, sprite_height, type),
        isHarmful(harmful)
    {}

    Obstacle::Obstacle():
        isHarmful(false)
    {}

    Obstacle::~Obstacle() {}

    void Obstacle::saveDataBuffer() {
        Entity::saveDataBuffer();
    }

    void Obstacle::damageCollision(Character* character) {
        const sf::FloatRect charCoordinates = character->getGlobalHitbox();
        const sf::FloatRect obstacleCoordinates = getGlobalHitbox();


        if (charCoordinates.intersects(obstacleCoordinates)) {
            const float middlePointPlayer = charCoordinates.left + (charCoordinates.width / 2);
            const float middlePointEntity = obstacleCoordinates.left + (obstacleCoordinates.width / 2);

            const float dy = Constants::JUMP_SPEED / 1.5;
            float dx = Constants::SPEED * 2;

            if (middlePointPlayer < middlePointEntity) {
                dx *= -1;
            }

            character->setDy(dy);
            character->setDx(dx);
            character->setIsHurt(true);
            character->moveHitboxSprite(dx, dy);
        }
    }
}