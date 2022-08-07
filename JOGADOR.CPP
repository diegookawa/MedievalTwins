#include "Jogador.h"
#include <iostream>

using namespace std;

Jogador::Jogador():
Personagem(){

    numVidas = 3;
    isInvincible = false;
    isAttacking = false;
}

Jogador::~Jogador(){}

void Jogador::setNumVidas(int num){

    numVidas = num;

}

int Jogador::getNumVidas(){

    return numVidas;

}


void Jogador::Draw(sf::RenderWindow window)
{
    window.draw(shape);
}
