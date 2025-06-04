#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Character.h"
#include "Player.h"

#include "Utility/Texture.h"

namespace Entities {
    class Enemy : public Character {
        protected:
            int ground;

        public:
            Enemy() {}
            Enemy(Texture::ID id, int sprite_width, int sprite_height);
            virtual ~Enemy() {}
            virtual void setInitialPosition(sf::Vector2f pos){}
            void run() override;
            void save() override;
            virtual void update(float time) {}
            virtual void obstruct(Player* player) = 0;
    };
}