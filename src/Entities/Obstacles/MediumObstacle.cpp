#include "Entities/Obstacles/MediumObstacle.h"
#include "Utility/Constants.h"

namespace Entities
{
    MediumObstacle::MediumObstacle(Texture::ID id, int sprite_width, int sprite_height):
        DamageObstacle(id, sprite_width, sprite_height, EntityType::Spike),
        damage(10)
    {}

    MediumObstacle::MediumObstacle() {}

    MediumObstacle::~MediumObstacle() {}
}
