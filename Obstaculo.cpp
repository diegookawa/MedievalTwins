#include "Obstaculo.h"

Obstaculo::Obstaculo():
Entidade()
{
    dano = 0;
}

Obstaculo::~Obstaculo(){}


void Obstaculo::atualizar(float deltaTime)
{

}

int Obstaculo::getDano()
{
    return dano;
}

void Obstaculo::setDano(int d)
{
    dano = d;
}
