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


            void setPlayer(Player* p);
            void setDtime(const float dt);
            void setInRange(const bool inrg);
            const int getBloodDamage() const;

            void setDistance();
            void setDirection();
            void jump();
            void changeDirectionOnPlatform() override;
            void damage(Player* player) override;
            void save() override;
            void exec() override;
    };
}


