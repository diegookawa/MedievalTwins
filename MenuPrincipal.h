#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

#include "Menu.h"

class MenuPrincipal : public Menu
{
    public:
    MenuPrincipal(sf::Font font, bool* playable);
    MenuPrincipal();
    ~MenuPrincipal();

    void atualizar(sf::RenderWindow* window, sf::View* view, float deltaTimeOprin);
    bool controlar(float deltaTimeOprin, sf::View* view, int* Op);
    bool controlar(float deltaTimeOprin, sf::View* view, bool* Ss, int* fase, int* Op);
    void build(sf::View* view);
    void buildFase(sf::View* view);
};

#endif // MENUPRINCIPAL_H_INCLUDED
