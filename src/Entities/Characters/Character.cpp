#include "Entities/Characters/Character.h"

namespace Entities {
    Character::Character(Texture::ID id, const int width, const int height):
        Entity(id, width, height), 
        lives(0),
        speed(10.f),
        dx(0.f),
        dy(0.f)
    {}

    Character::Character(): Entity(), lives(-1), speed(0), dx(-1.f), dy(0.f) {}

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

    void Character::setSpeed(float s) {
        speed = s;
    }

    void Character::setDx(float x) {
        dx = x;
    }

    void Character::setDy(float y) {
        dy = y;
    }
}