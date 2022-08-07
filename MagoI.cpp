#include "MagoI.h"
#include <iostream>
#include <string>

using namespace std;

MagoI::MagoI(Plataforma* plat, ListaProjeteis* vec):
Inimigo(){

    shape.setSize(Vector2f(80.0f, 80.0f));
    texture.loadFromFile("Texturas/Dungeon/Sprites/Bosses/Mago/andar00.png");
    shape.setTexture(&texture);
    shape.setPosition(plat->shape.getPosition());
    Origem = shape.getPosition();
    Rand = sf::Vector2f(plat->shape.getGlobalBounds().width / 2.85f, plat->shape.getGlobalBounds().height);
    vel.x = 10;
    pAux = vec;
    cooldown = 0.0f;

}

MagoI::MagoI():
Inimigo()
{

}

MagoI::~MagoI(){}

void MagoI::atirar()
{
    if(cooldown >= 250.0f)
    {
        MagiaVerde* p;
        p = new MagiaVerde(shape.getPosition(), getFaceRight());
        pAux->incluir(static_cast<Projetil*>(p));
        cooldown = 0.0f;
    }
}

void MagoI::atualizar(float deltaTime){

    atirar();

    if(shape.getPosition().x > Origem.x + Rand.x){

        vel.x = -0.3;
        setFaceRight(false);

    }

    if(shape.getPosition().x < Origem.x - Rand.x){

        vel.x = 0.3;
        setFaceRight(true);

    }

    shape.setPosition(shape.getPosition().x, Origem.y - Rand.y);

    float aux = shape.getPosition().x;

    shape.move(vel);

    cooldown += std::abs(aux - shape.getPosition().x);

}

void MagoI::animar(){

    if(getFaceRight()){

            string caminho = "Texturas/Dungeon/Sprites/Bosses/Mago/andar0";

            if(tempoAnimacao.getElapsedTime().asSeconds() > 0.10f){

                if(indiceAnimacao == 4)
                    indiceAnimacao = 0;

                else{

                    caminho = caminho + to_string(indiceAnimacao) + ".png";
                    texture.loadFromFile(caminho);
                    caminho = "Texturas/Dungeon/Sprites/Bosses/Mago/andar0";
                    indiceAnimacao++;

                }

                shape.setTexture(&texture);

                tempoAnimacao.restart();

            }

        }

        if( !(getFaceRight()) ){

            string caminho = "Texturas/Dungeon/Sprites/Bosses/Mago/esquerda0";

            if(tempoAnimacao.getElapsedTime().asSeconds() > 0.10f){

                if(indiceAnimacao == 4)
                    indiceAnimacao = 0;

                else{

                    caminho = caminho + to_string(indiceAnimacao) + ".png";
                    texture.loadFromFile(caminho);
                    caminho = "Texturas/Dungeon/Sprites/Bosses/Mago/esquerda0";
                    indiceAnimacao++;

                }

                shape.setTexture(&texture);

                tempoAnimacao.restart();

            }

        }

}

void MagoI::setXorigem(float x){

    Origem.x = x;

}

float MagoI::getXorigem(){

    return Origem.x;
}

void MagoI::setYorigem(float y){

    Origem.y = y;

}

float MagoI::getYorigem(){

    return Origem.y;
}
