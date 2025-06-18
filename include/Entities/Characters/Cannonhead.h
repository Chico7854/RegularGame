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
        List::EntityList* pEntityList;
        int cont_balls;
        float dtime;//Gambiarra, maybe add clock on main loop after

    public:     
        Cannonhead();
        virtual ~Cannonhead();

        void damage(Player* player) override;
        void save() override;
        void exec() override;

        void setBallDirection();
        void shoot();
        void setEntityList();
    };
}

