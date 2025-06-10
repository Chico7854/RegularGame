#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Entities/Obstacles/Platform.h"

#include "Utility/Texture.h"

namespace Entities {
    class Youkai : public Enemy {
        private:
            const int collisionDamage;

        public:
            Youkai(Texture::ID id, int width, int height);
            Youkai();
            virtual ~Youkai();

            void run() override;
            void save() override;
            void update() override;
    };
}
