#include "Entities/Characters/Player.h"
#include "Entities/Characters/Enemy.h"
#include "States/Stages/Stage.h"

namespace Entities {
    Player::Player(Texture::ID id, const int width, const int height, const bool isP1):
        Character(id, width, height, EntityType::Player),
        attack_radius(64.f),
        isAttacking(false),
        swordDamage(1),
        isPlayer1(isP1)
    {
        lifes = 30;
    }

    Player::Player():
        attack_radius(-1.f),
        swordDamage(-1.f),
        isPlayer1(false)
    {}

    Player::~Player() {}

    void Player::checkKeyboardInput() {
        if (isPlayer1) {
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
                isAttacking = true;
            }
        }
        else {
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
                dx = 0;       }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                dx = Constants::SPEED;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                dx = Constants::SPEED * -1;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && getOnGround()) {
                setDy(Constants::JUMP_SPEED);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                isAttacking = true;
            }
        }
    }

    void Player::collide(Enemy* pEnemy){
        sf::FloatRect charCoordinates = getGlobalHitbox();
        const sf::FloatRect enemyCoordinates = pEnemy->getGlobalHitbox();

        if (isAttacking) {
            charCoordinates.width += (attack_radius * 2);
            charCoordinates.left -= attack_radius;
        }


        if (charCoordinates.intersects(enemyCoordinates)) {
            const float middlePointPlayer = charCoordinates.left + (charCoordinates.width / 2);
            const float middlePointEntity = enemyCoordinates.left + (enemyCoordinates.width / 2);

            pEnemy->setDx(pEnemy->getDx() * -1);

            if (isAttacking) {
                pEnemy->setLife(pEnemy->getLife() - 1);
                pEnemy->setIsHurt(true);
                pEnemy->setDy(Constants::JUMP_SPEED / 1.5);
                pEnemy->moveHitboxSprite(pEnemy->getDx(), pEnemy->getDy());
                if (pEnemy->getType() == Entities::EntityType::Youkai){
                    pStage->updatePoints(5);
                } else if (pEnemy->getType() == Entities::EntityType::Cannonhead){
                    pStage->updatePoints(10);
                } else if (pEnemy->getType() == Entities::EntityType::Ghost){
                    pStage->updatePoints(15);
                }
                if (pEnemy->getLife() <= 0){
                    pEnemy->setToDelete(true);  
                }
            }
            else {
                const float playerDy = Constants::JUMP_SPEED / 1.5;
                float playerDx = Constants::SPEED * 2;

                if (middlePointPlayer < middlePointEntity) {
                    playerDx *= -1;
                }

                pEnemy->damage(this);
                setDy(playerDy);
                setDx(playerDx);
                setIsHurt(true);
                moveHitboxSprite(playerDx, playerDy);
            }
        }
    }

    void Player::setStage(States::Stage* pSt){
        pStage = pSt;
    }

    States::Stage* Player::getStage(){
        return pStage;
    }

    void Player::setIsAttacking(const bool isAttack) {
        isAttacking = isAttack;
    }

    const bool Player::getIsAttacking() const {
        return isAttacking;
    }

    void Player::save()
    {
        json data = Character::saveDataBuffer();
        data["isPlayer1"] = isPlayer1;
        data["isAttacking"] = isAttacking;

        buffer << data.dump(4) << ",\n";
        buffer.flush();
    }

    void Player::exec()
    {
        std::cout << lifes << "\n";
        if (!isHurt) {
            sprite.setColor(sf::Color::White);
            isAttacking = false;
            checkKeyboardInput();
        }
        else {
            sprite.setColor(sf::Color::Red);
        }
        dy += Constants::GRAVITY;
        if (dy > 20) {
            dy = 20;    //terminal velocity
        }
        moveHitboxSprite(dx, dy);
        if (!isHurt) {
            dx = 0;
        }

        setOnGround(false);
    }
}