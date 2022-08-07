#include "ListaObstaculos.h"

ListaObstaculos::ListaObstaculos()
{

}

ListaObstaculos::~ListaObstaculos(){}

void ListaObstaculos::incluir(int posicao, Obstaculo obstaculo){

    lista.insert(pair <int, Obstaculo> (posicao, obstaculo));

}

void ListaObstaculos::limpar()
{
    for(itr = lista.begin(); itr != lista.end(); ++itr)
    {
        lista.erase(itr);
    }
    lista.clear();
}

