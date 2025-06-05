#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Ent.h"
#include "Utility/Constants.h"

#include "Utility/Texture.h"

namespace Entities {
    class Entity : public Ent
    {
    protected:
        sf::Vector2f initialPosition;
        const Constants::TYPE type;
        int ground;

    public:
        Entity(Texture::ID id, int width, const int height, Constants::TYPE t);
        Entity();
        virtual ~Entity();

        virtual void update() = 0;
        virtual void save() = 0;

        const Constants::TYPE getType() const;
    };
}