#ifndef _FASE_H_
#define _FASE_H_

#include "Entidade.h"
#include "COLLIDER.H"

class Fase: public Entidade{

protected:

public:

    Fase();
    ~Fase();

    Collider colisor;

    void atualizar(float deltaTime);

};

#endif // _FASE_H_
