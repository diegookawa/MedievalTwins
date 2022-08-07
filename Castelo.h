#ifndef _CASTELO_H_
#define _CASTELO_H_

#include "Fase.h"
#include <iostream>
#include "Plataforma.h"
#include "Cavaleiro.h"
#include "Obstaculo.h"
#include "Barril.h"
#include "Projetil.h"
#include <vector>
#include "MagoI.h"
#include "MenuPause.h"
#include "MenuPrincipal.h"
#include "MagiaMana.h"
#include "Espinho.h"

class Castelo: public Fase{

private:



public:

    Castelo();
    ~Castelo();

    void build();

};

#endif // _CASTELO_H_
