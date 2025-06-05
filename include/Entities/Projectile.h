#pragma once
#include "Entities/Entity.h"
#include "Utility/Texture.h"

namespace Entities {
    class Projectile : public Entity
    {
    private:
        float speed;
        bool direction; //true for right, false for left 
        float dx, dy;

    public:
        Projectile(Texture::ID id, int sprite_width, int sprite_height);
        Projectile();
        virtual ~Projectile();

        void update();
        void save();

        void setSpeed(float newSpeed);
        void setDirection(float newDirection);
        void setDx(float x);
        void setDy(float y);

        const sf::FloatRect getGlobalHitbox() const;

        void shoot(float startX, float startY, bool dir);
        void moveHitboxSprite(float dx, float dy);
    };
}