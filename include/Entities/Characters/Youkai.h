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
            Youkai();
            virtual ~Youkai();

            void damage(Player* player) override;
            void save() override;
            void exec() override;
    };
}
