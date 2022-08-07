#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Entidade.h"

class Personagem: public Entidade {

protected:

    float xVel;
    float yVel;
    float alturaPulo;
    bool faceRight;
    sf::Vector2f vel;

public:

    Personagem();
    ~Personagem();

    void setFaceRight(bool right);
    bool getFaceRight();
    void setXvel(float vel);
    float getXvel();
    void setYvel(float vel);
    float getYvel();
    bool canJump;
    void onCollision(sf::Vector2f direction);


};

#endif // _PERSONAGEM_H_
