#pragma once
#include "Entities/Obstacles/Obstacle.h"
#include "Entities/Characters/Character.h"

namespace Entities {
    class DamageObstacle : public Obstacle {
        private:
            const int damage;

        public:
            DamageObstacle(const Texture::ID id, const int sprite_width, const int sprite_height, const EntityType type);
            DamageObstacle();
            ~DamageObstacle();

            void damageCollision(Character* character);
            void obstruct(Character* character) override;
    };
}