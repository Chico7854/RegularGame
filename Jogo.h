#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Player.h"
#include"Inimigo.h"

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

	Player player1;
	Player player2;

	Inimigo youkai;
public:
	Jogo();
	virtual ~Jogo(){}

	void executar();
};