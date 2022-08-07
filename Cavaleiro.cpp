#include "Cavaleiro.h"
#include <string>
#include <iostream>

using namespace std;

Cavaleiro::Cavaleiro(Plataforma* plat):
Inimigo(){

    shape.setSize(Vector2f(60.0f, 60.0f));
    texture.loadFromFile("Texturas/Dungeon/Sprites/Monsters/Cavaleiro/Variant1/andar00.png");
    shape.setTexture(&texture);
    shape.setPosition(plat->shape.getPosition());
    Origem = shape.getPosition();
    Rand = sf::Vector2f(plat->shape.getGlobalBounds().width / 2.75f, plat->shape.getGlobalBounds().height);
    vel.x = 10;


}

Cavaleiro::Cavaleiro():
Inimigo()
{

}

Cavaleiro::~Cavaleiro(){}


void Cavaleiro::atualizar(float deltaTime){

    if(shape.getPosition().x > Origem.x + Rand.x){

        vel.x = -0.3;
        setFaceRight(false);

    }

    if(shape.getPosition().x < Origem.x - Rand.x){

        vel.x = 0.3;
        setFaceRight(true);

    }

    shape.setPosition(shape.getPosition().x, Origem.y - Rand.y + 20);

    shape.move(vel);

}

void Cavaleiro::setXorigem(float x){

    Origem.x = x;

}

float Cavaleiro::getXorigem(){

    return Origem.x;
}

void Cavaleiro::setYorigem(float y){

    Origem.y = y;

}

float Cavaleiro::getYorigem(){

    return Origem.y;
}

void Cavaleiro::animar(){

    if(getFaceRight()){

            string caminho = "Texturas/Dungeon/Sprites/Monsters/Cavaleiro/Variant1/andar0";

            if(tempoAnimacao.getElapsedTime().asSeconds() > 0.10f){

                if(indiceAnimacao == 4)
                    indiceAnimacao = 0;

                else{

                    caminho = caminho + to_string(indiceAnimacao) + ".png";
                    texture.loadFromFile(caminho);
                    caminho = "Texturas/Dungeon/Sprites/Monsters/Cavaleiro/Variant1/andar0";
                    indiceAnimacao++;

                }

                shape.setTexture(&texture);

                tempoAnimacao.restart();

            }

        }

        if( !(getFaceRight()) ){

            string caminho = "Texturas/Dungeon/Sprites/Monsters/Cavaleiro/Variant1/esquerda0";

            if(tempoAnimacao.getElapsedTime().asSeconds() > 0.10f){

                if(indiceAnimacao == 4)
                    indiceAnimacao = 0;

                else{

                    caminho = caminho + to_string(indiceAnimacao) + ".png";
                    texture.loadFromFile(caminho);
                    caminho = "Texturas/Dungeon/Sprites/Monsters/Cavaleiro/Variant1/esquerda0";
                    indiceAnimacao++;

                }

                shape.setTexture(&texture);

                tempoAnimacao.restart();

            }

        }

}
