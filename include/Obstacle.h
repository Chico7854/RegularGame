#pragma once
#include "Entity.h"

class Obstacle : public Entity
{
protected:
    bool harmful;
public:
    Obstacle() : harmful(false) {}
    Obstacle(sf::Texture& texture, int sprite_width, int sprite_height): Entity(sprite_width, sprite_height)
    {
        sprite.setTexture(texture);
        hitbox = sf::FloatRect(0, 0, sprite_width, sprite_height);
    }
    virtual ~Obstacle() {}
    virtual void run() override {}
    virtual void save() override {}
    void setHarmful(bool harmful) { this->harmful = harmful; }
    bool isHarmful() const { return harmful; }
};