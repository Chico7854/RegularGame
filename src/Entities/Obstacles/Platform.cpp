#include "Entities/Obstacles/Platform.h"

namespace Entities {
    Platform::Platform():
        Obstacle(Texture::Platform, Constants::PLATFORM_WIDTH, Constants::PLATFORM_HEIGHT, EntityType::Platform, false),
        magicalForce(0.f)
    {}

    Platform::~Platform() {}

    void Platform::setMagicalForce(const float mf) {
        magicalForce = mf;
    }

    const float Platform::getMagicalForce() const {
        return magicalForce;
    }

    void Platform::obstruct(Entities::Character* character) {
        sf::FloatRect intersectionRect;

        const sf::FloatRect charCoordinates = character->getGlobalHitbox();
        const sf::FloatRect obstacleCoordinates = getGlobalHitbox();

        if (charCoordinates.intersects(obstacleCoordinates, intersectionRect)) {
            float xOverlap = intersectionRect.width;
            float yOverlap = intersectionRect.height;

            /*Horizontal collision*/
            if ((yOverlap > xOverlap) && (yOverlap == Constants::SCALE_TXT)) {
                if (obstacleCoordinates.left > charCoordinates.left)
                    xOverlap *= -1;
                character->moveHitboxSprite(xOverlap, 0);
                if (character->getType() != EntityType::Player) {
                    character->setDx(character->getDx() * -1);
                }
            }
            /*Vertical collision*/
            else {
                setMagicalForce(yOverlap);
                if ((character->getDy() >= 0) && (charCoordinates.top < obstacleCoordinates.top)) {
                    setMagicalForce(yOverlap * -1);
                    character->setOnGround(true);
                    character->setIsHurt(false);
                }
                character->moveHitboxSprite(0, magicalForce);
                character->setDy(0.f);
            } 
        }
    }
}