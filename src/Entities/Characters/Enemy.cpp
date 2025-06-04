#include "Entities/Characters/Enemy.h"

namespace Entities {
    Enemy::Enemy(Texture::ID id, int sprite_width, int sprite_height):
        Character(id, sprite_width, sprite_height, Constants::Enemy),
        ground(600)
    {
        dx = speed; //GAMBIARRA
    }

    void Enemy::run()
    {
    }

    void Enemy::save()
    {
    }

}