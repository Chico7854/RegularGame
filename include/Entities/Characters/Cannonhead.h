#pragma once
#include "Managers/CollisionManager.h"
#include "Enemy.h"
#include "Player.h"
#include "Entities/Projectile.h"
#include "../EntityList.h"
#include "Utility/Texture.h"


namespace Entities {
    class Cannonhead : public Enemy {
    private:
        bool direction; // true for right, false for left
        List::EntityList* pEntityList;
        float reloadTime;
        float dtime;

    public:     
        Cannonhead();
        virtual ~Cannonhead();

        void damage(Player* player) override;
        void save() override;
        void exec() override;

        void setBallDirection();
        void shoot();
        
        void setEntityList(List::EntityList* entityList);
        void setDtime(const float dt);
        void setDirection(const bool d);
        void setReloadTime(const float reloadT);
        const float getReloadTime() const;
        const bool getDirection() const;
        const float getDtime() const;
    };
}

