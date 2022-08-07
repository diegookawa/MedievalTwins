#ifndef LISTAPLATAFORMAS_H_INCLUDED
#define LISTAPLATAFORMAS_H_INCLUDED

#include "Plataforma.h"
#include <vector>

using namespace std;

class ListaPlataformas
{
private:

public:

    ~ListaPlataformas();
    ListaPlataformas();

    vector<Plataforma*> plataformas;
    vector<Plataforma*> getLista(){ return plataformas; }
    vector<Plataforma*>::iterator itr;
    void incluir(Plataforma* plat);
    void limpar();


};

#endif // LISTAPLATAFORMAS_H_INCLUDED
