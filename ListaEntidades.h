#ifndef LISTAENTIDADES_H_INCLUDED
#define LISTAENTIDADES_H_INCLUDED

#include "Lista.h"
#include "ENTIDADE.H"

class ListaEntidades
{
private:

public:

    ListaEntidades();
    ~ListaEntidades();

    Lista<Entidade> lista;

    void incluir(Entidade* pEn);

    void executar(float deltaTime, sf::RenderWindow* window);

};

#endif // LISTAENTIDADES_H_INCLUDED
