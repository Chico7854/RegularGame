#include "Entities/Entity.h"

namespace Entities {
    Entity::Entity(Texture::ID id, const int width, const int height, EntityType t):
        Ent(id, width, height), 
        type(t),
        toDelete(false)
    {
        setHitbox({0.f, 0.f, (float)width, (float)height});
    }

    Entity::Entity():
        Ent(),
        type(EntityType::None)
    {}

    Entity::~Entity() {}

    sf::FloatRect Entity::getGlobalHitbox() const {
        return hitbox;
    }

    void Entity::setHitbox(const sf::FloatRect& hb) {
        hitbox = hb;
    }

    void Entity::updateHitbox() {
        setHitbox(sprite.getGlobalBounds());
    }

    void Entity::setSpritePosition(float x, float y) {
        sprite.setPosition(x, y);
        updateHitbox();
    }

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