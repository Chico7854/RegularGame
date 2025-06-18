#pragma once
#include <SFML/Graphics.hpp>

#include "Entities/Characters/Character.h"
#include "Entities/Obstacles/Obstacle.h"

#include "Utility/Texture.h"
#include "Utility/Constants.h"

namespace Entities {
	class Saw : public Obstacle //implement damage, +50 damage for tounching it and it thwrows the player back
	{
	private:
		float damage;
		float dx,dy;
		float moving_area;
		float dx_sum;
		float frame;
	public:
		Saw();
		virtual ~Saw();
		void save() override {}
		void exec() override;
		void obstruct(Character* character) override;
		void moveHitboxSprite(float dx, float dy); 
		void moveSaw();
		float getDamage() const { return damage; }
		void setDamage(float damage_value) { damage = damage_value; }
	};
}