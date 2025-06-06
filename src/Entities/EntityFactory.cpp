#include "Entities/EntityFactory.h"

namespace Entities {
    EntityFactory::EntityFactory() {}

    EntityFactory::~EntityFactory() {}

    Entity* EntityFactory::createEntity(EntityType type, const float x, const float y) {
        switch (type) {
            case (EntityType::Youkai):
                return createYoukai(x, y);

            case (EntityType::Cannonhead):
                return createCannonhead(x, y);

            case (EntityType::Platform):
                return createPlatform(x, y);

            case (EntityType::Spike):
                return createSpike(x, y);

            case (EntityType::Saw):
                return createSaw(x, y);

            case (EntityType::Floor):
                return createFloor(x);

            case (EntityType::Player):
                return createPlayer();

            default:
                std::cerr << "ERROR failed to create entity. Type doesn't exist.\n";
                exit(1);
        }
    }

    Entity* EntityFactory::createYoukai(const float x, const float y) {
        Youkai* pYoukai = new Youkai(Texture::Youkai, Constants::YOUKAI_WIDTH, Constants::YOUKAI_HEIGHT);
        pYoukai->setSpritePosition(x, y);
        return static_cast<Entity*>(pYoukai);
    }

    Entity* EntityFactory::createCannonhead(const float x, const float y){
        Cannonhead* pCannonhead = new Cannonhead(Texture::Cannonhead, Constants::CANNONHEAD_WIDTH, Constants::CANNONHEAD_HEIGHT);
        pCannonhead->setSpritePosition(x, y);
        return static_cast<Entity*>(pCannonhead);
    }

    Entity* EntityFactory::createPlatform(const float x, const float y) {
        Platform* pPlatform = new Platform(Texture::Platform, Constants::PLATFORM_WIDTH, Constants::PLATFORM_HEIGHT);
        pPlatform->setSpritePosition(x, y);
        return static_cast<Entity*>(pPlatform);
    }

    Entity* EntityFactory::createSpike(const float x, const float y) {
        MediumObstacle* pSpike = new MediumObstacle(Texture::Spike, Constants::SPIKE_WIDTH, Constants::SPIKE_HEIGHT);
        pSpike->setSpritePosition(x, y);
        return static_cast<Entity*>(pSpike);
    }

    Entity* EntityFactory::createSaw(const float x, const float y) {
        HardObstacle* pSaw = new HardObstacle(Texture::Saw, Constants::SAW_WIDTH, Constants::SAW_HEIGHT);
        pSaw->setSpritePosition(x, y);
        return static_cast<Entity*>(pSaw);
    }

    Entity* EntityFactory::createFloor(const float x) {
        Platform* pFloor = new Platform(Texture::Floor, Constants::FLOOR_SPRITE_WIDTH, Constants::FLOOR_SPRITE_HEIGHT);
        pFloor->setSpritePosition(x, Constants::FLOOR_HEIGHT);
        return static_cast<Entity*>(pFloor);
    }

    Entity* EntityFactory::createPlayer() {
        Player* pPlayer= new Player(Texture::Player1, Constants::P1_WIDTH, Constants::P1_HEIGHT);
        pPlayer->setSpritePosition(0, Constants::FLOOR_HEIGHT - Constants::P1_HEIGHT);
        return static_cast<Entity*>(pPlayer);
    }
}