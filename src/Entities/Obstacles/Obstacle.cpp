#include "Entities/Obstacles/Obstacle.h"

namespace Entities {
    Obstacle::Obstacle(Texture::ID id, int sprite_width, int sprite_height):
        Entity(id, sprite_width, sprite_height, Constants::Obstacle)
    {}

    Obstacle::Obstacle() {}

    Obstacle::~Obstacle() {}
}