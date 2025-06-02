#pragma once

namespace Manager {
    class CollisionManager {
        private:

            static CollisionManager* pSelf;
            CollisionManager();

        public:
            ~CollisionManager();
            static CollisionManager* getCollisionManager();
    };
}