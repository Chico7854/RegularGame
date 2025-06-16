#include "Entities/Obstacles/Spike.h"
#include "Utility/Constants.h"

namespace Entities
{
    Spike::Spike(Texture::ID id, int sprite_width, int sprite_height):
        Obstacle(id, sprite_width, sprite_height, EntityType::Spike, true),
        damage(10)
    {}

    Spike::Spike() {}

    Spike::~Spike() {}

    void Spike::obstruct(Character* character) {
		if (character->getType() == EntityType::Player) {
            damageCollision(character);
        }
        else {
            sf::FloatRect intersectionRect;

            const sf::FloatRect charCoordinates = character->getGlobalHitbox();
            const sf::FloatRect obstacleCoordinates = getGlobalHitbox();

            if (charCoordinates.intersects(obstacleCoordinates, intersectionRect)) {
                float xOverlap = intersectionRect.width;
                float yOverlap = intersectionRect.height;

                /*Check vertical collision*/
                if (yOverlap <= xOverlap) {
                    if ((character->getDy() >= 0) && (charCoordinates.top < obstacleCoordinates.top)) {
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
                    if (character->getType() != EntityType::Player) {
                        character->setDx(character->getDx() * -1);
                    }
                }
            }
        }
	}
}
