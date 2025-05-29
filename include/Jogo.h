#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Entidade.h"
#include"Player.h"
#include"Inimigo.h"
#include"Platform.h"

class Jogo
{
private:
	sf::RenderWindow window;
	sf::Texture textfloor, textbg, textshinobi, textyoukai, textsamurai, textplat;
	sf::Sprite bg;
	sf::Sprite floor;
	sf::Clock clock;
	const float height_floor, speed;
	float frame2 ;

	Player player1;
	Player player2;

	Inimigo youkai;

	Platform platform;
public:
	Jogo();
	virtual ~Jogo(){}
	void collision_x();
	void executar();
};