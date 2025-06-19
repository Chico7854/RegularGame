#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"
#include "Utility/Texture.h"

namespace Entities {
    class Player : public Character {
        private:
            const int swordDamage;

        public:
            Player(Texture::ID id, const int width, const int height);
            Player();
            virtual ~Player();

            sf::Vector2f getPosition();
            void save() override;
            void exec() override;

        private:
            void checkKeyboardInput();
    };
}