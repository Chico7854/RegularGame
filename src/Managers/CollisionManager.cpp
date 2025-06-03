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

    void CollisionManager::appendPlatform(Entities::Platform* platform) {
        if (platform) {
            platforms.push_back(platform);
        }
    }

    void CollisionManager::setPlayer(Entities::Player* p) {
        if (p) {
            p1 = p;
        }
    }

    void CollisionManager::applyNoDamageCollision(Entities::Character* character, Entities::Entity* entity) {
        sf::FloatRect intersectionRect;

        const sf::FloatRect charCoordinates = character->getGlobalHitbox();
        const sf::FloatRect entCoordinates = entity->getGlobalHitbox();

        if (charCoordinates.intersects(entCoordinates, intersectionRect)) {
            float xOverlap = intersectionRect.width;
            float yOverlap = intersectionRect.height;

            /*Check vertical collision*/
            if (yOverlap < xOverlap) {
                character->setDy(0.f);
                if (entCoordinates.top > charCoordinates.top)
                    yOverlap *= -1;
                    character->setOnGround(true);
                    character->setIsHurt(false);
                character->moveHitboxSprite(0, yOverlap);
            } 
            /*Horizontal collision*/
            else {
                if (entCoordinates.left > charCoordinates.left)
                    xOverlap *= -1;
                character->moveHitboxSprite(xOverlap, 0);
            }
        }
    }

    void CollisionManager::applyDamageCollision(Entities::Player* player, Entities::Entity* entity) {
        const sf::FloatRect playerCoordinates = player->getGlobalHitbox();
        const sf::FloatRect entCoordinates = entity->getGlobalHitbox();


        if (playerCoordinates.intersects(entCoordinates)) {
            const float middlePointPlayer = playerCoordinates.left + (playerCoordinates.width / 2);
            const float middlePointEntity = entCoordinates.left + (entCoordinates.width / 2);

            const float dy = Constants::JUMP_SPEED / 1.5;
            float dx = Constants::SPEED * 2;

            if (middlePointPlayer < middlePointEntity) {
                dx *= -1;
            }

            player->setDy(dy);
            player->setDx(dx);
            player->setIsHurt(true);
        }
    }

    void CollisionManager::verifyNoDamageCollisions() {
        std::list<Entities::Platform*>::iterator it = platforms.begin();
        while (it != platforms.end()) {
            if (*it) {
                applyNoDamageCollision(p1, *it);
            }
            it++;
        }
    }
}