#include "Stage/DayMountainStage.h"

namespace Stage {
    DayMountainStage::DayMountainStage():
        Stage(Texture::ID::BackgroundDayMountain, "../assets/stages/DayMountainMap.txt", Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT)
    {
        numberOfCannonheads = rand() % (maxEnemies - 3);
        numberOfCannonheads += 3;
        createMap();
    }

    DayMountainStage::~DayMountainStage() {}

    void DayMountainStage::createCannonhead(const float x, const float y) {
        using namespace Entities;
        Cannonhead* pCannonhead = new Cannonhead();
        pCannonhead->setSpritePosition(x, y);
        entityList.append(static_cast<Entity*>(pCannonhead));
        pCollisionManager->appendEnemy(static_cast<Enemy*>(pCannonhead));
    }

    void DayMountainStage::createSpike(const float x, const float y) {
        using namespace Entities;
        Spike* pSpike = new Spike();
        pSpike->setSpritePosition(x, y);
        entityList.append(static_cast<Entity*>(pSpike));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pSpike));

    }

    void DayMountainStage::createEnemies() {
        int youkaiCount = 0;
        int cannonheadCount = 0;
        std::cout << numberOfCannonheads << "\n" << numberOfYoukais << "\n";
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
                    if (youkaiCount < numberOfYoukais) {
                        createYoukai(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                        youkaiCount++;
                    }
                }
                else if (line[i] == 'c') {
                    if (cannonheadCount < numberOfCannonheads) {
                        createCannonhead(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                        cannonheadCount++;
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
                    createPlatform(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                }
                else if (line[i] == 's') {
                    createSpike(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                }
            }
            j++;
        }
        file.close();
    }
}