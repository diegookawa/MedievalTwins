#include "MagiaVerde.h"

MagiaVerde::MagiaVerde(sf::Vector2f position, bool right) :
Projetil(right)
{
    shape.setSize(Vector2f(50.0f, 15.0f));
    if(faceRight)
    {
        texture.loadFromFile("Texturas/projetil.png");
    }
    else
    {
        texture.loadFromFile("Texturas/projetilE.png");
    }
    shape.setTexture(&texture);
    shape.setPosition(position);
    xOrigem = position.x;
}

MagiaVerde::MagiaVerde():
Projetil()
{

}

MagiaVerde::~MagiaVerde()
{

}

bool MagiaVerde::atualizar()
{
    if(std::abs(xOrigem - shape.getPosition().x) < 400.0f)
    {
        if(faceRight)
            shape.move(1.0f, 0.0f);
        else
            shape.move(-1.0f, 0.0f);
    }
	return true;
}
