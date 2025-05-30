#pragma once
#include "Obstacle.h"
class MediumObstacle : public Obstacle
{
private:
	int width, height;
	float damage;
public:
	MediumObstacle() : width(0), height(0), damage(10.f) {}
	MediumObstacle(/*sf::Texture& texture,*/  int sprite_width, int sprite_height) :
		width(sprite_width),
		height(sprite_height)
	{
		//sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, 0, width, height));
		sprite.setPosition(800, 500 - height);
		hitbox = sf::FloatRect(800, 500 - height, width, height);
	}
	virtual ~MediumObstacle() {}
	void run() override {}
	void save() override {}
	float getDamage() const { return damage; }
	void setDamage(float damage_value) { damage = damage_value; }
};

