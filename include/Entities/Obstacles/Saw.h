#pragma once
#include <SFML/Graphics.hpp>

#include "DamageObstacle.h"
#include "Entities/Characters/Character.h"

#include "Utility/Texture.h"

namespace Entities {
	class Saw : public DamageObstacle //implement damage, +50 damage for tounching it and it thwrows the player back
	{
	private:
		float damage;
		float frame;
	public:
		Saw(Texture::ID id, int sprite_width, int sprite_height);
		Saw();
		virtual ~Saw();
		void save() override {}
		void exec() override {};
		float getDamage() const { return damage; }
		void setDamage(float damage_value) { damage = damage_value; }
	};
}