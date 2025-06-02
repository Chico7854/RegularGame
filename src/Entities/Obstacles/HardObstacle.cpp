#include "Entities/Obstacles/HardObstacle.h"

namespace Entities {
	void HardObstacle::update(float time)
	{
		frame += 0.005f * time;
		if (frame > 7) {
			frame = 0;
		}
	}
}