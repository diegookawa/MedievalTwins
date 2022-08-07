#include "ListaEntidades.h"
#include <iostream>

ListaEntidades::ListaEntidades()
{

}

ListaEntidades::~ListaEntidades()
{

}

void ListaEntidades::incluir(Entidade* pEn)
{
    lista.adicionar(pEn);
}

void ListaEntidades::executar(float deltaTime, sf::RenderWindow* window)
{
    Lista<Entidade>::Elemento<Entidade>* pAux = lista.begin();

    while(pAux != lista.end())
    {
        window->draw((pAux->getInfo()->shape));//Draw(window);
        std::cout << "Algo" << std::endl;
        pAux = pAux->getProximo();
    }
}
