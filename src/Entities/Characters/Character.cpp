#include "Entities/Characters/Character.h"

namespace Entities {
    Character::Character() : lives(0)
    {
    }

    Character::Character(Texture::ID id, const int width, const int height):
        Entity(id, width, height), 
        lives(0),
        speed(10.f),
        dx(0.f),
        dy(0.f)
    {}

    Character::~Character()
    {
    }
}