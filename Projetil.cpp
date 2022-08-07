#pragma once
#include "Projetil.h"

Projetil::Projetil(bool Right):
Entidade()
{

    shape.setSize(Vector2f(50.0f, 15.0f));
    faceRight = Right;

}

Projetil::Projetil():
Entidade()
{

}

Projetil::~Projetil()
{

}

void Projetil::setDano(int n)
{
    dano = n;
}

int Projetil::getDano()
{
    return dano;
}

void Projetil::atualizar(float deltaTime)
{

}
