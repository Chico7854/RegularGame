#include "Entities/Obstacles/Saw.h"
#include "Utility/Constants.h"

namespace Entities {
	Saw::Saw():
		Obstacle(Texture::Saw, Constants::SAW_WIDTH, Constants::SAW_HEIGHT, EntityType::Saw, true), 
		damage(2), 
        dx(Constants::SPEED),
        dy(0.f),
        moving_area(128.f),
        dx_sum(0.f)
	{}

	Saw::~Saw() {}

    void Saw::save() {
        saveDataBuffer();
    }

    void Saw::exec() {
        moveSaw();
    }

	void Saw::obstruct(Character* character) {
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

    void Saw::setDx(const float DX) {
        dx = DX;
    }

    void Saw::setDy(const float DY) {
        dy = DY;
    }

    void Saw::setDx_sum(const float dxsum) {
        dx_sum = dx_sum;
    }

    const float Saw::getDamage() const {
        return damage;
    }

    void Saw::saveDataBuffer() {
        json data = Obstacle::saveDataBuffer();
        data["dx"] = dx;
        data["dy"] = dy;
        data["dx_sum"] = dx_sum;
        buffer << data.dump(4) << ",\n";
        buffer.flush();
    }
}