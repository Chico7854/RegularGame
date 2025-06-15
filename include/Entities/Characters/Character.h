#pragma once

#include "Entities/Entity.h"
#include "Utility/Texture.h"

namespace Entities {
    class Character : public Entity {
        protected:
            int lives;
            float speed;
            float dx, dy;
            bool onGround, isHurt;

        public:
            Character();
            Character(Texture::ID id, const int width, const int height, EntityType type);
            ~Character();

            const float getSpeed() const;
            const float getDx() const;
            const float getDy() const;
            void setSpeed(float s);
            void setDx(float x);
            void setDy(float y);
            void setOnGround(bool o);
            const bool getOnGround() const;
            void setIsHurt(bool hurt);
            const bool getIsHurt() const;
            void moveHitboxSprite(float dx, float dy);

            virtual void run() = 0;
            virtual void save() = 0;
            virtual void exec() = 0;
    };
}