#include "ListaProjeteis.h"

ListaProjeteis::ListaProjeteis()
{

}

ListaProjeteis::~ListaProjeteis(){}

void ListaProjeteis::incluir(Projetil* pProj){

    deck.push_back(pProj);

}

void ListaProjeteis::deletar(std::list <Projetil*>::iterator i)
{
    deck.erase(i);
}

void ListaProjeteis::limpar()
{
    for(itr = deck.begin(); itr != deck.end(); ++itr)
    {
        deck.erase(itr);
    }
    deck.clear();
}
