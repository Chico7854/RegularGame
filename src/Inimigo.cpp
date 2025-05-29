#include"Inimigo.h"

Inimigo::Inimigo(sf::Texture& texture, int largura_sprite, int altura_sprite): 
	ground(600), 
	frame(0), 
	speed(0.3f), 
	largura(largura_sprite), 
	altura(altura_sprite),
	dx(0.1f),
	dy(0.1f)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, largura, altura));
	sprite.setPosition(0, ground - altura);
	hitbox = sf::FloatRect(0, ground - altura, largura, altura);
}
void Inimigo::setInitPosition(sf::Vector2f pos)
{
	init_position = pos;
	hitbox.left = pos.x;
	hitbox.top = pos.y;
	sprite.setPosition(pos);
}
void Inimigo::executar()
{
}
void Inimigo::salvar()
{
}
void Inimigo::move()
{
}
void Inimigo::update(float time)
{
	hitbox.left += dx * time;
	if (hitbox.left < 0 || hitbox.left + largura > window->getSize().x) {
		dx = -dx; // Inverte a direção se atingir as bordas
	}

	frame += 0.008f * time;//velocidade da animacao
	if (frame >= 6) {
		frame = 0;
	}

	if (dx > 0) {
		sprite.setTextureRect(sf::IntRect(largura * (int)frame, 0, largura, altura));
	}
	if (dx < 0) {
		sprite.setTextureRect(sf::IntRect(largura * ((int)frame + 1), 0, -largura, altura));
	}
	

	sprite.setPosition(hitbox.left, hitbox.top);
}