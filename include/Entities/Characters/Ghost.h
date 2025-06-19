#pragma once
#include "Enemy.h"
#include "Utility/Texture.h"
#include "Player.h"

namespace Entities {
    class Ghost : public Enemy {
        private:
            const int bloodDamage;
            float dtime;
            bool direction; //True for right
            Player* p1;

        public:
            Ghost();
            ~Ghost();

            const int getBloodDamage() const;

            void setPlayer(Player* p);
            void setDirection();
            void jump();
            void damage(Player* player) override;
            void save() override {}
            void exec() override;
    };
}


