#ifndef _PLATAFORMA_H_
#define _PLATAFORMA_H_

#include "ENTIDADE.H"

class Plataforma: public Entidade {

private:

public:

    Plataforma(Texture* textura, Vector2f size, Vector2f position);
    Plataforma();
    ~Plataforma();

    void atualizar(float deltaTime);

    bool isOccupied;

};

#endif // _PLATAFORMA_H_
