#include "Entities/Entity.h"

namespace Entities {
    Entity::Entity(Texture::ID id, const int width, const int height): 
        Ent(id, width, height), 
        ground(600) /*floor height, declared statcally, chenge after*/
    {
        sprite.setPosition(0.f, ground - height);
    }

}