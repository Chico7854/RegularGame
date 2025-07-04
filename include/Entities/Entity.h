#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

#include "Ent.h"
#include "Utility/Constants.h"

#include "Utility/Texture.h"

using json = nlohmann::json;

namespace Entities {
    enum class EntityType {
        None = 0,

        Player,
        Youkai,
        Platform,
        Spike,
        Saw,
        Ball,
        Cannonhead,
        Ghost
    };

    class Entity : public Ent
    {
    protected:
        const EntityType type;
        sf::FloatRect hitbox;
        bool toDelete;
        std::ofstream buffer;

    public:
        Entity(Texture::ID id, int width, const int height, EntityType t);
        Entity();
        virtual ~Entity();

        virtual void exec() = 0;
        virtual void save() = 0;

        /*Sprite and Hitbox*/
        sf::FloatRect getGlobalHitbox() const;
        void setHitbox(const sf::FloatRect& hb);
        void updateHitbox();
        void setSpritePosition(float x, float y);

        const EntityType getType() const;
        bool getToDelete() const;
        void setToDelete(bool del);

    protected:
        json saveDataBuffer();
    };
}