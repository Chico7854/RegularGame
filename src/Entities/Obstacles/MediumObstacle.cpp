#include "Entities/Obstacles/MediumObstacle.h"
#include "Utility/Constants.h"

namespace Entities
{
    MediumObstacle::MediumObstacle(Texture::ID id, int sprite_width, int sprite_height):
        Obstacle(id, sprite_width, sprite_height, EntityType::Spike),
        damage(10)
    {}

    MediumObstacle::MediumObstacle() {}

    MediumObstacle::~MediumObstacle() {}

    void MediumObstacle::obstruct(Entities::Character* character) {
        if (character->getType() == EntityType::Player) {
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
            }
        }
        else {
            nonDamageCollision(character);
        }
    }
}
