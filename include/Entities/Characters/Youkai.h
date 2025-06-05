#pragma once
#include "Enemy.h"
#include "Player.h"

#include "Utility/Texture.h"

namespace Entities {
    class Youkai : public Enemy {
        private:

        public:
            Youkai() {}
            Youkai(Texture::ID id, int width, int height);
            virtual ~Youkai();

            void run() override;
            void save() override;
            void update() override;
    };
}
