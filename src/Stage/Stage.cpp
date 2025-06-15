#include "Stage/Stage.h"

namespace Stage {
    Stage::Stage(const Texture::ID background, const std::string path, const float sprite_width, const float sprite_height):
        Ent(background, sprite_width, sprite_height),
        charactersList(),
        obstaclesList(),
        pCollisionManager(Manager::CollisionManager::getCollisionManager()),
        mapPath(path)
    {}

    Stage::~Stage() {}

    const Entities::Player* Stage::getPlayer() const {
        return player;
    }

    void Stage::createEntity(const char ent, const sf::Vector2i pos) {
        switch (ent) {
            case ('y'):
                createYoukai(pos.x, pos.y);
                break;
            case ('#'):
                createPlatform(pos.x, pos.y);
                break;
        }
    }

    void Stage::createYoukai(const float x, const float y) {
        using namespace Entities;
        Youkai* pYoukai = new Youkai(Texture::Youkai, Constants::YOUKAI_WIDTH, Constants::YOUKAI_HEIGHT);
        pYoukai->setSpritePosition(x, y);
        Entity* pEntity = static_cast<Entity*>(pYoukai);
        charactersList.append(pEntity); 
        pCollisionManager->appendEnemy(static_cast<Enemy*>(pEntity));
    }

    void Stage::createPlatform(const float x, const float y) {
        using namespace Entities;
        Platform* pPlatform = new Platform(Texture::Platform, Constants::PLATFORM_WIDTH, Constants::PLATFORM_HEIGHT);
        pPlatform->setSpritePosition(x, y);
        Entity* pEntity = static_cast<Entity*>(pPlatform);
        obstaclesList.append(pEntity);
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pEntity));
    }

    void Stage::createPlayer() {
        using namespace Entities;
        player = new Player(Texture::Player1, Constants::P1_WIDTH, Constants::P1_HEIGHT);
        player->setSpritePosition(0.f, Constants::FLOOR_HEIGHT - Constants::P1_HEIGHT);
        pCollisionManager->setPlayer(player);
        Manager::EventManager::getEventManager()->setPlayer(player);
    }

    void Stage::updateView() {
        pGraphicsManager->setViewCenter(player->getGlobalHitbox().left);
        setSpritePosition(pGraphicsManager->getViewPositionX(), 0.f);
    }

    void Stage::createMap() {
        std::ifstream file;
        std::string line;
        file.open(mapPath);
        if (!file.is_open()) {
            std::cerr << "Couldnt open stage file\n";
            exit(1);
        }
        int j = 0;
        while(std::getline(file, line)){
            for(int i = 0; i < line.size(); i++){
                if(line[i] != ' ') {
                    createEntity(line[i], {i * Constants::SCALE_TXT, j * Constants::SCALE_TXT});
                }
            }
            j++;
        }
        createPlayer();

        file.close();
    }

    void Stage::exec() {
        updateView();
        draw();   //draw background
        player->update();
        charactersList.updateEntities();
        pCollisionManager->verifyCollisions();
        player->draw();
        charactersList.drawEntities();
        obstaclesList.drawEntities();
    }
}