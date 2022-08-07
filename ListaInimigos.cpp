#include "ListaInimigos.h"

ListaInimigos::ListaInimigos(){}

ListaInimigos::~ListaInimigos(){}

void ListaInimigos::incluir(Inimigo* pInimigo){

    lista.push_back(pInimigo);

}

void ListaInimigos::deletar(list <Inimigo*>::iterator i){


    lista.erase(i);

}

void ListaInimigos::limpar()
{
    for(itr = lista.begin(); itr != lista.end(); ++itr)
    {
        lista.erase(itr);
    }
    lista.clear();
}

