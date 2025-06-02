#pragma once

#include "Enemy.h"
#include "Utility/Texture.h"

namespace Entities {
    class EasyEnemy : public Enemy {
        private:

        public:
            EasyEnemy() {}
            EasyEnemy(Texture::ID id, int width, int height);
            virtual ~EasyEnemy();
            void run() override;
            void save() override;
            void update(float time) override;
    };
}
