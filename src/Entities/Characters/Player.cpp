#include "Entities/Characters/Player.h"
#include "Entities/Characters/Enemy.h"

namespace Entities {
    Player::Player(Texture::ID id, const int width, const int height):
        Character(id, width, height, EntityType::Player),
        swordDamage(1),
        attack_radius(64.f)
    {
    }

    Player::Player():
        swordDamage(-1),
        attack_radius()
    {}

    Player::~Player() {}

    void Player::checkKeyboardInput() {
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) {
            dx = 0;       }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            dx = Constants::SPEED;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            dx = Constants::SPEED * -1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && getOnGround()) {
            setDy(Constants::JUMP_SPEED);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            // collide();
        }
    }

    void Player::collide(Enemy* pEnemy){
        const sf::FloatRect charCoordinates = getGlobalHitbox();
        const sf::FloatRect enemyCoordinates = pEnemy->getGlobalHitbox();


        if (charCoordinates.intersects(enemyCoordinates)) {
            const float middlePointPlayer = charCoordinates.left + (charCoordinates.width / 2);
            const float middlePointEntity = enemyCoordinates.left + (enemyCoordinates.width / 2);

            const float playerDy = Constants::JUMP_SPEED / 1.5;
            float playerDx = Constants::SPEED * 2;

            if (middlePointPlayer < middlePointEntity) {
                playerDx *= -1;
            }

            setDy(playerDy);
            setDx(playerDx);
            setIsHurt(true);
            moveHitboxSprite(playerDx, playerDy);

            pEnemy->setDx(pEnemy->getDx() * -1);
        }
    }

    sf::Vector2f Player::getPosition(){
        return sprite.getPosition();
    }

    void Player::save()
    {
    }

    void Player::exec()
    {
        if (!isHurt) {
            sprite.setColor(sf::Color::White);
            checkKeyboardInput();
        }
        else {
            sprite.setColor(sf::Color::Red);
        }
        dy += Constants::GRAVITY;
        if (dy > 20) {
            dy = 20;
        }
        moveHitboxSprite(dx, dy);
        if (!isHurt) {
            dx = 0;
        }

        setOnGround(false);

        // frame += 0.008f * time; // Animation speed
        // if (frame >= 8) {
        //     frame = 0;
        // }

        // /*animation*/
        // if (dx > 0) {
        //     sprite.setTextureRect(sf::IntRect(width * (int)frame, 0, width, height));
        // }
        // if (dx < 0) {
        //     sprite.setTextureRect(sf::IntRect(width * ((int)frame + 1), 0, -width, height));
        // }
    }
}