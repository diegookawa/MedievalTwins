#ifndef COLLIDER_H_INCLUDED
#define COLLIDER_H_INCLUDED

#pragma once

#include <SFML/Graphics.hpp>

#include "Jogador.h"
#include "Dragao.h"
#include "ListaObstaculos.h"
#include "ListaInimigos.h"
#include "ListaPlataformas.h"
#include "ListaProjeteis.h"



class Collider
{
  public:
      ~Collider();
      Collider();

      bool checkCollision(Jogador* esse, sf::Vector2f* direction, int* score);

      bool checkCollisionPer(int* score);

      bool checkCollisionProj();

      bool checkCollision();

      bool checkCollision(Dragao* dragao, Jogador* esse, sf::Vector2f* direction, int* score);

      bool checkCollision(Dragao* dragao, int* score);

      void desenhar(sf::RenderWindow* window);

      void atualizar(float deltaTime);

      ListaPlataformas listaPlataformas;
      ListaInimigos listaInimigos;
      ListaObstaculos listaObstaculos;
      ListaProjeteis listaProjeteisP;
      ListaProjeteis listaProjeteis;

      Dragao* pDrag;

  private:
    sf::RectangleShape shape;
    float push;
};

#endif // COLLIDER_H_INCLUDED
