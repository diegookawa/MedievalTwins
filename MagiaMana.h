#ifndef MAGIA_H_INCLUDED
#define MAGIA_H_INCLUDED

#include "Projetil.h"

class MagiaMana : public Projetil
{
public:

    MagiaMana(sf::Vector2f position, bool right);
    MagiaMana();
    ~MagiaMana();

    bool atualizar();

};

#endif // MAGIA_H_INCLUDED
