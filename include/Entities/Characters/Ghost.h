#pragma once
#include "Enemy.h"
#include "Utility/Texture.h"
#include "Player.h"

namespace Entities {
    class Ghost : public Enemy {
        private:
            const int bloodDamage;
            float dtime;
            bool jumpDirection; //True for right

        public:
            Ghost();
            ~Ghost();

            const int getBloodDamage() const;

            void setLandingSpot();
            void setJumpDirection();
            void jump();
            void damage(Player* player) override;
            void save() override {}
            void exec() override;
    };
}


