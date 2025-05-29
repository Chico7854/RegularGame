#pragma once
#include "Obstaculo.h"

class Platform : public Obstaculo
{
private:
	int largura, altura;

public:
	Platform() {}
	Platform(sf::Texture& texture, int largura_sprite, int altura_sprite):
		largura(largura_sprite), 
		altura(altura_sprite)
	{
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, 0, largura, altura));
		sprite.setPosition(600, 500);
		hitbox = sf::FloatRect(600, 450, largura, altura);
	}
	virtual ~Platform() {}

	void executar() override {}
	void salvar() override {}
};