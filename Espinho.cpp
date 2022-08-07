#include "Espinho.h"

Espinho::Espinho(sf::Vector2f posi, sf::Vector2f size):
Obstaculo()
{
    shape.setSize(size);
    texture.loadFromFile("Texturas/espinho.png");
    shape.setPosition(posi);
    shape.setOrigin(size.x/2, size.y/6 );
    shape.setTexture(&texture);
    setDano(1);

}

Espinho::Espinho():
Obstaculo()
{

}

Espinho::~Espinho()
{

}
