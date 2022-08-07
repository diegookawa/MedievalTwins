#ifndef LISTAPROJETEIS_H_INCLUDED
#define LISTAPROJETEIS_H_INCLUDED

#include <list>
#include "Projetil.h"

class ListaProjeteis
{
private:

public:

    ListaProjeteis();
    ~ListaProjeteis();

    std::list <Projetil*> deck;
    std::list <Projetil*>::iterator itr;

    void deletar (std::list <Projetil*>::iterator i);
    void incluir(Projetil* pProj);
    void limpar();

};

#endif // LISTAPROJETEIS_H_INCLUDED
