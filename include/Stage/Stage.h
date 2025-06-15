#pragma once
#include <fstream>
#include <string>

#include "Ent.h"
#include "Entities/EntityList.h"
#include "Entities/Characters/Youkai.h"
#include "Entities/Characters/Cannonhead.h"
#include "Managers/CollisionManager.h"
#include "Managers/EventManager.h"

namespace Stage {
    class Stage : public Ent {
        protected:
            List::EntityList charactersList;
            List::EntityList obstaclesList;
            Manager::CollisionManager* pCollisionManager;
            Entities::Player* player;
            std::string mapPath;

        public:
            Stage(const Texture::ID background, const std::string path, const float sprite_width, const float sprite_height);
            ~Stage();

            const Entities::Player* getPlayer() const;

        protected:
            void createEntity(const char ent, const sf::Vector2i pos);
            void createYoukai(const float x, const float y);
            void createPlatform(const float x, const float y);
            void createPlayer();
            void updateView();

            // virtual void createEnemies() = 0;
            // virtual void createObstacle() = 0;

        public:
            virtual void createMap();
            void exec();
    };
}