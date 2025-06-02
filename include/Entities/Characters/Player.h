#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"
#include "Utility/Texture.h"

namespace Entities {
    class Player : public Character {
        private:
            bool onGround;

        public:
            Player() {}
            Player(Texture::ID id, const int width, const int height);
            virtual ~Player() {}

            void run() override;
            void save() override;
            void update(float time) override;

            const bool getOnGround() const;
    };
}