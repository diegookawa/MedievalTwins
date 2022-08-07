#ifndef _LISTA_INIMIGOS_H_
#define _LISTA_INIMIGOS_H_

#include "Inimigo.h"
#include <list>

using namespace std;

class ListaInimigos {

private:

public:

    ~ListaInimigos();
    ListaInimigos();

    list <Inimigo*> lista;
    list <Inimigo*>::iterator itr;

    void deletar (list <Inimigo*>::iterator i);
    void incluir(Inimigo* pInimigo);
    void limpar();


};

#endif // _LISTA_INIMIGOS_H_
