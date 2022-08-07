#ifndef _LISTA_OBSTACULOS_H_
#define _LISTA_OBSTACULOS_H_

#include "Obstaculo.h"
#include <map>

using namespace std;

class ListaObstaculos{

private:

public:

    map<int, Obstaculo> lista;
    map<int, Obstaculo>::iterator itr;

    ~ListaObstaculos();
    ListaObstaculos();

    void incluir (int posicao, Obstaculo obstaculo);
    void limpar();

};

#endif // _LISTA_OBSTACULOS_H_
