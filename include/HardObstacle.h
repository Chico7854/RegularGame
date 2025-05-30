#pragma once
#include "Obstacle.h"

class HardObstacle : public Obstacle
{
private:
	int width, height;
	float damage;
public:
	HardObstacle() : width(0), height(0), damage(10.f) {}
	HardObstacle(/*sf::Texture& texture,*/  int sprite_width, int sprite_height) :
		width(sprite_width),
		height(sprite_height)
	{
		//sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, 0, width, height));
		sprite.setPosition(400, 500 - height);
		hitbox = sf::FloatRect(400, 500 - height, width, height);
	}
	virtual ~HardObstacle() {}
	void run() override {}
	void save() override {}
	float getDamage() const { return damage; }
	void setDamage(float damage_value) { damage = damage_value; }

};
