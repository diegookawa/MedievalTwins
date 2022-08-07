#ifndef DRAGAO_H_INCLUDED
#define DRAGAO_H_INCLUDED

#include "Inimigo.h"
#include "ListaProjeteis.h"
#include "Plataforma.h"
#include "BolaFogo.h"
#include <string.h>
#include <time.h>

class Dragao : public Inimigo
{

private:

    int numVidas;

public:
    Dragao(Plataforma* plat, ListaProjeteis* pLista);
    Dragao();
    ~Dragao();

    void atualizar(float deltaTime);
    void atirar();
    void animar();

    int getNumVidas();
    void setNumVidas(int n);

    clock_t cooldown;
    clock_t startInv;

    ListaProjeteis* pLista;
    bool isInvincible;
};

#endif // DRAGAO_H_INCLUDED
