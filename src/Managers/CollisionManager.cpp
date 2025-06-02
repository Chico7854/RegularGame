#include "Managers/CollisionManager.h"

namespace Manager {
    CollisionManager* CollisionManager::pSelf(nullptr);

    CollisionManager::CollisionManager():
        enemies(),
        obstacles(),
        player(nullptr)
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
            player = p;
        }
    }

    void CollisionManager::verifyCollision(std::pair<Entities::Entity*, Entities::Entity*> entities) {
        sf::FloatRect intersectionRect;
        const sf::FloatRect firstCoordinates = entities.first->getGlobalHitbox();
        const sf::FloatRect secondCoordinates = entities.second->getGlobalHitbox();

        std::cout << "Player left: " << firstCoordinates.left << "\nPlatform left: " << secondCoordinates.left << std::endl;
        std::cout << "Player top: " << firstCoordinates.top << "\nPlatform top: " << secondCoordinates.top << std::endl;


        if (firstCoordinates.intersects(secondCoordinates, intersectionRect)) {
            std::cout << "Intersecting" << std::endl;
        }
    }
}