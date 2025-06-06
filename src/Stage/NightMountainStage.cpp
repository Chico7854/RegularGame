#include "Stage/NightMountainStage.h"

namespace Stage {
    NightMountainStage::NightMountainStage():
        Stage(Texture::ID::BackgroundNightMountain, "../assets/stages/NightMountainMap.txt")
    {}

    NightMountainStage::~NightMountainStage() {}
}