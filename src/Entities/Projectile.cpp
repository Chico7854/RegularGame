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
        updateHitbox();
    }

    void Projectile::moveHitboxSprite(float dx, float dy) {
        sprite.move(dx, dy);
        updateHitbox();
    }

    void Projectile::obstruct(Character* character){//took from enemy class
        Player* player = static_cast<Player*>(character);
        const sf::FloatRect charCoordinates = player->getGlobalHitbox();
        const sf::FloatRect ballCoordinates = getGlobalHitbox();

        if (charCoordinates.intersects(ballCoordinates)) {
            const float middlePointPlayer = charCoordinates.left + (charCoordinates.width / 2);
            const float middlePointEntity = ballCoordinates.left + (ballCoordinates.width / 2);

            const float playerDy = Constants::JUMP_SPEED / 1.5;
            float playerDx = Constants::SPEED * 2;

            if (middlePointPlayer < middlePointEntity) {
                playerDx *= -1;
            }

            player->setDy(playerDy);
            player->setDx(playerDx);
            player->setIsHurt(true);

            setActive(false);
        }
    }

    void Projectile::exec() {
        //dx += speed/2;
        dy += Constants::GRAVITY/2; //still no gravity

        if (sprite.getGlobalBounds().left + dx < 0 || 
            sprite.getGlobalBounds().top + dy < 0 || 
            sprite.getGlobalBounds().left + sprite.getGlobalBounds().width + dx > Constants::WINDOW_WIDTH ) {
            active = false; 
        }   
        moveHitboxSprite(dx, dy);
    }
}