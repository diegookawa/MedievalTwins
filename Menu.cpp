#include "Menu.h"

Menu::Menu(sf::Font font, bool* play):
Entidade()
{
    fonte = font;
    menuOp = 0;
    playable = play;
}

Menu::Menu():
Entidade()
{

}

Menu::~Menu()
{

}
void Menu::imprimir(sf::RenderWindow* window)
{
    window->draw(menu_back);
    for(int i = 0; i < 4; i++)
    {
        window->draw(opcoes[i]);
    }
}

void Menu::sair()
{
    (*playable) = false;
}

void Menu::atualizar(float deltaTime)
{

}
