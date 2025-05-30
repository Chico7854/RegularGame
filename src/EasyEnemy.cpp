#include "../include/EasyEnemy.h"

#include "../include/Enemy.h"

EasyEnemy::EasyEnemy(sf::Texture& texture, int sprite_width, int sprite_height) :
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
    if (hitbox.left < 0 || hitbox.left + width > window->getSize().x) {
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