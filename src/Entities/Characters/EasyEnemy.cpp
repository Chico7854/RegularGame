#include "Entities/Characters/EasyEnemy.h"
#include "Utility/Constants.h"
#include "Entities/Characters/Enemy.h"

namespace Entities {
    EasyEnemy::EasyEnemy(Texture::ID id, int width, int height):
        Enemy(id, width, height)
    {}

    EasyEnemy::~EasyEnemy() {}

    void EasyEnemy::run()
    {
    }

    void EasyEnemy::save()
    {
    }

    void EasyEnemy::obstruct(Player* player) {
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

    void EasyEnemy::update()
    {
        /*GAMBIARRA*/
        dy += Constants::GRAVITY;
        if (sprite.getGlobalBounds().left + dx < 0 || sprite.getGlobalBounds().left + sprite.getGlobalBounds().width + dx > Constants::WINDOW_WIDTH) {
            dx = -dx; // Reverse direction if hits borders
        }
        moveHitboxSprite(dx, dy);

        // frame += 0.008f * time; // Animation speed
        // if (frame >= 6) {
        //     frame = 0;
        // }

        // if (dx > 0) {
        //     sprite.setTextureRect(sf::IntRect(width * (int)frame, 0, width, height));
        // }
        // if (dx < 0) {
        //     sprite.setTextureRect(sf::IntRect(width * ((int)frame + 1), 0, -width, height));
        // }
    }
}