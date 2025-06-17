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
            void setSpeed(const float s);
            void setDx(const float x);
            void setDy(const float y);
            void setOnGround(const bool o);
            const bool getOnGround() const;
            void setIsHurt(const bool hurt);
            const bool getIsHurt() const;
            void moveHitboxSprite(const float dx, const float dy);

            virtual void save() = 0;
            virtual void exec() = 0;
    };
}