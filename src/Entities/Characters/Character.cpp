#include "Entities/Characters/Character.h"
#include "Utility/Constants.h"

namespace Entities {
    Character::Character(Texture::ID id, const int width, const int height, EntityType type):
        Entity(id, width, height, type),
        speed(Constants::SPEED),
        lifes(0),
        dx(0.f),
        dy(0.f),
        onGround(true),
        isHurt(false)
    {}

    Character::Character(): Entity(), lifes(-1), speed(0), dx(-1.f), dy(0.f) {}

    Character::~Character()
    {
    }

    const float Character::getSpeed() const {
        return speed;
    }

    const float Character::getDx() const {
        return dx;
    }

    const float Character::getDy() const {
        return dy;
    }

    const int Character::getLife() const {
        return lifes;
    }

    void Character::setSpeed(const float speedValue) {
        speed = speedValue;
    }

    void Character::setDx(float x) {
        dx = x;
    }

    void Character::setDy(float y) {
        dy = y;
    }

    void Character::setIsHurt(bool hurt) {
        isHurt = hurt;
    }

    const bool Character::getIsHurt() const {
        return isHurt;
    }

    void Character::setOnGround(bool o) {
        onGround = o;
    }

    const bool Character::getOnGround() const {
        return onGround;
    }

    void Character::setLife(const int numLifes) {
        lifes = numLifes;
    }

    void Character::moveHitboxSprite(float dx, float dy) {
        sprite.move(dx, dy);
        updateHitbox();
    }

    json Character::saveDataBuffer() {
        json data = Entity::saveDataBuffer();
        data["speed"] = speed;
        data["lifes"] = lifes;
        data["dx"] = dx;
        data["dy"] = dy;
        data["onGround"] = onGround;
        data["isHurt"] = isHurt;

        return data;
    }
}