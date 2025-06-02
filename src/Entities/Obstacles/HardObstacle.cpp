#include "Entities/Obstacles/HardObstacle.h"

namespace Entities {
	void HardObstacle::animation(float time)
	{
		frame += 0.005f * time;
		if (frame > 7) {
			frame = 0;
		}
		sprite.setTextureRect(sf::IntRect(static_cast<int>(frame) * width,0 , width, height));
	}
}