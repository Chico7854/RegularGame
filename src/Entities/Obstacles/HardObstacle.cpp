#include "Entities/Obstacles/HardObstacle.h"
#include "Utility/Constants.h"

namespace Entities {
	HardObstacle::HardObstacle(Texture::ID id, int sprite_width, int sprite_height):
		DamageObstacle(id, sprite_width, sprite_height, EntityType::Saw), 
		damage(10.f), 
		frame(0)
	{}

	HardObstacle::HardObstacle() {}

	HardObstacle::~HardObstacle() {}
}