#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_

#include <SFML/Graphics.hpp>



using namespace sf;

class Entidade {

protected:

    float x;
    float y;

public:

    Entidade();
    ~Entidade();

    void setX(float xx);
    float getX();
    void setY(float yy);
    float getY();

    virtual void atualizar(float deltaTime) = 0;

    void Draw(sf::RenderWindow* window);

    RectangleShape shape;
    Texture texture;

};

#endif // _ENTIDADE_H_
