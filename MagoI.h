#ifndef MAGOI_H_INCLUDED
#define MAGOI_H_INCLUDED

#include "Inimigo.h"
#include "Guerreiro.h"
#include "MagoP.h"
#include "Plataforma.h"
#include "MagiaVerde.h"
#include "ListaProjeteis.h"
#include <vector>

class MagoI: public Inimigo{

private:

    float cooldown;

public:

    MagoI(Plataforma* plat, ListaProjeteis* vec);
    MagoI();
    ~MagoI();

    void setXorigem(float x);
    float getXorigem();
    void setYorigem(float y);
    float getYorigem();
    void atualizar(float deltaTime);

    void atirar();

    void animar();
    ListaProjeteis* pAux;

};

#endif // MAGOI_H_INCLUDED
