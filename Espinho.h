#ifndef ESPINHO_H_INCLUDED
#define ESPINHO_H_INCLUDED

#include "Obstaculo.h"

class Espinho : public Obstaculo
{
public:

    Espinho(sf::Vector2f posi, sf::Vector2f size);
    Espinho();
    ~Espinho();
};

#endif // ESPINHO_H_INCLUDED
