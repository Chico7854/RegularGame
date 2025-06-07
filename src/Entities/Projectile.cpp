#include "Entities/Projectile.h"
#include "Utility/Constants.h"

namespace Entities {
    Projectile::Projectile(Texture::ID id, const int width, const int height):
        Entity(id, width, height, EntityType::Ball),
        active(true),
        speed(Constants::BALL_SPEED),
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
        if (!active) return;

        dx = speed;
        dy = 0.f; //still no gravity

        if (sprite.getGlobalBounds().left + dx < 0 || sprite.getGlobalBounds().left + sprite.getGlobalBounds().width + dx > Constants::WINDOW_WIDTH) {
            active = false; 
        }   
        moveHitboxSprite(dx, dy);
    }
}