#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Character.h"

#include "Utility/Texture.h"
#include "Utility/Constants.h"

namespace Entities {
    class Enemy;

    class Player : public Character {
        private:
            const float attack_radius;
            bool isAttacking;

        public:
            Player(Texture::ID id, const int width, const int height);
            Player();
            virtual ~Player();

            sf::Vector2f getPosition();
            void save() override;
            void exec() override;
            void collide(Enemy* pEnemy);

        private:
            void checkKeyboardInput();
    };
}