#pragma once
#include "Entities/Characters/Character.h"
#include "Entities/Obstacles/Obstacle.h"

#include "Utility/Texture.h"

namespace Entities {
	class Spike : public Obstacle //implement damage to player, +10 damage per second of contact
	{
	private:
		const int damage;
		
	public:
		Spike();
		virtual ~Spike();

		void save() override;
		void exec() override {};
		void obstruct(Character* character) override;

		const int getDamage() const;
	};
}
