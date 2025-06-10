#include "Entities/Characters/Enemy.h"

namespace Entities {
    Enemy::Enemy(const Texture::ID id, const int sprite_width, const int sprite_height, const EntityType type):
        Character(id, sprite_width, sprite_height, type),
        evilness(rand() % 10)
    {
        dx = speed; //GAMBIARRA
    }

    Enemy::Enemy(): 
        evilness(-1) 
    {}

    Enemy::~Enemy() {}

    void Enemy::run()
    {
    }

    void Enemy::save()
    {
    }

    void Enemy::obstruct(Character* character) {
        Player* player = static_cast<Player*>(character);
        const sf::FloatRect charCoordinates = player->getGlobalHitbox();
        const sf::FloatRect obstacleCoordinates = getGlobalHitbox();


        if (charCoordinates.intersects(obstacleCoordinates)) {
            const float middlePointPlayer = charCoordinates.left + (charCoordinates.width / 2);
            const float middlePointEntity = obstacleCoordinates.left + (obstacleCoordinates.width / 2);

            const float playerDy = Constants::JUMP_SPEED / 1.5;
            float playerDx = Constants::SPEED * 2;

            if (middlePointPlayer < middlePointEntity) {
                playerDx *= -1;
            }

            player->setDy(playerDy);
            player->setDx(playerDx);
            player->setIsHurt(true);

            dx *= -1;
        }
    }
}