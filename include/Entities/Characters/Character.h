#pragma once

#include "Entities/Entity.h"
#include "Utility/Texture.h"

namespace Entities {
    class Character : public Entity {
        protected:
            int lifes;
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
            const bool getOnGround() const;
            const bool getIsHurt() const;
            const int getLife() const;
            void setSpeed(const float s);
            void setDx(const float x);
            void setDy(const float y);
            void setOnGround(const bool o);
            void setIsHurt(const bool hurt);
            void setLife(const int numLifes);

            void moveHitboxSprite(const float dx, const float dy);
            void saveDataBuffer();

            virtual void save() = 0;
            virtual void exec() = 0;
    };
}