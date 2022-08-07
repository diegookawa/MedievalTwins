#ifndef BOLAFOGO_H_INCLUDED
#define BOLAFOGO_H_INCLUDED

#include "Projetil.h"

class BolaFogo : public Projetil
{
public:
    BolaFogo(sf::Vector2f position = sf::Vector2f(0.0f, 0.0f), bool right = true);
    ~BolaFogo();

    bool atualizar();
};

#endif // BOLAFOGO_H_INCLUDED
