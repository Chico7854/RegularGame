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

    void CollisionManager::verifyCollision(Entities::Character* character, Entities::Entity* entity) {
        sf::FloatRect intersectionRect;

        const sf::FloatRect charCoordinates = character->getGlobalHitbox();
        const sf::FloatRect entCoordinates = entity->getGlobalHitbox();

        if (charCoordinates.intersects(entCoordinates, intersectionRect)) {
            float xOverlap = intersectionRect.width;
            float yOverlap = intersectionRect.height;

            /*Check vertical collision*/
            if (yOverlap < xOverlap) {
                if (entCoordinates.top > charCoordinates.top)
                    yOverlap *= -1;
                character->moveHitboxSprite(0, yOverlap);
                std::cout << "Vertical\n";
            } 
            /*Horizontal collision*/
            else {
                if (entCoordinates.left > charCoordinates.left)
                    xOverlap *= -1;
                character->moveHitboxSprite(xOverlap, 0);
                std::cout << "Horizontal\n";
            }
        }
        std::cout << "None\n";
    }
}