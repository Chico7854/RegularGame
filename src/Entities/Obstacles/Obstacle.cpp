#include "Entities/Obstacles/Obstacle.h"

namespace Entities {
    Obstacle::Obstacle(Texture::ID id, int sprite_width, int sprite_height):
        Entity(id, sprite_width, sprite_height, EntityType::Obstacle)
    {}

    Obstacle::Obstacle() {}

    Obstacle::~Obstacle() {}

    void Obstacle::nonDamageCollision(Character* character) {
        sf::FloatRect intersectionRect;

        const sf::FloatRect charCoordinates = character->getGlobalHitbox();
        const sf::FloatRect obstacleCoordinates = getGlobalHitbox();

        if (charCoordinates.intersects(obstacleCoordinates, intersectionRect)) {
            float xOverlap = intersectionRect.width;
            float yOverlap = intersectionRect.height;

            /*Check vertical collision*/
            if (yOverlap < xOverlap) {
                if (character->getDy() >= 0) {
                    yOverlap *= -1;
                    character->setOnGround(true);
                    character->setIsHurt(false);
                }
                character->moveHitboxSprite(0, yOverlap);
                character->setDy(0.f);
            } 
            /*Horizontal collision*/
            else {
                if (obstacleCoordinates.left > charCoordinates.left)
                    xOverlap *= -1;
                character->moveHitboxSprite(xOverlap, 0);
                if (character->getType() == EntityType::Enemy) {
                    character->setDx(character->getDx() * -1);
                }
            }
        }
    }
}