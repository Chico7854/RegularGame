#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Utility/Texture.h"
#include "Entities/Projectile.h"
#include "../EntityList.h"

namespace Entities {
    class Cannonhead : public Enemy {
    private:
        bool direction; // true for right, false for left
        List::EntityList* projectileList;
        int cont_balls;
        float dtime;//Gambiarra, maybe add clock on main loop after

    public:     
        Cannonhead(Texture::ID id, int width, int height);
        Cannonhead(){}
        virtual ~Cannonhead();

        void run() override;
        void save() override;
        void exec() override;

        void setBallDirection();
        void shoot();
        void setProjectileList();
    };
}

