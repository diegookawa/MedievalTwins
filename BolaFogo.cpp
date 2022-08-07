#include "BolaFogo.h"

BolaFogo::BolaFogo(sf::Vector2f position, bool right) :
Projetil(right)
{
    shape.setSize(Vector2f(75.0f, 50.0f));
    if(faceRight)
    {
        texture.loadFromFile("Texturas/projetil2.png");
    }
    else
    {
        texture.loadFromFile("Texturas/projetil2E.png");
    }
    shape.setTexture(&texture);
    shape.setPosition(position);
    xOrigem = position.x;
}

BolaFogo::~BolaFogo()
{

}

bool BolaFogo::atualizar()
{
    if(std::abs(xOrigem - shape.getPosition().x) < 3000.0f)
    {

        if(faceRight)
            shape.move(0.75f, 0.0f);
        else
            shape.move(-0.75f, 0.0f);
    }
	return true;
}
