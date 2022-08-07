#include "Barril.h"

Barril::Barril(sf::Vector2f posi, sf::Vector2f size):
Obstaculo(){

    shape.setSize(size);
    texture.loadFromFile("Texturas/barril.png");
    shape.setPosition(posi);
    shape.setOrigin(size.x/2, size.y/6 );
    shape.setTexture(&texture);

}

Barril::Barril():
Obstaculo()
{

}

Barril::~Barril(){}
