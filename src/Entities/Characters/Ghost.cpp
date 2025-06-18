#include "Entities/Characters/Ghost.h"

namespace Entities {
    Ghost::Ghost():
        Enemy(Texture::Ghost, Constants::GHOST_WIDTH, Constants::GHOST_HEIGHT, EntityType::Ghost),
        bloodDamage(1)
    {}

    Ghost::~Ghost() {}

    const int Ghost::getBloodDamage() const {
        return bloodDamage;
    }
}