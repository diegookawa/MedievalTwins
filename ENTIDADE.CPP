#include "Entidade.h"
#include "Collider.h"

Entidade::Entidade(){}

Entidade::~Entidade(){}

void Entidade::setX(float xx){

    x = xx;

}

float Entidade::getX(){

    return x;

}

void Entidade::setY(float yy){

    y = yy;

}

float Entidade::getY(){

    return y;

}

void Entidade::Draw(sf::RenderWindow* window)
{
    window->draw(shape);
}

