#pragma once
#include "Entities/Entity.h"
#include "Entities/Characters/Character.h"
#include "Entities/Obstructable.h"

#include "Utility/Texture.h"

namespace Entities {
    class Obstacle : public Entity, public Obstructable
    {
    public:
        Obstacle(const Texture::ID id, const int sprite_width, const int sprite_height, const EntityType type);
        Obstacle();
        virtual ~Obstacle();

        void nonDamageCollision(Character* character);

        virtual void save() override {}
        virtual void update() {};
        virtual void obstruct(Entities::Character* character) = 0;

        enum class ObstacleType {
            None = -1,

            Platform,
            Spike,
            Saw
        };
    };
}