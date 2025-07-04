#include "Managers/CollisionManager.h"

namespace Manager {
    CollisionManager* CollisionManager::pSelf(nullptr);

    CollisionManager::CollisionManager():
        enemies(),
        obstacles(),
        balls(),
        p1(nullptr),
        p2(nullptr)
    {
        enemies.clear();
        obstacles.clear();
        balls.clear();
    }

    CollisionManager::~CollisionManager() {
        p1 = nullptr;
        p2 = nullptr;
        enemies.clear();
        obstacles.clear();
        balls.clear();
    }

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

    void CollisionManager::setPlayer1(Entities::Player* p) {
        if (p) {
            p1 = p;
        }
    }

    void CollisionManager::setPlayer2(Entities::Player* p) {
        if (p) {
            p2 = p;
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
                if (verifyCollision(*it, p1)) 
                    (*it)->obstruct(static_cast<Entities::Character*>(p1));
                if (p2)
                    if (verifyCollision(*it, p2))
                        (*it)->obstruct(static_cast<Entities::Character*>(p2));
            }
            it++;
        }
    }

    void CollisionManager::applyPlayerEnemiesCollisions() {
        std::vector<Entities::Enemy*>::iterator it = enemies.begin();
        while (it != enemies.end()) {
            if (*it) {
                p1->collide(*it);
                if (p2)
                    p2->collide(*it);
            }
            it++;
        }
    }

    void CollisionManager::applyPlayerProjectilesCollisions() {
        std::vector<Entities::Projectile*>::iterator itBalls = balls.begin();
        while (itBalls != balls.end()) {
            if (*itBalls) {
                (*itBalls)->obstruct(p1);
                if (p2) 
                    (*itBalls)->obstruct(p2);
            }
            itBalls++;
        }
    }

    void CollisionManager::applyPlayerBorderCollision() {
        const sf::FloatRect p1Coords = p1->getGlobalHitbox();
        if(p1Coords.left < 0){
            p1->setSpritePosition(0, p1Coords.top);
        }
        else if ((p1Coords.left + p1Coords.width) > Constants::MAP_WIDTH) {
            p1->setSpritePosition(Constants::MAP_WIDTH - p1Coords.width, p1Coords.top);
        }
        if (p2) {
            const sf::FloatRect p2Coords = p2->getGlobalHitbox();
            if(p2Coords.left < 0){
            p2->setSpritePosition(0, p2Coords.top);
        }
        else if ((p2Coords.left + p2Coords.width) > Constants::MAP_WIDTH) {
            p2->setSpritePosition(Constants::MAP_WIDTH - p2Coords.width, p2Coords.top);
        }
        }
    }

    void CollisionManager::applyEnemiesObstaclesCollision() {
        std::vector<Entities::Enemy*>::iterator itEnemies = enemies.begin();
        Entities::Enemy* pEnemy = nullptr;

        while (itEnemies != enemies.end()) {
            std::list<Entities::Obstacle*>::iterator itObstacles = obstacles.begin();
            pEnemy = *itEnemies;
            if (pEnemy) {
                (pEnemy)->setOnGround(false);
                while (itObstacles != obstacles.end()) {
                    if (*itObstacles) {
                        (*itObstacles)->obstruct(static_cast<Entities::Character*>(*itEnemies));
                    }
                    itObstacles++;
                }
            }
            if (pEnemy->getOnGround() == false) {
                pEnemy->changeDirectionOnPlatform();
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

        for (int i = 0; i < enemies.size(); i++) {
            Entities::Enemy* currentEnemy = enemies[i];

            if (!currentEnemy || currentEnemy->getToDelete()) {
                enemies.erase(enemies.begin() + i);
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

    void CollisionManager::clearLists() { 
        enemies.clear(); 
        obstacles.clear(); 
        balls.clear(); 
        p1 = nullptr; 
    }
}