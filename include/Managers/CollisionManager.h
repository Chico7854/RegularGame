#pragma once
#include <vector>
#include <list>
#include <set>

#include "Entities/Characters/Enemy.h"
#include "Entities/Characters/Character.h"
#include "Entities/Obstacles/Obstacle.h"
#include "Entities/Obstacles/Platform.h"
#include "Entities/Characters/Player.h"
#include "Entities/Projectile.h"
#include "Entities/EntityList.h"

namespace Manager {
    class CollisionManager {
        private:
            std::vector<Entities::Enemy*> enemies;
            std::list<Entities::Obstacle*> obstacles;
            std::vector<Entities::Projectile*> balls;
            //TODO: Set for porjectiles
            Entities::Player* p1;

            static CollisionManager* pSelf;
            CollisionManager();

        public:
            ~CollisionManager();
            static CollisionManager* getCollisionManager();

            void appendEnemy(Entities::Enemy* enemy);
            void appendObstacle(Entities::Obstacle* obstacle);
            void appendProjectile(Entities::Projectile* projectile);
            void setPlayer(Entities::Player* p);

            void exec();

        private:
            const bool verifyCollision(Entities::Entity* ent1, Entities::Entity* ent2) const;
            void applyPlayerObstacleCollisions();
            void applyPlayerEnemiesCollisions();
            void applyPlayerProjectilesCollisions();
            void applyPlayerBorderCollision();
            void applyEnemiesObstaclesCollision();
            void applyProjectileCollisions();
            void verifyDelete();
    };
}