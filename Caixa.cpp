#include "Caixa.h"

Caixa::Caixa(sf::Vector2f posi, sf::Vector2f size):
Obstaculo(){

    shape.setSize(size);
    texture.loadFromFile("Texturas/caixa.jpg");
    shape.setPosition(posi);
    shape.setOrigin(size.x/2, size.y/6 );
    shape.setTexture(&texture);

}

Caixa::Caixa():
Obstaculo()
{

}

Caixa::~Caixa(){}
