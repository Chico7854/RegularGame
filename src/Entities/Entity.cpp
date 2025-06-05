#include "Entities/Entity.h"

namespace Entities {
    Entity::Entity(Texture::ID id, const int width, const int height, Constants::TYPE t):
        Ent(id, width, height), 
        type(t),
        ground(600) /*floor height, declared statcally, chenge after*/
    {
    }

    Entity::Entity():
        Ent(),
        type(Constants::TYPE::None)
    {}

    Entity::~Entity() {}

    const Constants::TYPE Entity::getType() const {
        return type;
    }
}