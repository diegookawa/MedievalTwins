#include "Dragao.h"
#include <string>


Dragao::Dragao(Plataforma* plat, ListaProjeteis* pLista):
Inimigo()
{

    shape.setSize(Vector2f(400.0f, 200.0f));
    texture.loadFromFile("Texturas/Dragao/dragao0.png");
    shape.setTexture(&texture);
    shape.setPosition(plat->shape.getPosition());
    Origem.y = shape.getPosition().y;
    Rand.y = plat->shape.getGlobalBounds().height;
    this->pLista = pLista;
    isInvincible = false;
    setNumVidas(5);

}

Dragao::Dragao():
Inimigo()
{

}

Dragao::~Dragao(){}

void Dragao::atualizar(float deltaTime){

    atirar();
    shape.setPosition(shape.getPosition().x, Origem.y - Rand.y - 100);
    float deltaTimeInv = (std::clock() - startInv)/(float)CLOCKS_PER_SEC;
    if(deltaTimeInv >= 1.5f && isInvincible)
    {
        startInv = std::clock();
        isInvincible = false;
    }

}

void Dragao::animar()
{

}

int Dragao::getNumVidas()
{
    return numVidas;
}

void Dragao::setNumVidas(int n)
{
    numVidas = n;
}

void Dragao::atirar()
{
    float deltaTime = (std::clock() - cooldown)/(float)CLOCKS_PER_SEC;
    if(deltaTime >= 2.0f)
    {
        BolaFogo* p;

        p = new BolaFogo(sf::Vector2f(shape.getPosition().x, shape.getPosition().y + 75), false);
        pLista->incluir(static_cast<Projetil*>(p));
        cooldown = std::clock();
    }
}
