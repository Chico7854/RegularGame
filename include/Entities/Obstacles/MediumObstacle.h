#pragma once

#include "Obstacle.h"
#include "Utility/Texture.h"

namespace Entities {
	class MediumObstacle : public Obstacle //implement damage to player, +10 damage per second of contact
	{
	private:
		float damage;
	public:
		MediumObstacle() : damage(10.f) {}
		MediumObstacle(Texture::ID id, int sprite_width, int sprite_height): Obstacle(id, sprite_width, sprite_height), damage(10)
		{
		}
		virtual ~MediumObstacle() {}
		void run() override {}
		void save() override {}
		float getDamage() const { return damage; }
		void setDamage(float damage_value) { damage = damage_value; }
	};
}
