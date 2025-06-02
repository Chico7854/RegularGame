#pragma once

#include "Entities/Entity.h"
#include "Utility/Texture.h"

namespace Entities {
    class Character : public Entity {
        protected:
            int lives;
            float speed;
            float dx, dy;

        public:
            Character();
            Character(Texture::ID id, const int width, const int height);
            ~Character();

            virtual void run() = 0;
            virtual void save() = 0;
            virtual void update(float time) = 0;
    };
}