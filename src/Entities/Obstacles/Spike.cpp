#include "Entities/Obstacles/Spike.h"
#include "Utility/Constants.h"

namespace Entities
{
    Spike::Spike():
        Obstacle(Texture::Spike, Constants::SPIKE_WIDTH, Constants::SPIKE_HEIGHT, EntityType::Spike, true),
        damage(1)
    {}

    Spike::~Spike() {}

    void Spike::save() {
        json data = Obstacle::saveDataBuffer();
        buffer << data.dump(4) << ",\n";
        buffer.flush();
    }

    void Spike::obstruct(Character* character) {
		if (character->getType() == EntityType::Player) {
            damageCollision(character);
            character->setLife(character->getLife() - damage);
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

    const int Spike::getDamage() const {
        return damage;
    }
}
