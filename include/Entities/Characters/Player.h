#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"
#include "Utility/Texture.h"

namespace Entities {
    class Player : public Character {
        private:
            bool on_ground;

        public:
            Player() {}
            Player(Texture::ID id, const int width, const int height);
            virtual ~Player() {}

            void run() override;
            void save() override;
            void update(float time) override;

            void keyboardInput(int playerNumber);
            bool getOnGround() { return on_ground; }
    };
}