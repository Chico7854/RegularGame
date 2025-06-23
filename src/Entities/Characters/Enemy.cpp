#include "Entities/Characters/Enemy.h"

namespace Entities {
    Enemy::Enemy(const Texture::ID id, const int sprite_width, const int sprite_height, const EntityType type):
        Character(id, sprite_width, sprite_height, type),
        evilness((rand() % 5) + 1)
    {
        speed = Constants::SPEED / (6 - evilness);      //attribute based on evilness
        dx = speed;
        lifes = evilness;
    }

    Enemy::Enemy(): 
        evilness(-10000) 
    {}

    Enemy::~Enemy() {}

    const int Enemy::getEvilness() const {
        return evilness;
    }

    void Enemy::setEvilness(const int evilnessValue) {
        evilness = evilnessValue;
    }

    void Enemy::changeDirectionOnPlatform() {
        if (!isHurt) {
            dx *= -1;
            moveHitboxSprite(dx, 0);
        }
    }

    json Enemy::saveDataBuffer() {
        json data = Character::saveDataBuffer();
        data["evilness"] = evilness;
        return data;
    }
}