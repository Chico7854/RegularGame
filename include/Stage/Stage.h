#pragma once
#include "Ent.h"

#include "Entities/EntityList.h"
#include "Entities/Characters/Youkai.h"
#include "Managers/CollisionManager.h"
#include "Managers/EventManager.h"

namespace Stage {
    class Stage : public Ent {
        protected:
            List::EntityList charactersList;
            List::EntityList obstaclesList;
            Manager::CollisionManager* pCollisionManager;
            Entities::Player* player;

        public:
            Stage();
            ~Stage();

        protected:
            void createYoukai(const float x, const float y);
            void createPlatform(const float x, const float y);
            void createFloor();
            void createPlayer();

            // virtual void createEnemies() = 0;
            // virtual void createObstacle() = 0;

        public:
            virtual void createMap();
            void exec();
    };
}