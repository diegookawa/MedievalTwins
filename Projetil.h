#ifndef PROJETIL_H_INCLUDED
#define PROJETIL_H_INCLUDED

#include "ENTIDADE.H"

class Projetil : public Entidade
{

protected:

    int dano;
    float xOrigem;
    bool faceRight;

public:
    Projetil(bool Right);
    Projetil();
    ~Projetil();

    void setDano(int n);
    int getDano();

    virtual bool atualizar() = 0;
    void atualizar(float deltaTime);


};

#endif // PROJETIL_H_INCLUDED
