#include "Stage/Stage.h"

namespace Stage {
    Stage::Stage():
        Ent(Texture::ID::Background, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT),
        charactersList(),
        obstaclesList(),
        pCollisionManager(Manager::CollisionManager::getCollisionManager())
    {}

    Stage::~Stage() {}

    const Entities::Player* Stage::getPlayer() const {
        return player;
    }

    void Stage::createEntity(const char ent, const sf::Vector2i pos) {
        switch (ent) {
            case ('y'):
                createYoukai(pos.x * 50.f, pos.y * 50.f);
                break;
            case ('p'):
                createPlatform(pos.x * 50.f, pos.y * 50.f);
                break;
        }
    }

    void Stage::createYoukai(const float x, const float y) {
        using namespace Entities;
        Youkai* pYoukai = new Youkai(Texture::Youkai, Constants::YOUKAI_WIDTH, Constants::YOUKAI_HEIGHT);
        pYoukai->setSpritePosition(x, y);
        charactersList.append(static_cast<Entity*>(pYoukai));
        pCollisionManager->appendEnemy(pYoukai);
    }

    void Stage::createPlatform(const float x, const float y) {
        using namespace Entities;
        Platform* pPlatform = new Platform(Texture::Platform, Constants::PLATFORM_WIDTH, Constants::PLATFORM_HEIGHT);
        pPlatform->setSpritePosition(x, y);
        obstaclesList.append(static_cast<Entity*>(pPlatform));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform));
    }

    void Stage::createFloor() {
        using namespace Entities;
        Platform* pFloor = new Platform(Texture::Floor, 5000.f, Constants::FLOOR_HEIGHT);
        pFloor->setSpritePosition(0, Constants::FLOOR_HEIGHT);
        obstaclesList.append(static_cast<Entity*>(pFloor));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pFloor));
    }

    void Stage::createPlayer() {
        using namespace Entities;
        Player* pPlayer= new Player(Texture::Player1, Constants::P1_WIDTH, Constants::P1_HEIGHT);
        pPlayer->setSpritePosition(0, Constants::FLOOR_HEIGHT - Constants::P1_HEIGHT);
        player = pPlayer;
        pCollisionManager->setPlayer(player);
        Manager::EventManager::getEventManager()->setPlayer(player);
    }

    void Stage::createMap() {
        // createFloor();
        // createYoukai(400.f, Constants::FLOOR_HEIGHT - Constants::YOUKAI_HEIGHT);
        // createPlatform(800.f, Constants::FLOOR_HEIGHT - 100.f);
        // createPlayer();
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
                    createEntity(line[i], {i, j});
                }
            }
            j++;
        }
        createPlayer();
        createFloor();

        file.close();
    }

    void Stage::exec() {
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