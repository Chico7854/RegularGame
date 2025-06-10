#pragma once
#include "Entities/Characters/Enemy.h"

namespace Entities {
    class Boss : public Enemy {
        private:
            const int bloodDamage;

        public:
            Boss();
            ~Boss();

            const int getBloodDamage() const;
    };
}


