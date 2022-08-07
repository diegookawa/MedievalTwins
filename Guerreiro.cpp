#include "Guerreiro.h"
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace sf;

Guerreiro::Guerreiro():
Jogador(){

    shape.setSize(Vector2f(60.0f, 60.0f));
    texture.loadFromFile("Texturas/Dungeon/Sprites/Player/Sword/Defence0/parado0.1.png");
    shape.setTexture(&texture);
    shape.setPosition(Vector2f(0.0f, -500.0f));
    isAttacking = false;
    setNumVidas(5);

}

Guerreiro::~Guerreiro(){}

void Guerreiro::atualizar(float deltaTime)
{
    if(vel.y < 0.001f && vel.y > - 0.001f)
        canJump = true;

    xVel = 0;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        xVel = -450.0f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        xVel = 450.0f;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump){

        canJump = false;

        vel.y = -sqrt(2.0f * 981.0f * alturaPulo);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){

        isAttacking = true;
    }
    else
        isAttacking = false;

        vel.y += 981.0f * deltaTime;

    vel.x = xVel;

    float deltaTimeInv = (std::clock() - startInv)/(float)CLOCKS_PER_SEC;
    if(deltaTimeInv >= 2.0f && isInvincible)
    {
        isInvincible = false;
    }


    shape.move(vel * deltaTime);
}
