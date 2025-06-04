#include "Managers/CollisionManager.h"
#include "Utility/Constants.h"

namespace Manager {
    CollisionManager* CollisionManager::pSelf(nullptr);

    CollisionManager::CollisionManager():
        enemies(),
        obstacles(),
        p1(nullptr)
    {
        enemies.clear();
        obstacles.clear();
    }

    CollisionManager::~CollisionManager() {}

    CollisionManager* CollisionManager::getCollisionManager() {
        if (!pSelf) {
            pSelf = new CollisionManager();
        }
        return pSelf;
    }

    void CollisionManager::appendEnemy(Entities::Enemy* enemy) {
        if (enemy) {
            enemies.push_back(enemy);
        }
    }

    void CollisionManager::appendObstacle(Entities::Obstacle* obstacle) {
        if (obstacle) {
            obstacles.push_back(obstacle);
        }
    }

    void CollisionManager::setPlayer(Entities::Player* p) {
        if (p) {
            p1 = p;
        }
    }

    void CollisionManager::verifyCollisions() {
        std::list<Entities::Obstacle*>::iterator itObstacles = obstacles.begin();
        std::vector<Entities::Enemy*>::iterator itEnemies = enemies.begin();

        while(itObstacles != obstacles.end()) {
            if (*itObstacles) {
                (*itObstacles)->obstruct(p1);
            }
            itObstacles++;
        }

        while (itEnemies != enemies.end()) {
            if (*itEnemies) {
                (*itEnemies)->obstruct(p1);
            }
            itEnemies++;
        }
    }
}