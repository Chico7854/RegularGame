#pragma once
#include "Obstacle.h"
#include <SFML/Graphics.hpp>

class HardObstacle : public Obstacle //implement damage, +50 damage for tounching it and it thwrows the player back
{
private:
	float damage;
	float frame;
public:
	HardObstacle() : damage(10.f), frame(0) {}
	HardObstacle(sf::Texture& texture,int sprite_width, int sprite_height): Obstacle(texture, sprite_width, sprite_height), damage(10.f), frame(0)
	{
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, 0, width, height));
		sprite.setPosition(400, ground - height);
		hitbox = sf::FloatRect(400, ground - height, width, height);
	}
	virtual ~HardObstacle() {}
	void run() override {}
	void save() override {}
	void animation(float time);
	float getDamage() const { return damage; }
	void setDamage(float damage_value) { damage = damage_value; }

};