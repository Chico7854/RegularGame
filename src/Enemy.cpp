#include "../include/Enemy.h"

Enemy::Enemy(Texture::ID id, int sprite_width, int sprite_height):
    Character(id, sprite_width, sprite_height),
    ground(600),
    frame(0),
    speed(0.3f),
    dx(0.1f),
    dy(0.1f)
{
    sprite.setPosition(0, ground - height);
    hitbox = sf::FloatRect(0, ground - height, width, height);
}

void Enemy::run()
{
}

void Enemy::save()
{
}

void Enemy::move()
{
}

