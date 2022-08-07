#ifndef MENUPAUSE_H_INCLUDED
#define MENUPAUSE_H_INCLUDED

#include "Menu.h"

class MenuPause : public Menu
{

public:
    MenuPause(sf::Font font, bool* playable);
    MenuPause();
    ~MenuPause();

    void atualizar(sf::RenderWindow* window, sf::View* view, float deltaTimeOp);
    bool controlar(float deltaTimeOprin, sf::View* view, int* Op);
    void build(sf::View* view);
};

#endif // MENUPAUSE_H_INCLUDED
