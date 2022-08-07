#include "MenuPrincipal.h"
#include <iostream>

MenuPrincipal::MenuPrincipal(sf::Font font, bool* play):
Menu(font, play)
{

}

MenuPrincipal::MenuPrincipal():
Menu()
{

}

MenuPrincipal::~MenuPrincipal()
{

}

void MenuPrincipal::atualizar(sf::RenderWindow* window, sf::View* view, float deltaTimeOprin)
{
            sf::Event event;
            window->pollEvent(event);
            if(event.type == sf::Event::EventType::KeyPressed)
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

void MenuPrincipal::build(sf::View* view)
{
        texture.loadFromFile("Background/castelo.jpg");
        menu_back.setTexture(&texture);
        //menu_back.setFillColor(Color::Black);
        menu_back.setPosition(view->getCenter().x - view->getSize().x / 2, view->getCenter().y - view->getSize().y / 2);
        menu_back.setSize(Vector2f(800.0f, 600.0f));

        opcoes[0].setPosition(view->getCenter().x - view->getSize().x / 4.5f, view->getCenter().y - view->getSize().y / 3.0f);
        opcoes[0].setString("* 1 Jogador");
        opcoes[0].setCharacterSize(30);
        opcoes[0].setFillColor(Color::White);
        opcoes[0].setFont(fonte);

        opcoes[1].setPosition(view->getCenter().x - view->getSize().x / 4.5f, view->getCenter().y - view->getSize().y / 6.5f);
        opcoes[1].setString("* 2 Jogadores");
        opcoes[1].setCharacterSize(30);
        opcoes[1].setFillColor(Color::White);
        opcoes[1].setFont(fonte);

        opcoes[2].setPosition(view->getCenter().x - view->getSize().x / 4.5f, view->getCenter().y + view->getSize().y / 50);
        opcoes[2].setString("* Ranking");
        opcoes[2].setCharacterSize(30);
        opcoes[2].setFillColor(Color::White);
        opcoes[2].setFont(fonte);

        opcoes[3].setPosition(view->getCenter().x - view->getSize().x / 4.5f, view->getCenter().y + view->getSize().y / 4.75);
        opcoes[3].setString("* Configuracoes");
        opcoes[3].setCharacterSize(30);
        opcoes[3].setFillColor(Color::White);
        opcoes[3].setFont(fonte);
}

void MenuPrincipal::buildFase(sf::View* view)
{
        texture.loadFromFile("Background/castelo.jpg");
        menu_back.setTexture(&texture);
        //menu_back.setFillColor(Color::Black);
        menu_back.setPosition(view->getCenter().x - view->getSize().x / 2, view->getCenter().y - view->getSize().y / 2);
        menu_back.setSize(Vector2f(800.0f, 600.0f));

        opcoes[0].setPosition(view->getCenter().x - view->getSize().x / 4.5f, view->getCenter().y - view->getSize().y / 3.0f);
        opcoes[0].setString("* Fase 1");
        opcoes[0].setCharacterSize(30);
        opcoes[0].setFillColor(Color::White);
        opcoes[0].setFont(fonte);

        opcoes[1].setPosition(view->getCenter().x - view->getSize().x / 4.5f, view->getCenter().y - view->getSize().y / 6.5f);
        opcoes[1].setString("* Fase 2");
        opcoes[1].setCharacterSize(30);
        opcoes[1].setFillColor(Color::White);
        opcoes[1].setFont(fonte);

        opcoes[2].setPosition(view->getCenter().x - view->getSize().x / 4.5f, view->getCenter().y + view->getSize().y / 50);
        opcoes[2].setString("* Fase 3");
        opcoes[2].setCharacterSize(30);
        opcoes[2].setFillColor(Color::White);
        opcoes[2].setFont(fonte);

        opcoes[3].setPosition(view->getCenter().x - view->getSize().x / 4.5f, view->getCenter().y + view->getSize().y / 4.75);
        opcoes[3].setString("* Voltar");
        opcoes[3].setCharacterSize(30);
        opcoes[3].setFillColor(Color::White);
        opcoes[3].setFont(fonte);
}

bool MenuPrincipal::controlar(float deltaTimeOprin, sf::View* view, bool* Ss, int* fase, int* Op)
{
            buildFase(view);
            if((*Op) < 0)
            {
                (*Op) = 0;
            }
            if((*Op) > 3)
            {
                (*Op) = 3;
            }

            for(int i = 0; i < 4; i++)
            {
                opcoes[i].setFillColor(sf::Color::White);
            }
            opcoes[(*Op)].setFillColor(Color::Red);

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && deltaTimeOprin >= 0.2f)
            {
                (*fase) = (*Op) + 1;
                (*Ss) = false;
                return true;

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && deltaTimeOprin >= 0.2f)
            {
                (*Op)--;
                return true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && deltaTimeOprin >= 0.2f)
            {
                (*Op)++;
                return true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && deltaTimeOprin >= 0.2f)
            {
                (*Op)--;
                return true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && deltaTimeOprin >= 0.2f)
            {
                (*Op)++;
                return true;
            }
            else
                return false;


}

bool MenuPrincipal::controlar(float deltaTimeOprin, sf::View* view, int* Op)
{
            build(view);
            if((*Op) <  - 1)
            {
                (*Op) = 0;
            }
            if((*Op) > 3)
            {
                (*Op) = 3;
            }

            for(int i = 0; i < 4; i++)
            {
                opcoes[i].setFillColor(sf::Color::White);
            }
            if((*Op) == -1)
                opcoes[(*Op) + 1].setFillColor(Color::Red);
            else
                opcoes[(*Op)].setFillColor(Color::Red);

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && deltaTimeOprin >= 0.2f)
            {
                (*playable) = true;
                (*Op)++;
                return true;

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && deltaTimeOprin >= 0.2f)
            {
                (*Op)--;
                return true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && deltaTimeOprin >= 0.2f)
            {
                if((*Op) == -1)
                    (*Op) += 2;
                else
                    (*Op)++;
                return true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && deltaTimeOprin >= 0.2f)
            {
                (*Op)--;
                return true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && deltaTimeOprin >= 0.2f)
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
