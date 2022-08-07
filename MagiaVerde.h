#ifndef MAGIAVERDE_H_INCLUDED
#define MAGIAVERDE_H_INCLUDED

#include "Projetil.h"

class MagiaVerde : public Projetil
{
public:

    MagiaVerde(sf::Vector2f position, bool right);
    MagiaVerde();
    ~MagiaVerde();

    bool atualizar();

};


#endif // MAGIAVERDE_H_INCLUDED
