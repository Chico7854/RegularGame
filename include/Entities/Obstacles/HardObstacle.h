#pragma once
#include <SFML/Graphics.hpp>

#include "DamageObstacle.h"
#include "Entities/Characters/Character.h"

#include "Utility/Texture.h"

namespace Entities {
	class HardObstacle : public DamageObstacle //implement damage, +50 damage for tounching it and it thwrows the player back
	{
	private:
		float damage;
		float frame;
	public:
		HardObstacle(Texture::ID id, int sprite_width, int sprite_height);
		HardObstacle();
		virtual ~HardObstacle();
		void save() override {}
		void update() override {};
		float getDamage() const { return damage; }
		void setDamage(float damage_value) { damage = damage_value; }
	};
}