#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Entity.h"
#include"Player.h"
#include"Enemy.h"
#include"Platform.h"
#include"HardObstacle.h"
#include"MediumObstacle.h"
#include"EasyEnemy.h"

class Game
{
private:
    sf::RenderWindow window;
    sf::Texture floorTexture, bgTexture, shinobiTexture, youkaiTexture, samuraiTexture, platformTexture, hardObsTexture;
    sf::Sprite background;
    sf::Sprite floor;
    sf::Clock clock;
    const float floorHeight, speed;
    float frame2;

    Player player1;
    Player player2;

    EasyEnemy youkai;

    Platform platform;
	HardObstacle hardObstacle;
	MediumObstacle mediumObstacle;
public:
    Game();
    virtual ~Game() {}
    void collisionX();
    void run();
};