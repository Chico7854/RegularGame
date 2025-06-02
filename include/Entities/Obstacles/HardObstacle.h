#pragma once

#include <SFML/Graphics.hpp>
#include "Obstacle.h"
#include "Utility/Texture.h"

namespace Entities {
	class HardObstacle : public Obstacle //implement damage, +50 damage for tounching it and it thwrows the player back
	{
	private:
		float damage;
		float frame;
	public:
		HardObstacle() : damage(10.f), frame(0) {}
		HardObstacle(Texture::ID id, int sprite_width, int sprite_height): Obstacle(id, sprite_width, sprite_height), damage(10.f), frame(0)
		{
			sprite.setPosition(400, ground - height);
		}
		virtual ~HardObstacle() {}
		void run() override {}
		void save() override {}
		void animation(float time);
		float getDamage() const { return damage; }
		void setDamage(float damage_value) { damage = damage_value; }

	};
}