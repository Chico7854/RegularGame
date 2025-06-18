#include "Managers/CollisionManager.h"
#include "Utility/Constants.h"

namespace Manager {
    CollisionManager* CollisionManager::pSelf(nullptr);

    CollisionManager::CollisionManager():
        enemies(),
        obstacles(),
        balls(),
        p1(nullptr)
    {
        enemies.clear();
        obstacles.clear();
        balls.clear();
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

    void CollisionManager::appendProjectile(Entities::Projectile* projectile) {
        if (projectile) {
            balls.push_back(projectile);
        }
    }

    void CollisionManager::setPlayer(Entities::Player* p) {
        if (p) {
            p1 = p;
        }
    }

    const bool CollisionManager::verifyCollision(Entities::Entity* ent1, Entities::Entity* ent2) const {
        sf::FloatRect coords1 = ent1->getGlobalHitbox();
        sf::FloatRect coords2 = ent2->getGlobalHitbox();

        return coords1.intersects(coords2);
    }

    void CollisionManager::applyPlayerObstacleCollisions() {
        std::list<Entities::Obstacle*>::iterator it = obstacles.begin();
        while (it != obstacles.end()) {
            if (*it) {
                (*it)->obstruct(p1);
            }
            it++;
        }
    }

    void CollisionManager::applyPlayerEnemiesCollisions() {
        std::vector<Entities::Enemy*>::iterator it = enemies.begin();
        while (it != enemies.end()) {
            if (*it) {
                (*it)->applyCollisionDamage(p1);
            }
            it++;
        }
    }

    void CollisionManager::applyPlayerProjectilesCollisions() {
        std::vector<Entities::Projectile*>::iterator itBalls = balls.begin();
        while (itBalls != balls.end()) {
            if (*itBalls) {
                (*itBalls)->obstruct(p1);
            }
            itBalls++;
        }
    }

    void CollisionManager::applyPlayerBorderCollision() {
        if(p1->getGlobalHitbox().left < 0){
            p1->setSpritePosition(0, p1->getGlobalHitbox().top);
        }
    }

    void CollisionManager::applyEnemiesObstaclesCollision() {
        std::vector<Entities::Enemy*>::iterator itEnemies = enemies.begin();
        std::list<Entities::Obstacle*>::iterator itObstacles = obstacles.begin();

        while (itEnemies != enemies.end()) {
            if (*itEnemies) {
                while (itObstacles != obstacles.end()) {
                    if (*itObstacles) {
                        (*itObstacles)->obstruct(*itEnemies);
                    }
                    itObstacles++;
                }
            }
            itEnemies++;
        }
    }

    void CollisionManager::applyProjectileCollisions() {
        std::vector<Entities::Projectile*>::iterator itBalls = balls.begin();

        while (itBalls != balls.end()) {
            bool erased = false;
            if (*itBalls) {
                const sf::FloatRect ballCoordinates = (*itBalls)->getGlobalHitbox();
                std::list<Entities::Obstacle*>::iterator it = obstacles.begin();
                while (it != obstacles.end()) {
                    if (*it) {
                        const sf::FloatRect obsCoordinates = (*it)->getGlobalHitbox();
                        if((ballCoordinates).intersects(obsCoordinates)){
                            (*itBalls)->setToDelete(true);//will be deleted after on update of entity class
                            balls.erase(itBalls);//erasinf from collision manager vector
                            erased = true;
                            break;
                        }
                    }
                    it++;
                }
            }
            if (!erased) {
                ++itBalls;
            }
        }
    }

    void CollisionManager::verifyDelete(){
        for (int i = 0; i < balls.size(); i++) {
            Entities::Projectile* currentball = balls[i];
        
            if (!currentball || currentball->getToDelete()) {
                balls.erase(balls.begin() + i);
                i--;
                continue;
            }
        }
    }

    void CollisionManager::exec() {
        applyPlayerEnemiesCollisions();
        applyPlayerProjectilesCollisions();
        applyPlayerObstacleCollisions();
        applyPlayerBorderCollision();
        applyEnemiesObstaclesCollision();
        applyProjectileCollisions();
        verifyDelete();
    }
}