#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "Personagem.h"
#include <time.h>

class Jogador: public Personagem {

protected:

    int numVidas;


public:

    Jogador();
    ~Jogador();

    void setNumVidas(int num);
    int getNumVidas();
    void Draw(sf::RenderWindow window);

    virtual void atualizar(float deltaTime) = 0;

    bool isAttacking;
    bool isInvincible;

    clock_t startInv;

};

#endif // _JOGADOR_H_
