#pragma once
#include "Entities/Entity.h"
#include "Utility/Texture.h"
#include "Entities/Characters/Character.h"
#include "Entities/Characters/Player.h"

namespace Entities {
    class Projectile : public Entity
    {
    private:
        float speed;
        bool direction; //true for right, false for left 
        float dx, dy;
        bool active;

    public:
        Projectile(Texture::ID id, int sprite_width, int sprite_height);
        Projectile();
        virtual ~Projectile();

        void update();
        void save();
        
        const sf::FloatRect getGlobalHitbox() const;
        void setInitPosition(float x, float y);
        void moveHitboxSprite(float dx, float dy);
        void obstruct(Character* character);

        void setDx(float dx) { this->dx = dx; }
        void setDy(float dy) { this->dy = dy; }
    };
}