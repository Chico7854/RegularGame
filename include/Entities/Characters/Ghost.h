#pragma once
#include "Enemy.h"
#include "Utility/Texture.h"
#include "Player.h"

namespace Entities {
    class Ghost : public Enemy {
        private:
            const int bloodDamage;
            float dtime;
            bool inRange;
            Player* p1;
            const float detection_range;
            float distanceFromPlayer;

        public:
            Ghost();
            ~Ghost();

            const int getBloodDamage() const;

            void setDistance();
            void setPlayer(Player* p);
            void setDirection();
            void jump();
            void changeDirectionOnPlatform() override;
            void damage(Player* player) override;
            void save() override {}
            void exec() override;
    };
}


