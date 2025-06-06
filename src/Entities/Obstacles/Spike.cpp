#include "Entities/Obstacles/Spike.h"
#include "Utility/Constants.h"

namespace Entities
{
    Spike::Spike(Texture::ID id, int sprite_width, int sprite_height):
        DamageObstacle(id, sprite_width, sprite_height, EntityType::Spike),
        damage(10)
    {}

    Spike::Spike() {}

    Spike::~Spike() {}
}
