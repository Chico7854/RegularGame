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
		const int damage;
		const float moving_area;
		float dx,dy;
		float dx_sum;

	public:
		Saw();
		virtual ~Saw();

		void save() override;
		void exec() override;

		void obstruct(Character* character) override;
		void moveHitboxSprite(float dx, float dy); 
		void moveSaw();
		void saveDataBuffer();

		void setDx(const float DX);
		void setDy(const float DY);
		void setDx_sum(const float dxsum);
		const float getDamage() const;
	};
}