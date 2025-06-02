#pragma once
#include <vector>
#include <list>
#include <set>

#include "Entities/Characters/Enemy.h"
#include "Entities/Obstacles/Obstacle.h"
#include "Entities/Characters/Player.h"

namespace Manager {
    class CollisionManager {
        private:
            std::vector<Entities::Enemy*> enemies;
            std::list<Entities::Obstacle*> obstacles;
            //TODO: Set for porjectiles
            Entities::Player* player;

            static CollisionManager* pSelf;
            CollisionManager();

        public:
            ~CollisionManager();
            static CollisionManager* getCollisionManager();

            void appendEnemy(Entities::Enemy* enemy);
            void appendObstacle(Entities::Obstacle* obstacle);
            void setPlayer(Entities::Player* p);
            void verifyCollision(std::pair<Entities::Entity*, Entities::Entity*> entities);

        private:
    };
}