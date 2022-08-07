#ifndef BARRIL_H_INCLUDED
#define BARRIL_H_INCLUDED

#include "Obstaculo.h"

class Barril : public Obstaculo {

private:

public:

    Barril(sf::Vector2f posi, sf::Vector2f size);
    Barril();
    ~Barril();

};

#endif // BARRIL_H_INCLUDED
