#pragma once
#include "Entities/Entity.h"
#include "Entities/Characters/Character.h"

#include "Utility/Texture.h"

namespace Entities {
    class Obstacle : public Entity
    {
    protected:
        const bool isHarmful;

    public:
        Obstacle(const Texture::ID id, const int sprite_width, const int sprite_height, const EntityType type, const bool harmful);
        Obstacle();
        virtual ~Obstacle();

        virtual void save() = 0;
        virtual void exec() = 0;
        virtual void obstruct(Entities::Character* character) = 0;

        void saveDataBuffer();
        void damageCollision(Character* character);
    };
}