#include "MagoP.h"

#include <SFML/Graphics.hpp>

using namespace sf;

MagoP::MagoP():
Jogador(){

    shape.setSize(Vector2f(60.0f, 60.0f));
    texture.loadFromFile("Texturas/Dungeon/Sprites/Player/Scepter/Defence1/mago_idle_1.png");
    shape.setTexture(&texture);
    shape.setPosition(Vector2f(0.0f, -500.0f));
    isAttacking = false;

}

MagoP::~MagoP(){}

void MagoP::atualizar(float deltaTime)
{
    if(vel.y < 0.001f && vel.y > - 0.001f)
        canJump = true;

    vel.x = 0;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        vel.x = -450.0f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        vel.x = 450.0f;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump){

        canJump = false;

        vel.y = -sqrt(2.0f * 981.0f * alturaPulo);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){

        isAttacking = true;
    }
    else
        isAttacking = false;

    float deltaTimeInv = (std::clock() - startInv)/(float)CLOCKS_PER_SEC;
    if(deltaTimeInv >= 2.0f && isInvincible)
    {
        isInvincible = false;
    }

    vel.y += 981.0f * deltaTime;

    shape.move(vel * deltaTime);
}
