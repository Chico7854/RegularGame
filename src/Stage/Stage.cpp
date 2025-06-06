#include "Stage/Stage.h"

namespace Stage {
    Stage::Stage(const Texture::ID background):
        Ent(background, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT),
        charactersList(),
        obstaclesList(),
        entityFactory(),
        pCollisionManager(Manager::CollisionManager::getCollisionManager())
    {}

    Stage::~Stage() {}

    const Entities::Player* Stage::getPlayer() const {
        return player;
    }

    void Stage::createEntity(const char ent, const sf::Vector2i pos) {
        switch (ent) {
            case ('y'):
                createCharacter(Entities::EntityType::Youkai, pos.x, pos.y);
                break;
            case ('c'):
                createCharacter(Entities::EntityType::Cannonhead, pos.x, pos.y);
                break;
            case ('p'):
                createObstacle(Entities::EntityType::Platform,  pos.x, pos.y);
                break;
            case ('f'):
                createObstacle(Entities::EntityType::Floor, pos.x, pos.y);
                break;
            case ('s'):
                createObstacle(Entities::EntityType::Spike, pos.x, pos.y);
                break;
            case ('S'):
                createObstacle(Entities::EntityType::Saw, pos.x, pos.y);
        }
    }

    void Stage::createCharacter(const Entities::EntityType type, const float x, const float y) {
        using namespace Entities;
        Entity* pEntity = entityFactory.createEntity(type, x, y);
        charactersList.append(pEntity);
        if (type != EntityType::Player) 
            pCollisionManager->appendEnemy(static_cast<Enemy*>(pEntity));
    }

    void Stage::createObstacle(const Entities::EntityType type, const float x, const float y) {
        using namespace Entities;
        Entity* pEntity = entityFactory.createEntity(type, x, y);
        obstaclesList.append(pEntity);
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pEntity));
    }

    void Stage::createPlayer() {
        using namespace Entities;
        player = static_cast<Player*>(entityFactory.createEntity(EntityType::Player, 0, 0));
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
        file.open("../assets/stages/fuck.txt");
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
        player->setOnGround(false);
        player->update();
        charactersList.updateEntities();
        pCollisionManager->verifyCollisions();
        player->draw();
        charactersList.drawEntities();
        obstaclesList.drawEntities();
    }
}