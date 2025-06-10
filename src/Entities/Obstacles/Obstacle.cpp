#include "Entities/Obstacles/Obstacle.h"

namespace Entities {
    Obstacle::Obstacle(const Texture::ID id, const int sprite_width, const int sprite_height, const EntityType type, const bool harmful):
        Entity(id, sprite_width, sprite_height, type),
        isHarmful(harmful)
    {}

    Obstacle::Obstacle():
        isHarmful(false)
    {}

    Obstacle::~Obstacle() {}
}