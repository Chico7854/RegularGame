#pragma once
#include "Entidade.h"

class Personagem : public Entidade
{
protected:
	int num_vidas;
public:
	Personagem();
	~Personagem();

	virtual void executar() = 0;
	virtual void salvar() = 0;
	virtual void move() = 0;
};

