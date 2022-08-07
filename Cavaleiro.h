#ifndef _CAVALEIRO_H_
#define _CAVALEIRO_H_

#include "Inimigo.h"

#include "Plataforma.h"

class Cavaleiro: public Inimigo{

private:

public:

    Cavaleiro(Plataforma* plat);
    Cavaleiro();
    ~Cavaleiro();

    void setXorigem(float x);
    float getXorigem();
    void setYorigem(float y);
    float getYorigem();
    void atualizar(float deltaTime);
    void animar();

};

#endif // _CAVALEIRO_H_
