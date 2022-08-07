#ifndef _OBSTACULO_H_
#define _OBSTACULO_H_

#include "ENTIDADE.H"

class Obstaculo: public Entidade {

protected:

    float altura;
    float largura;
    int dano;

public:

    Obstaculo();
    ~Obstaculo();

    void atualizar(float deltaTime);
    int getDano();
    void setDano(int d);



};

#endif // _OBSTACULO_H_
