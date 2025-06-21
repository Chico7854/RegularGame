#include "States/Stages/DayMountainStage.h"

namespace States {
    DayMountainStage::DayMountainStage():
        Stage(Texture::ID::BackgroundDayMountain, "../assets/stages/DayMountainMap.txt", Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT),
        maxCannonheads(5)
    {
        createMap();
    }

    DayMountainStage::~DayMountainStage() {}

    void DayMountainStage::createCannonhead(const float x, const float y) {
        using namespace Entities;
        Cannonhead* pCannonhead = new Cannonhead();
        pCannonhead->setSpritePosition(x, y);
        pEntityList->append(static_cast<Entity*>(pCannonhead));
        pCollisionManager->appendEnemy(static_cast<Enemy*>(pCannonhead));
    }

    void DayMountainStage::createSpike(const float x, const float y) {
        using namespace Entities;
        Spike* pSpike = new Spike();
        pSpike->setSpritePosition(x, y);
        pEntityList->append(static_cast<Entity*>(pSpike));
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
                    if (rand() % 2) 
                        createPlatform(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                }
                else if (line[i] == 's') {
                    if (rand() % 2)
                        createSpike(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                }
            }
            j++;
        }
        file.close();
    }
}