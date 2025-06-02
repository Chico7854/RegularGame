#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ent.h"
#include "Utility/Texture.h"

namespace Entities {
    class Entity : public Ent
    {
    protected:
        sf::FloatRect hitbox;
        sf::Vector2f initialPosition;
        int ground;

    public:
        Entity() {}
        Entity(Texture::ID id, int width, const int height): Ent(id, width, height), ground(600/*floor height, declared statcally, chenge after*/) {}
        virtual ~Entity() {}

        virtual void update(float time) = 0;
        virtual void run() = 0;          
        virtual void save() = 0;         

        sf::FloatRect getHitbox() { return hitbox; }
    };
}