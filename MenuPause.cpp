#include "MenuPause.h"
#include <time.h>
#include <iostream>

MenuPause::MenuPause(sf::Font font, bool* play):
Menu(font, play)
{

}

MenuPause::MenuPause():
Menu()
{

}

MenuPause::~MenuPause()
{

}

void MenuPause::atualizar(sf::RenderWindow* window, sf::View* view, float deltaTimeOpause)
{
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            if(*playable)
            {
                (*playable) = false;
            }
            else
            {
                (*playable) = true;
            }
        }
}

void MenuPause::build(sf::View* view)
{
        menu_back.setTexture(nullptr);
        menu_back.setFillColor(Color::Black);
        menu_back.setPosition(view->getCenter().x - view->getSize().x / 4, view->getCenter().y - view->getSize().y / 4);
        menu_back.setSize(Vector2f(400.0f, 300.0f));

        opcoes[0].setPosition(view->getCenter().x - view->getSize().x / 4.5f, view->getCenter().y - view->getSize().y / 7.5f);
        opcoes[0].setString("* Continuar");
        opcoes[0].setCharacterSize(20);
        opcoes[0].setFont(fonte);

        opcoes[1].setPosition(view->getCenter().x - view->getSize().x / 4.5f, view->getCenter().y + view->getSize().y / 22.5f);
        opcoes[1].setString("* Retornar ao Menu");
        opcoes[1].setCharacterSize(20);
        opcoes[1].setFont(fonte);

}

bool MenuPause::controlar(float deltaTimeOpause, sf::View* view, int* Op)
{
            build(view);
            if((*Op) < - 1)
            {
                (*Op) = 0;
            }
            if((*Op) > 1)
            {
                (*Op) = 1;
            }

            for(int i = 0; i < 4; i++)
            {

            }
            if((*Op) == -1)
                opcoes[(*Op) + 1].setFillColor(Color::Red);
            else
                opcoes[(*Op)].setFillColor(Color::Red);

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && deltaTimeOpause >= 0.2f)
            {
                (*playable) = true;
                return true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && deltaTimeOpause >= 0.2f)
            {
                (*Op)--;
                return true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && deltaTimeOpause >= 0.2f)
            {
                if((*Op) == -1)
                    (*Op) += 2;
                else
                    (*Op)++;
                return true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && deltaTimeOpause >= 0.2f)
            {
                (*Op)--;
                return true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && deltaTimeOpause >= 0.2f)
            {
                if((*Op) == -1)
                    (*Op) += 2;
                else
                    (*Op)++;
                return true;
            }
            else
                return false;


}
