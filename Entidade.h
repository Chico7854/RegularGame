#pragma once
#include <SFML/Graphics.hpp>

class Entidade
{
//o que toda entidade deve ter? sprite,
// textura,
// posicao inicial(algumas entidades nao vao se mover, por isso implementar apenas a posicao inicial na classe mae)
// hitbox
// aparecer na tela(draw)
protected:
	sf::RenderWindow* window;// sf::Texture& texture, int largura_sprite, int altura_sprite
	sf::Sprite sprite;
	sf::Texture texture;
	sf::FloatRect hitbox;
	sf::Vector2f init_position;
public:
	Entidade():window(nullptr){}
	virtual ~Entidade(){}
	 
	virtual void executar() = 0;
	virtual void salvar() = 0;

	sf::FloatRect getHitbox(){ return hitbox; }
	void setWindow(sf::RenderWindow* window) { this->window = window; }
	void draw() { window->draw(sprite); }
};