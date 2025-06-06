#include "Entities/Projectile.h"
#include "Utility/Constants.h"

namespace Entities {
    Projectile::Projectile(Texture::ID id, const int width, const int height):
        speed(Constants::SPEED),
        dx(0.f),
        dy(0.f),
        direction(false)
    {}

    Projectile::Projectile(): Entity(), speed(0), dx(0.f), dy(0.f), direction(false){}

    Projectile::~Projectile()
    {
    }

    void Projectile::save() {
    }

    void Projectile::setInitPosition(float x, float y) {
        sprite.setPosition(x, y);
        sprite.updateHitbox();
    }

    void Projectile::moveHitboxSprite(float dx, float dy) {
        sprite.move(dx, dy);
        sprite.updateHitbox();
    }

    void Projectile::update() {
        dx = speed;
        if (sprite.getGlobalBounds().left + dx < 0 || sprite.getGlobalBounds().left + sprite.getGlobalBounds().width + dx > Constants::WINDOW_WIDTH) {
            // Implement destruction
        }
        moveHitboxSprite(dx, dy);
    }
}