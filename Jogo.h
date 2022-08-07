#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Guerreiro.h"
#include <iostream>
#include "Floresta.h"
#include "Castelo.h"
#include "COLLIDER.H"
#include "Plataforma.h"
#include "Cavaleiro.h"
#include "Obstaculo.h"
#include "Caixa.h"
#include "Projetil.h"
#include <vector>
#include <time.h>
#include "ListaObstaculos.h"
#include "MagoP.h"
#include "MagoI.h"
#include "MenuPause.h"
#include "MenuPrincipal.h"
#include "MagiaMana.h"
#include <stdlib.h>
#include "Fim.h"

class Jogo
{
public:

    Jogo();
    ~Jogo();

    void executar();

    sf::Font fonte;

    Guerreiro guerreiro;
    MagoP mago;

    bool playable;
    bool playing;

    MenuPause menuP;
    MenuPrincipal menuPrin;

    Floresta floresta;
    Castelo castelo;
    Fim fim;

};

#endif // JOGO_H_INCLUDED
