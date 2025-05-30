#include "../include/Enemy.h"

Enemy::Enemy(sf::Texture& texture, int sprite_width, int sprite_height) :
    ground(600),
    frame(0),
    speed(0.3f),
    width(sprite_width),
    height(sprite_height),
    dx(0.1f),
    dy(0.1f)
{
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, height));
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

