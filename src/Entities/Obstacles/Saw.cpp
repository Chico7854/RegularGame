#include "Entities/Obstacles/Saw.h"
#include "Utility/Constants.h"

namespace Entities {
	Saw::Saw(Texture::ID id, int sprite_width, int sprite_height):
		DamageObstacle(id, sprite_width, sprite_height, EntityType::Saw), 
		damage(10.f), 
		frame(0)
	{}

	Saw::Saw() {}

	Saw::~Saw() {}
}