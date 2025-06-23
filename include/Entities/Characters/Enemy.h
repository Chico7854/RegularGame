#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entities/Characters/Character.h"
#include "Entities/Characters/Player.h"
#include "Entities/Obstacles/Obstacle.h"

#include "Utility/Texture.h"

namespace Entities {
    class Enemy : public Character {
        protected:
            const int evilness;
        public:
            Enemy(const Texture::ID id, const int sprite_width, const int sprite_height, const EntityType type);
            Enemy();
            virtual ~Enemy();

            const int getEvilness() const;

            virtual void damage(Player* player) = 0;
            virtual void save() = 0;
            virtual void exec() = 0;

            virtual void changeDirectionOnPlatform();
            json saveDataBuffer();
    };
}