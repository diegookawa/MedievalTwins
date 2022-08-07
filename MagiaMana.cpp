#include "MagiaMana.h"

MagiaMana::MagiaMana(sf::Vector2f position, bool right) :
Projetil(right)
{
    shape.setSize(Vector2f(50.0f, 15.0f));
    if(faceRight)
    {
        texture.loadFromFile("Texturas/projetil1.png");
    }
    else
    {
        texture.loadFromFile("Texturas/projetil1E.png");
    }
    shape.setTexture(&texture);
    shape.setPosition(position);
    xOrigem = position.x;
}

MagiaMana::MagiaMana():
Projetil()
{

}

MagiaMana::~MagiaMana()
{

}

bool MagiaMana::atualizar()
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
