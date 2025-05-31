#include "../include/EasyEnemy.h"
#include "Utility/Constants.h"
#include "../include/Enemy.h"

EasyEnemy::EasyEnemy(sf::Texture& texture, int width, int height):
    Enemy(texture, width, height)
{}

void EasyEnemy::setInitialPosition(sf::Vector2f pos)
{
    initialPosition = pos;
    hitbox.left = pos.x;
    hitbox.top = pos.y;
    sprite.setPosition(pos);
}

void EasyEnemy::run()
{
}

void EasyEnemy::save()
{
}

void EasyEnemy::move()
{
}

void EasyEnemy::update(float time)
{
    hitbox.left += dx * time;
    if (hitbox.left < 0 || hitbox.left + width > Constants::WINDOW_WIDTH) {
        dx = -dx; // Reverse direction if hits borders
    }

    frame += 0.008f * time; // Animation speed
    if (frame >= 6) {
        frame = 0;
    }

    if (dx > 0) {
        sprite.setTextureRect(sf::IntRect(width * (int)frame, 0, width, height));
    }
    if (dx < 0) {
        sprite.setTextureRect(sf::IntRect(width * ((int)frame + 1), 0, -width, height));
    }

    sprite.setPosition(hitbox.left, hitbox.top);
}