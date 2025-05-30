#pragma once
#include "Obstacle.h"
class MediumObstacle : public Obstacle //implement damage to player, +10 damage per second of contact
{
private:
	int width, height;
	float damage;
public:
	MediumObstacle() : width(0), height(0), damage(10.f) {}
	MediumObstacle(sf::Texture& texture, int sprite_width, int sprite_height) :
		width(sprite_width),
		height(sprite_height)
	{
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, 0, width, height));
		sprite.setPosition(200, ground - height);
		hitbox = sf::FloatRect(200,ground - height, width, height);
	}
	virtual ~MediumObstacle() {}
	void run() override {}
	void save() override {}
	float getDamage() const { return damage; }
	void setDamage(float damage_value) { damage = damage_value; }
};

