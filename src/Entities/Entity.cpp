#include "Entities/Entity.h"

namespace Entities {
    Entity::Entity(Texture::ID id, const int width, const int height, EntityType t):
        Ent(id, width, height), 
        type(t),
        ground(600), /*floor height, declared statcally, chenge after*/
        toDelete(false)
    {
    }

    Entity::Entity():
        Ent(),
        type(EntityType::None)
    {}

    Entity::~Entity() {}

    const EntityType Entity::getType() const {
        return type;
    }

    bool Entity::getToDelete() const {
        return toDelete;
    }

    void Entity::setToDelete(bool del){
        this->toDelete = del;
    }
}