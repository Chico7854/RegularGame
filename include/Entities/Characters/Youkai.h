#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Entities/Obstacles/Platform.h"

#include "Utility/Texture.h"

namespace Entities {
    class Youkai : public Enemy {
        private:
            int scratchDamage;

        public:
            Youkai();
            virtual ~Youkai();

            void setScratchDamage(const int damage);
            const int getScrathDamage() const;

            void damage(Player* player) override;
            void save() override;
            void exec() override;
    };
}
