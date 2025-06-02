#include "Managers/CollisionManager.h"

namespace Manager {
    CollisionManager* CollisionManager::pSelf(nullptr);

    CollisionManager::CollisionManager() {}

    CollisionManager::~CollisionManager() {}

    CollisionManager* CollisionManager::getCollisionManager() {
        if (!pSelf) {
            pSelf = new CollisionManager();
        }
        return pSelf;
    }
}