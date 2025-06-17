#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Character.h"
#include "Player.h"

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
            void obstruct(Character* character);

            virtual void save();
            virtual void exec() = 0;
    };
}