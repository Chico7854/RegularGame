#include "Entities/Obstacles/Platform.h"

namespace Entities {
    Platform::Platform(Texture::ID id, int sprite_width, int sprite_height):
        Obstacle(id, sprite_width, sprite_height)
    {}

    Platform::Platform(): Obstacle() {}

    Platform::~Platform() {}

    void Platform::obstruct(Entities::Character* character) {
        nonDamageCollision(character);
    }
}