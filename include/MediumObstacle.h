#pragma once
#include "Obstacle.h"
class MediumObstacle : public Obstacle //implement damage to player, +10 damage per second of contact
{
private:
	float damage;
public:
	MediumObstacle() : damage(10.f) {}
	MediumObstacle(sf::Texture& texture, int sprite_width, int sprite_height): Obstacle(texture, sprite_width, sprite_height), damage(10)
	{
		sprite.setPosition(200, ground - height);
	}
	virtual ~MediumObstacle() {}
	void run() override {}
	void save() override {}
	float getDamage() const { return damage; }
	void setDamage(float damage_value) { damage = damage_value; }
};

