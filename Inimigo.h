#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include "Personagem.h"

class Inimigo: public Personagem{

protected:

public:

    Inimigo();
    ~Inimigo();

    Clock tempoAnimacao;
    int indiceAnimacao;

    sf::Vector2f Origem;
    sf::Vector2f Rand;

    virtual void atualizar(float deltaTime) = 0;
    virtual void animar() = 0;


};

#endif // _INIMIGO_H_
