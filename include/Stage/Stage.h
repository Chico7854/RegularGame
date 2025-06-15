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
            List::EntityList entityList;
            Manager::CollisionManager* pCollisionManager;
            Entities::Player* player;
            std::string mapPath;
            const int maxEnemies;
            int numberOfYoukais;

        public:
            Stage(const Texture::ID background, const std::string path, const float sprite_width, const float sprite_height);
            virtual ~Stage();

            const Entities::Player* getPlayer() const;
            void exec();

        protected:
            void createEntity(const char ent, const sf::Vector2i pos);
            void createYoukai(const float x, const float y);
            void createPlatform(const float x, const float y);
            void createPlayer();
            void updateView();

            virtual void createEnemies() = 0;
            virtual void createObstacles() = 0;
            virtual void createMap();

            void drawBackground();
    };
}