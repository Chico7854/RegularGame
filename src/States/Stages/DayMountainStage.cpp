#include "States/Stages/DayMountainStage.h"

namespace States {
    DayMountainStage::DayMountainStage(const bool isSinglePlayer, const bool defaultMap):
        Stage(Texture::ID::BackgroundDayMountain, "../assets/stages/DayMountainMap.txt", Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT, isSinglePlayer),
        maxCannonheads(5)
    {
        if (defaultMap)
            createMap();
        else 
            loadSave();
    }

    DayMountainStage::~DayMountainStage() {}

    void DayMountainStage::save() {
        std::ofstream file("../data/save.json", std::ios::out);     //delete contents of the file
        json stageData = {{"map", "day"}, {"points", points}, {"isSinglePlayer", isSinglePlayer}};
        json endObj = {{"type",0}};
        file << "[\n";
        file << stageData.dump(4) << ",\n";
        file.flush();
        file.close();
        entities.saveEntities();
        std::ofstream file2("../data/save.json", std::ios::app);
        file2 << endObj.dump(4);
        file2 << "\n]";
        file2.flush();
        file2.close();

        std::cout << "Game Saved \n";
    }

    void DayMountainStage::loadSave() {
        using namespace Entities;
        std::cout << "Game Loaded \n";
        entities.clear(); //preventing entities leaking to other stages
        pCollisionManager->clearLists();
        std::ifstream file("../data/save.json");
        json data = json::parse(file);
        std::vector<json> entitiesJSON = data.get<std::vector<json>>();
        for (int i = 1; i < entitiesJSON.size(); i++) {
            json entityData = entitiesJSON[i];
            EntityType type = entityData["type"];
            switch (type) {
                case EntityType::Platform:
                    createPlatform(entityData["left"], entityData["top"]);
                    break;

                case EntityType::Spike:
                    createSpike(entityData["left"], entityData["top"]);
                    break;

                case EntityType::Player:
                    createPlayer(entityData["left"], entityData["top"], entityData["isPlayer1"]);
                    player->setDx(entityData["dx"]);
                    player->setDy(entityData["dy"]);
                    player->setLife(entityData["lifes"]);
                    player->setOnGround(entityData["onGround"]);
                    player->setIsHurt(entityData["isHurt"]);
                    player->setIsAttacking(entityData["isAttacking"]);
                    break;
                
                case EntityType::Youkai: {
                    Youkai* pYoukai = createYoukai(entityData["left"], entityData["top"]);
                    pYoukai->setEvilness(entityData["evilness"]);
                    pYoukai->setSpeed(entityData["speed"]);
                    pYoukai->setDx(entityData["dx"]);
                    pYoukai->setDy(entityData["dy"]);
                    pYoukai->setLife(entityData["lifes"]);
                    pYoukai->setScratchDamage(entityData["scratchDamage"]);
                    pYoukai->setOnGround(entityData["onGround"]);
                    pYoukai->setIsHurt(entityData["isHurt"]);
                    break;
                }

                case EntityType::Cannonhead: {
                    Cannonhead* pCannonhead = createCannonhead(entityData["left"], entityData["top"]);
                    pCannonhead->setEvilness(entityData["evilness"]);
                    pCannonhead->setLife(entityData["lifes"]);
                    pCannonhead->setSpeed(entityData["speed"]);
                    pCannonhead->setDx(entityData["dx"]);
                    pCannonhead->setDy(entityData["dy"]);
                    pCannonhead->setOnGround(entityData["onGround"]);
                    pCannonhead->setIsHurt(entityData["isHurt"]);
                    pCannonhead->setReloadTime(entityData["reloadTime"]);
                    pCannonhead->setDirection(entityData["direction"]);
                    pCannonhead->setDtime(entityData["dtime"]);
                    break;
                }

                case EntityType::Ball: {
                    Projectile* pBall = new Projectile(Texture::Ball, Constants::BALL_WIDTH, Constants::BALL_HEIGHT);
                    pBall->setSpritePosition(entityData["left"], entityData["top"]);
                    pBall->setDx(entityData["dx"]);
                    pBall->setDy(entityData["dy"]);
                    pBall->setToDelete(entityData["toDelete"]);
                    pBall->setDirection(entityData["direction"]);
                    pBall->setActive(entityData["isActive"]);
                    entities.append(pBall);
                    pCollisionManager->appendProjectile(pBall);
                    break;
                }
            }
        }
    }

    Entities::Cannonhead* DayMountainStage::createCannonhead(const float x, const float y) {
        using namespace Entities;
        Cannonhead* pCannonhead = new Cannonhead();
        pCannonhead->setSpritePosition(x, y);
        pCannonhead->setEntityList(&entities);
        entities.append(static_cast<Entity*>(pCannonhead));
        pCollisionManager->appendEnemy(static_cast<Enemy*>(pCannonhead));
        return pCannonhead;
    }

    void DayMountainStage::createSpike(const float x, const float y) {
        using namespace Entities;
        Spike* pSpike = new Spike();
        pSpike->setSpritePosition(x, y);
        entities.append(static_cast<Entity*>(pSpike));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pSpike));
    }

    void DayMountainStage::createEnemies() {
        int youkaiCount = 0;
        int cannonheadCount = 0;
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
                if(line[i] == 'y') {
                    if (youkaiCount < maxYoukais) {
                        if ((youkaiCount < 3) || (rand() % 2)) {
                            createYoukai(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                            youkaiCount++;
                        }
                    }
                }
                else if (line[i] == 'c') {
                    if (cannonheadCount < maxCannonheads) {
                        if ((cannonheadCount < 3) || (rand() % 2)) {
                            createCannonhead(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                            cannonheadCount++;
                        }
                    }
                }
            }
            j++;
        }
        file.close();
    }

    void DayMountainStage::createObstacles() {
        std::ifstream file;
        std::string line;
        int platformCount = 0;
        int spikeCount = 0;
        file.open(mapPath);
        if (!file.is_open()) {
            std::cerr << "Couldnt open stage file\n";
            exit(1);
        }
        int j = 0;
        while(std::getline(file, line)){
            for(int i = 0; i < line.size(); i++){
                if (line[i] == '#') {
                    createBlock(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                }
                else if (line[i] == '&') {
                    if ((platformCount < 3) || (rand() % 2)) {
                        createPlatform(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                        platformCount++;
                    }
                }
                else if (line[i] == 's') {
                    if ((spikeCount < 3) || (rand() % 2)) {
                        createSpike(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                        spikeCount++;
                    }
                }
            }
            j++;
        }
        file.close();
    }
}