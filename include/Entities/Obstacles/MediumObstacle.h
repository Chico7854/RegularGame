#pragma once
#include "DamageObstacle.h"
#include "Entities/Characters/Character.h"

#include "Utility/Texture.h"

namespace Entities {
	class MediumObstacle : public DamageObstacle //implement damage to player, +10 damage per second of contact
	{
	private:
		float damage;
	public:
		MediumObstacle(Texture::ID id, int sprite_width, int sprite_height);
		MediumObstacle();
		virtual ~MediumObstacle();

		void save() override {}
		float getDamage() const { return damage; }
		void setDamage(float damage_value) { damage = damage_value; }
	};
}
