#include "Personagem.h"

Personagem::Personagem():
Entidade(){

    xVel = 0;
    yVel = 0;
    alturaPulo = 150.0f;
    faceRight = true;
    canJump = true;
    vel.x = 0.0f;
    vel.y = 0.0f;
}

Personagem::~Personagem(){}

void Personagem::setXvel(float vel){

    xVel = vel;

}

float Personagem::getXvel(){

    return xVel;

}

void Personagem::setYvel(float vel){

    yVel = vel;

}

float Personagem::getYvel(){

    return yVel;

}

void Personagem::setFaceRight(bool right){

    faceRight = right;

}

bool Personagem::getFaceRight(){

    return faceRight;

}

void Personagem::onCollision(sf::Vector2f direction)
{
    if(direction.x > 0.0f)
    {
        vel.x = 0.0f;
    }
    else if(direction.x < 0.0f)
    {
        vel.x = 0.0f;
    }
    if(direction.y > 0.0f)
    {
        vel.y = 0.0f;
        canJump = false;
    }
    if(direction.y < 0.0f)
    {
        vel.y = 0.0f;
        canJump = true;
    }

}





