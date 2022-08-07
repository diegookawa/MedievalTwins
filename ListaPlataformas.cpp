#pragma once
#include "ListaPlataformas.h"

ListaPlataformas::ListaPlataformas()
{

}

ListaPlataformas::~ListaPlataformas()
{

}

void ListaPlataformas::incluir(Plataforma* plat)
{
    plataformas.push_back(plat);
}

void ListaPlataformas::limpar()
{
    for(itr = plataformas.begin(); itr != plataformas.end(); ++itr)
    {
        plataformas.erase(itr);
    }
    plataformas.clear();
}

