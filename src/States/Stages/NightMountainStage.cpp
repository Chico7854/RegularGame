#include "States/Stages/NightMountainStage.h"

namespace States {
    NightMountainStage::NightMountainStage(const bool isSinglePlayer, const bool defaultMap, const int pointsValue):
        Stage(Texture::ID::BackgroundNightMountain, "../assets/stages/NightMountainMap.txt", Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT, isSinglePlayer, pointsValue, 1),
        maxGhosts(3),
        maxSaws(20)
    {
        if (defaultMap)
            createMap();
        else
            loadSave();
    }

    NightMountainStage::~NightMountainStage() {}

    void NightMountainStage::save() {
        std::ofstream file("../data/save.json", std::ios::out);     //delete contents of the file
        json stageData = {{"map", "night"}, {"points", points}, {"isSinglePlayer", isSinglePlayer}};
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

    void NightMountainStage::loadSave() {
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

                case EntityType::Saw: {
                    Saw* pSaw = createSaw(entityData["left"], entityData["top"]);
                    pSaw->setDx(entityData["dx"]);
                    pSaw->setDy(entityData["dy"]);
                    pSaw->setDx_sum(entityData["dx_sum"]);
                    break;
                }

                case EntityType::Player: {
                    Entities::Player* pPlayer = createPlayer(entityData["left"], entityData["top"], entityData["isPlayer1"]);
                    pPlayer->setDx(entityData["dx"]);
                    pPlayer->setDy(entityData["dy"]);
                    pPlayer->setLife(entityData["lifes"]);
                    pPlayer->setOnGround(entityData["onGround"]);
                    pPlayer->setIsHurt(entityData["isHurt"]);
                    pPlayer->setIsAttacking(entityData["isAttacking"]);
                    break;
                }
                
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

                case EntityType::Ghost: {
                    Ghost* pGhost = createGhost(entityData["left"], entityData["top"]);
                    pGhost->setEvilness(entityData["evilness"]);
                    pGhost->setLife(entityData["lifes"]);
                    pGhost->setSpeed(entityData["speed"]);
                    pGhost->setDx(entityData["dx"]);
                    pGhost->setDy(entityData["dy"]);
                    pGhost->setSoulDamage(entityData["soulDamage"]);
                    pGhost->setOnGround(entityData["onGround"]);
                    pGhost->setIsHurt(entityData["isHurt"]);
                    pGhost->setDtime(entityData["dtime"]);
                    pGhost->setInRange(entityData["inRange"]);
                    break;
                }
            }
        }
    }

    Entities::Ghost* NightMountainStage::createGhost(const float x, const float y) {
        using namespace Entities;
        Ghost* pGhost = new Ghost();
        pGhost->setSpritePosition(x, y);
        entities.append(static_cast<Entity*>(pGhost));
        pCollisionManager->appendEnemy(static_cast<Enemy*>(pGhost));
        pGhost->setPlayer(player);
        return pGhost;
    }

    Entities::Saw* NightMountainStage::createSaw(const float x, const float y) {
        using namespace Entities;
        Saw* pSaw = new Saw();
        pSaw->setSpritePosition(x, y);
        entities.append(static_cast<Entity*>(pSaw));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pSaw));
        return pSaw;
    }

    void NightMountainStage::createEnemies() {
        int youkaiCount = 0;
        int ghostCount = 0;
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
                else if (line[i] == 'g') {
                    if (ghostCount < maxGhosts) {
                        if ((ghostCount < 3) || (rand() % 2)) {
                            createGhost(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                            ghostCount++;
                        }
                    }
                }
            }
            j++;
        }
        file.close();
    }

    void NightMountainStage::createObstacles() {
        std::ifstream file;
        std::string line;
        int platformCount = 0;
        int sawCount = 0;
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
                    if (platformCount < maxPlatforms) {
                        if ((platformCount < 3) || (rand() % 2)) {
                            createPlatform(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                            platformCount++;
                        }
                    }
                }
                else if (line[i] == 'S') {
                    if (sawCount < maxSaws) {
                        if ((sawCount < 3) || (rand() % 2)) {
                            createSaw(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                            sawCount++;
                        }
                    }
                }
            }
            j++;
        }
        file.close();
    }
}