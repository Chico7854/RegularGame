#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Ent.h"
#include "Utility/Constants.h"

#include "Utility/Texture.h"

namespace Entities {
    enum class EntityType {
        None = 0,

        Player,
        Youkai,
        Floor,
        Platform,
        Spike,
        Saw,
        Ball,
        Cannonhead
    };

    class Entity : public Ent
    {
    protected:
        sf::Vector2f initialPosition;
        const EntityType type;
        int ground;
        bool toDelete;

    public:
        Entity(Texture::ID id, int width, const int height, EntityType t);
        Entity();
        virtual ~Entity();

        virtual void update() = 0;
        virtual void save() = 0;

        const EntityType getType() const;
        bool getToDelete() const;
        void setToDelete(bool del);
    };
}