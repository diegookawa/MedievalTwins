#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "ENTIDADE.H"

class Menu : public Entidade
{
public:

    Menu(sf::Font font, bool* play);
    Menu();
    ~Menu();

    virtual void atualizar(sf::RenderWindow* window, sf::View* view, float deltaTimeOp) = 0;
    void imprimir(sf::RenderWindow* window);
    void sair();
    void atualizar(float deltaTime);


    sf::RectangleShape menu_back;
    sf::Text opcoes[4];
    sf::Font fonte;

    int menuOp;

    bool* playable;

};

#endif // MENU_H_INCLUDED
