#pragma once
#include "Entidade.h"
class Obstaculo : public Entidade
{
protected:
	bool danoso;
public:
	Obstaculo() : danoso(false) {}
	Obstaculo(sf::Texture& texture, int largura_sprite, int altura_sprite) {
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, 0, largura_sprite, altura_sprite));
		hitbox = sf::FloatRect(0, 0, largura_sprite, altura_sprite);
	}
	virtual ~Obstaculo() {}
	virtual void executar() override {}
	virtual void salvar() override {}
	void setDanoso(bool danoso) { this->danoso = danoso; }
	bool getDanoso() const { return danoso; }
};

