#ifndef _CAIXA_H_
#define _CAIXA_H_

#include "Obstaculo.h"

class Caixa: public Obstaculo {

private:

public:

    Caixa(sf::Vector2f posi, sf::Vector2f size);
    Caixa();
    ~Caixa();

};

#endif // _CAIXA_H_
