#include "Stage/NightMountainStage.h"

namespace Stage {
    NightMountainStage::NightMountainStage():
        Stage(Texture::ID::BackgroundNightMountain, "../assets/stages/NightMountainMap.txt", Constants::BACKGROUND_NIGHT_WIDTH, Constants::BACKGROUND_NIGHT_HEIGHT)
    {
        sprite.setScale({0.5, 0.5});
    }

    NightMountainStage::~NightMountainStage() {}
}