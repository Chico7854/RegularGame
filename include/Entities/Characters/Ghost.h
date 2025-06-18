#pragma once
#include "Entities/Characters/Enemy.h"

namespace Entities {
    class Ghost : public Enemy {
        private:
            const int bloodDamage;

        public:
            Ghost();
            ~Ghost();

            const int getBloodDamage() const;
    };
}


