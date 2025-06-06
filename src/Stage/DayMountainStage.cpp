#include "Stage/DayMountainStage.h"

namespace Stage {
    DayMountainStage::DayMountainStage():
        Stage(Texture::ID::BackgroundDayMountain, "../assets/stages/DayMountainMap.txt")
    {}

    DayMountainStage::~DayMountainStage() {}
}