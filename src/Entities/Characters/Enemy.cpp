#include "Entities/Characters/Enemy.h"

namespace Entities {
    Enemy::Enemy(const Texture::ID id, const int sprite_width, const int sprite_height, const EntityType type):
        Character(id, sprite_width, sprite_height, type),
        evilness(rand() % 10)
    {
        dx = speed; //GAMBIARRA
    }

    Enemy::Enemy(): 
        evilness(-1) 
    {}

    Enemy::~Enemy() {}

    const int Enemy::getEvilness() const {
        return evilness;
    }

    void Enemy::save()
    {
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