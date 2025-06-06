#include "Stage/DayMountainStage.h"

namespace Stage {
    DayMountainStage::DayMountainStage():
        Stage(Texture::ID::BackgroundDayMountain, "../assets/stages/DayMountainMap.txt", Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT)
    {}

    DayMountainStage::~DayMountainStage() {}
}