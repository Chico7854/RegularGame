#pragma once
#include "Entities/Entity.h"
#include "Utility/Texture.h"
#include "Entities/Characters/Character.h"
#include "Entities/Characters/Player.h"

namespace Entities {
    class Projectile : public Entity
    {
    private:
        bool direction; //true for right, false for left 
        float dx, dy;
        bool active;
        const int projectileDamage;

    public:
        Projectile(Texture::ID id, int sprite_width, int sprite_height);
        Projectile();
        virtual ~Projectile();

        void exec();
        void save();
        
        void setInitPosition(float x, float y);
        void moveHitboxSprite(float dx, float dy);
        void obstruct(Character* character);

        void setActive(bool act) {this->active = act; }
        bool isActive() const { return active; }
        void setDirection(bool dir) { direction = dir; }
        void setDx(float dx) { this->dx = dx; }
        void setDy(float dy) { this->dy = dy; }
    };
}