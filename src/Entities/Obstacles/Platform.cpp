#include "Entities/Obstacles/Platform.h"

namespace Entities {
    Platform::Platform(Texture::ID id, int sprite_width, int sprite_height):
        Obstacle(id, sprite_width, sprite_height)
    {}

    Platform::Platform(): Obstacle() {}

    Platform::~Platform() {}

    void Platform::obstruct(Entities::Character* character) {
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
            }
        }
    }
}