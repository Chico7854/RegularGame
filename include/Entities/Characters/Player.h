#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Character.h"

#include "Utility/Texture.h"
#include "Utility/Constants.h"

namespace States {
    class Stage;
}

namespace Entities {
    class Enemy;

    class Player : public Character {
        private:
            const float attack_radius;
            bool isAttacking;
            States::Stage* pStage;

        public:
            Player(Texture::ID id, const int width, const int height);
            Player();
            virtual ~Player();

            sf::Vector2f getPosition();
            void save() override;
            void exec() override;
            void collide(Enemy* pEnemy);

            void setStage(States::Stage* pSt);
            States::Stage* getStage();

        private:
            void checkKeyboardInput();
    };
}