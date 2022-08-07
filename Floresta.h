#ifndef _FLORESTA_H_
#define _FLORESTA_H_

#include "Fase.h"
#include "Guerreiro.h"
#include <iostream>
#include "Plataforma.h"
#include "Cavaleiro.h"
#include "Obstaculo.h"
#include "Caixa.h"
#include "Projetil.h"
#include <vector>
#include <time.h>
#include "MagoP.h"
#include "MagoI.h"
#include "MenuPause.h"
#include "MenuPrincipal.h"
#include "MagiaMana.h"
#include "Barril.h"

class Floresta: public Fase{

private:



public:

    Floresta();
    ~Floresta();

    void build();

};

#endif // _FLORESTA_H_
