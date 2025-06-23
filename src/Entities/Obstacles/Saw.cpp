#include "Entities/Obstacles/Saw.h"
#include "Utility/Constants.h"

namespace Entities {
	Saw::Saw():
		Obstacle(Texture::Saw, Constants::SAW_WIDTH, Constants::SAW_HEIGHT, EntityType::Saw, true), 
		damage(10.f), 
        dx(Constants::SPEED),
        dy(0.f),
        moving_area(128.f),
        dx_sum(0.f)
	{}

	Saw::~Saw() {}

    void Saw::save() {
        Obstacle::saveDataBuffer();
        saveDataBuffer();
    }

    void Saw::exec() {
        moveSaw();
    }

	void Saw::obstruct(Character* character) {
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

    void Saw::moveHitboxSprite(float dx, float dy) {
        sprite.move(dx, dy);
        updateHitbox();
    }

    void Saw::moveSaw(){
        if (dx_sum > moving_area) {
            dx *= -1; 
            dx_sum = 0;
        } else{
            if (dx > 0)
                dx_sum += dx;
            else
                dx_sum += dx*(-1);
        }
        moveHitboxSprite(dx, dy);
    }

    const float Saw::getDamage() const {
        return damage;
    }

    void Saw::saveDataBuffer() {
        buffer << " " << dx << " " << dy << " " << dx_sum << std::endl;
    }
}