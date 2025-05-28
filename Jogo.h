#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Player.h"

class Jogo
{
private:
	sf::RenderWindow window;
	sf::Texture textfloor, textbg, textshinobi, textyoukai, textsamurai, textplat;
	sf::Sprite bg;
	sf::Sprite floor;
	sf::Sprite platform;
	sf::Clock clock;
	const float height_floor, speed;
	float frame2 ;
public:
	Jogo();
	~Jogo();

	void executar();
};