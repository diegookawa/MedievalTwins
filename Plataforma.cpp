#include "Plataforma.h"
#include "ENTIDADE.H"

Plataforma::Plataforma(Texture* textura, Vector2f size, Vector2f position):
Entidade(){

    shape.setSize(size);
    shape.setPosition(position);
    shape.setOrigin(size.x/2, size.y/6 );
    shape.setTexture(textura);
    isOccupied = false;

}

Plataforma::Plataforma():
Entidade()
{

}

Plataforma::~Plataforma(){}

void Plataforma::atualizar(float deltaTime)
{

}


