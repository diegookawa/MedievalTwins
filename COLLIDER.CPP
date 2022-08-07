#include "Collider.h"
#include <iostream>

using namespace sf;

Collider::Collider()
{
    push = 1.0f;
    pDrag = nullptr;

}

Collider::~Collider()
{

}

void Collider::desenhar(sf::RenderWindow* window)
{
    for(int i = 0; i < listaPlataformas.plataformas.size(); i++)
    {
        window->draw(listaPlataformas.plataformas[i]->shape);
    }
    for (listaProjeteis.itr = listaProjeteis.deck.begin(); listaProjeteis.itr != listaProjeteis.deck.end(); ++listaProjeteis.itr)
    {
        window->draw((*listaProjeteis.itr)->shape);
    }
    for (listaProjeteisP.itr = listaProjeteisP.deck.begin(); listaProjeteisP.itr != listaProjeteisP.deck.end(); ++listaProjeteisP.itr)
    {
        window->draw((*listaProjeteisP.itr)->shape);
    }
     for(listaObstaculos.itr = listaObstaculos.lista.begin(); listaObstaculos.itr != listaObstaculos.lista.end(); ++listaObstaculos.itr)
    {
        window->draw((*listaObstaculos.itr).second.shape);
    }
    for (listaInimigos.itr = listaInimigos.lista.begin(); listaInimigos.itr != listaInimigos.lista.end(); ++listaInimigos.itr)
    {
        (*listaInimigos.itr)->animar();
        window->draw((*listaInimigos.itr)->shape);
    }
    if(pDrag != nullptr)
    {
        window->draw(pDrag->shape);
        //pDrag->animar();
    }
}

void Collider::atualizar(float deltaTime)
{
    for (listaInimigos.itr = listaInimigos.lista.begin(); listaInimigos.itr != listaInimigos.lista.end(); ++listaInimigos.itr)
    {
        (*listaInimigos.itr)->atualizar(deltaTime);
    }
    if(pDrag != nullptr)
    {
        if(pDrag->getNumVidas() >= 0)
            pDrag->atualizar(deltaTime);
        else
        {
            pDrag = nullptr;
        }
    }
}

bool Collider::checkCollision(Dragao* dragao, Jogador* other, sf::Vector2f* direction, int* score)
{

    Vector2f otherPosition = other->shape.getPosition();
    Vector2f otherHalfSize = other->shape.getSize() / 2.0f;
    Vector2f thisPosition = dragao->shape.getPosition();
    Vector2f thisHalfSize = dragao->shape.getSize() / 2.0f;

    float deltaX;
    float deltaY;
    float intersectX;
    float intersectY;

    int mov = 0;

    deltaX = otherPosition.x - thisPosition.x - 175;
    deltaY = otherPosition.y - thisPosition.y - 10;
    intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if(deltaX < 0)
    {
        intersectX = (deltaX * -1) - (thisHalfSize.x + otherHalfSize.x);
    }
    else
    {
        intersectX = deltaX - (thisHalfSize.x + otherHalfSize.x);
    }

    if(deltaY < 0)
    {
        intersectY = (deltaY * -1) - (thisHalfSize.y + otherHalfSize.y);
    }else
    {
        intersectY = deltaY - (thisHalfSize.y + otherHalfSize.y);
    }

    if(intersectX < 0.0f && intersectY < 0.0f){

        push = std::min(std::max(push, 0.0f), 1.0f);

        if(intersectX > intersectY){

            if(deltaX > 0.0f ){

                if(other->isAttacking && !other->getFaceRight())
                {
                    if(!dragao->isInvincible)
                    {
                        if(dragao->getNumVidas() - 1 == 0)
                        {
                            (*score) += 5000;
                        }
                        else
                        {
                            dragao->startInv = std::clock();
                            dragao->isInvincible = true;
                        }
                        int aux = dragao->getNumVidas();
                        aux--;
                        dragao->setNumVidas(aux);
                    }
                }
                else
                {
                    if(!other->isInvincible)
                    {
                        int aux = other->getNumVidas();
                        aux--;
                        other->setNumVidas(aux);
                        other->startInv = clock();
                        other->isInvincible = true;
                    }
                }

                dragao->shape.move(intersectX * (1.0f - push), 0.0f);
                other->shape.move(-intersectX * push, 0.0f);

                direction->x = 1.0f;
                direction->y = 0.0f;

            }

            else{

                if(other->isAttacking && other->getFaceRight())
                {
                    if(!dragao->isInvincible)
                    {
                        if(dragao->getNumVidas() - 1 == 0)
                        {
                            (*score) += 5000;
                        }
                        else
                        {
                            dragao->startInv = std::clock();
                            dragao->isInvincible = true;
                        }
                        int aux = dragao->getNumVidas();
                        aux--;
                        dragao->setNumVidas(aux);
                    }
                }
                else
                {
                    if(!other->isInvincible)
                    {
                        int aux = other->getNumVidas();
                        aux--;
                        other->setNumVidas(aux);
                        other->startInv = clock();
                        other->isInvincible = true;
                    }

                }

                dragao->shape.move(-intersectX * (1.0f - push), 0.0f);
                other->shape.move(intersectX * push, 0.0f);

                direction->x = -1.0f;
                direction->y = 0.0f;

            }

        }

        else{

            if(deltaY > 0.0f ){

                dragao->shape.move(0.0f, intersectY * (1.0f - push));
                other->shape.move(0.0f, -intersectY * push);

                direction->x = 0.0f;
                direction->y = 1.0f;

                if(!other->isInvincible)
                {
                    int aux = other->getNumVidas();
                    aux--;
                    other->setNumVidas(aux);
                    other->startInv = clock();
                    other->isInvincible = true;
                }



            }

            else{

                dragao->shape.move(0.0f, -intersectY * (1.0f - push));
                other->shape.move(0.0f, intersectY * push);

                direction->x = 0.0f;
                direction->y = -1.0f;

                if(!dragao->isInvincible)
                    {
                        if(dragao->getNumVidas() - 1 == 0)
                        {
                            (*score) += 5000;
                        }
                        else
                        {
                            dragao->startInv = std::clock();
                            dragao->isInvincible = true;
                        }
                        int aux = dragao->getNumVidas();
                        aux--;
                        dragao->setNumVidas(aux);
                    }

            }

        }

        mov++;
    }



    if(mov > 0)
    {
        return true;
    }
    else
        return false;

}

bool Collider::checkCollision(Jogador* other, sf::Vector2f* direction, int* score)
{

    Vector2f otherPosition = other->shape.getPosition();
    Vector2f otherHalfSize = other->shape.getSize() / 2.0f;
    Vector2f thisPosition;
    Vector2f thisHalfSize;

    float deltaX;
    float deltaY;
    float intersectX;
    float intersectY;

    int mov = 0;

    for(int i = 0; i < listaPlataformas.plataformas.size(); i++)
    {
        thisPosition = listaPlataformas.plataformas[i]->shape.getPosition();
        thisHalfSize = listaPlataformas.plataformas[i]->shape.getSize()/2.0f;

        deltaX = otherPosition.x - thisPosition.x + 30;
        deltaY = otherPosition.y - thisPosition.y;
        intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
        intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

        if(deltaX < 0)
        {
            intersectX = (deltaX * -1) - (thisHalfSize.x + otherHalfSize.x);
        }
        else
        {
            intersectX = deltaX - (thisHalfSize.x + otherHalfSize.x);
        }

        if(deltaY < 0)
        {
            intersectY = (deltaY * -1) - (thisHalfSize.y + otherHalfSize.y);
        }else
        {
            intersectY = deltaY - (thisHalfSize.y + otherHalfSize.y);
        }

        if(intersectX < 0.0f && intersectY < 0.0f){

            push = std::min(std::max(push, 0.0f), 1.0f);

            if(intersectX > intersectY){

                if(deltaX > 0.0f ){

                    listaPlataformas.plataformas[i]->shape.move(intersectX * (1.0f - push), 0.0f);
                    other->shape.move(-intersectX * push, 0.0f);

                    direction->x = 1.0f;
                    direction->y = 0.0f;

                }

                else{

                    listaPlataformas.plataformas[i]->shape.move(-intersectX * (1.0f - push), 0.0f);
                    other->shape.move(intersectX * push, 0.0f);

                    direction->x = -1.0f;
                    direction->y = 0.0f;

                }

            }

            else{

                if(deltaY > 0.0f ){

                    listaPlataformas.plataformas[i]->shape.move(0.0f, intersectY * (1.0f - push));
                    other->shape.move(0.0f, -intersectY * push);

                    direction->x = 0.0f;
                    direction->y = 1.0f;

                }

                else{

                    listaPlataformas.plataformas[i]->shape.move(0.0f, -intersectY * (1.0f - push));
                    other->shape.move(0.0f, intersectY * push);

                    direction->x = 0.0f;
                    direction->y = -1.0f;

                }

            }

            mov++;

        }

    }
    for (listaProjeteis.itr = listaProjeteis.deck.begin(); listaProjeteis.itr != listaProjeteis.deck.end(); ++listaProjeteis.itr)
    {
        thisPosition = (*listaProjeteis.itr)->shape.getPosition();
        thisHalfSize = (*listaProjeteis.itr)->shape.getSize()/2.0f;

        deltaX = otherPosition.x - thisPosition.x;
        deltaY = otherPosition.y - thisPosition.y;
        intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
        intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

        if(deltaX < 0)
        {
            intersectX = (deltaX * -1) - (thisHalfSize.x + otherHalfSize.x);
        }
        else
        {
            intersectX = deltaX - (thisHalfSize.x + otherHalfSize.x);
        }

        if(deltaY < 0)
        {
            intersectY = (deltaY * -1) - (thisHalfSize.y + otherHalfSize.y);
        }else
        {
            intersectY = deltaY - (thisHalfSize.y + otherHalfSize.y);
        }

        if(intersectX < 0.0f && intersectY < 0.0f){

            push = std::min(std::max(push, 0.0f), 1.0f);

            if(intersectX > intersectY){

                if(deltaX > 0.0f ){

                    (*listaProjeteis.itr)->shape.move(intersectX * (1.0f - push), 0.0f);
                    other->shape.move(-intersectX * push, 0.0f);

                    listaProjeteis.deletar(listaProjeteis.itr);
                    if(!other->isInvincible)
                    {
                        int aux = other->getNumVidas();
                        aux--;
                        other->setNumVidas(aux);
                        other->startInv = clock();
                        other->isInvincible = true;
                    }


                }

                else{

                    (*listaProjeteis.itr)->shape.move(-intersectX * (1.0f - push), 0.0f);
                    other->shape.move(intersectX * push, 0.0f);

                    listaProjeteis.deletar(listaProjeteis.itr);

                    if(!other->isInvincible)
                    {
                        int aux = other->getNumVidas();
                        aux--;
                        other->setNumVidas(aux);
                        other->startInv = clock();
                        other->isInvincible = true;
                    }

                }

            }

            else{

                if(deltaY > 0.0f ){

                    (*listaProjeteis.itr)->shape.move(0.0f, intersectY * (1.0f - push));
                    other->shape.move(0.0f, -intersectY * push);

                    listaProjeteis.deletar(listaProjeteis.itr);

                    if(!other->isInvincible)
                    {
                        int aux = other->getNumVidas();
                        aux--;
                        other->setNumVidas(aux);
                        other->startInv = clock();
                        other->isInvincible = true;
                    }


                }

                else{

                    (*listaProjeteis.itr)->shape.move(0.0f, -intersectY * (1.0f - push));
                    other->shape.move(0.0f, intersectY * push);

                    listaProjeteis.deletar(listaProjeteis.itr);

                    if(!other->isInvincible)
                    {
                        int aux = other->getNumVidas();
                        aux--;
                        other->setNumVidas(aux);
                        other->startInv = clock();
                        other->isInvincible = true;
                    }


                }

            }

            mov++;

        }

    }
     for(listaObstaculos.itr = listaObstaculos.lista.begin(); listaObstaculos.itr != listaObstaculos.lista.end(); ++listaObstaculos.itr)
    {
        thisPosition = listaObstaculos.itr->second.shape.getPosition();
        thisHalfSize = listaObstaculos.itr->second.shape.getSize()/2.0f;

        deltaX = otherPosition.x - thisPosition.x + 30;
        deltaY = otherPosition.y - thisPosition.y + 5;
        intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
        intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

        if(deltaX < 0)
        {
            intersectX = (deltaX * -1) - (thisHalfSize.x + otherHalfSize.x);
        }
        else
        {
            intersectX = deltaX - (thisHalfSize.x + otherHalfSize.x);
        }

        if(deltaY < 0)
        {
            intersectY = (deltaY * -1) - (thisHalfSize.y + otherHalfSize.y);
        }else
        {
            intersectY = deltaY - (thisHalfSize.y + otherHalfSize.y);
        }

        if(intersectX < 0.0f && intersectY < 0.0f){

            push = std::min(std::max(push, 0.0f), 1.0f);

            if(intersectX > intersectY){

                if(deltaX > 0.0f ){

                    listaObstaculos.itr->second.shape.move(intersectX * (1.0f - push), 0.0f);
                    other->shape.move(-intersectX * push, 0.0f);

                    if(listaObstaculos.itr->second.getDano() > 0)
                    {
                        if(!other->isInvincible)
                        {
                            int aux = other->getNumVidas();
                            aux--;
                            other->setNumVidas(aux);
                            other->startInv = clock();
                            other->isInvincible = true;
                        }
                    }

                    direction->x = 1.0f;
                    direction->y = 0.0f;

                }

                else{

                    listaObstaculos.itr->second.shape.move(-intersectX * (1.0f - push), 0.0f);
                    other->shape.move(intersectX * push, 0.0f);

                    direction->x = -1.0f;
                    direction->y = 0.0f;

                    if(listaObstaculos.itr->second.getDano() > 0)
                    {
                        if(!other->isInvincible)
                        {
                            int aux = other->getNumVidas();
                            aux--;
                            other->setNumVidas(aux);
                            other->startInv = clock();
                            other->isInvincible = true;
                        }
                    }

                }

            }

            else{

                if(deltaY > 0.0f ){

                    listaObstaculos.itr->second.shape.move(0.0f, intersectY * (1.0f - push));
                    other->shape.move(0.0f, -intersectY * push);

                    direction->x = 0.0f;
                    direction->y = 1.0f;

                    if(listaObstaculos.itr->second.getDano() > 0)
                    {
                        if(!other->isInvincible)
                        {
                            int aux = other->getNumVidas();
                            aux--;
                            other->setNumVidas(aux);
                            other->startInv = clock();
                            other->isInvincible = true;
                        }
                    }

                }

                else{

                    listaObstaculos.itr->second.shape.move(0.0f, -intersectY * (1.0f - push));
                    other->shape.move(0.0f, intersectY * push);

                    direction->x = 0.0f;
                    direction->y = -1.0f;

                    if(listaObstaculos.itr->second.getDano() > 0)
                    {
                        if(!other->isInvincible)
                        {
                            int aux = other->getNumVidas();
                            aux--;
                            other->setNumVidas(aux);
                            other->startInv = clock();
                            other->isInvincible = true;
                        }
                    }

                }

            }

            mov++;

        }

    }
    for (listaInimigos.itr = listaInimigos.lista.begin(); listaInimigos.itr != listaInimigos.lista.end(); ++listaInimigos.itr)
    {
        thisPosition = (*listaInimigos.itr)->shape.getPosition();
        thisHalfSize = (*listaInimigos.itr)->shape.getSize()/2.0f;

        deltaX = otherPosition.x - thisPosition.x;
        deltaY = otherPosition.y - thisPosition.y;
        intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
        intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

        if(deltaX < 0)
        {
            intersectX = (deltaX * -1) - (thisHalfSize.x + otherHalfSize.x);
        }
        else
        {
            intersectX = deltaX - (thisHalfSize.x + otherHalfSize.x);
        }

        if(deltaY < 0)
        {
            intersectY = (deltaY * -1) - (thisHalfSize.y + otherHalfSize.y);
        }else
        {
            intersectY = deltaY - (thisHalfSize.y + otherHalfSize.y);
        }

        if(intersectX < 0.0f && intersectY < 0.0f){

            push = std::min(std::max(push, 0.0f), 1.0f);

            if(intersectX > intersectY){

                if(deltaX > 0.0f ){

                    if(other->isAttacking && !other->getFaceRight())
                    {
                        listaInimigos.deletar(listaInimigos.itr);
                        (*score) += 500;
                    }
                    else
                    {
                        if(!other->isInvincible)
                        {
                            int aux = other->getNumVidas();
                            aux--;
                            other->setNumVidas(aux);
                            other->startInv = clock();
                            other->isInvincible = true;
                        }
                    }

                    (*listaInimigos.itr)->shape.move(intersectX * (1.0f - push), 0.0f);
                    other->shape.move(-intersectX * push, 0.0f);

                    direction->x = 1.0f;
                    direction->y = 0.0f;

                }

                else{

                   if(other->isAttacking && other->getFaceRight())
                    {
                        listaInimigos.deletar(listaInimigos.itr);
                        (*score) += 500;
                    }
                    else
                    {
                        if(!other->isInvincible)
                        {
                            int aux = other->getNumVidas();
                            aux--;
                            other->setNumVidas(aux);
                            other->startInv = clock();
                            other->isInvincible = true;
                        }

                    }

                    (*listaInimigos.itr)->shape.move(-intersectX * (1.0f - push), 0.0f);
                    other->shape.move(intersectX * push, 0.0f);

                    direction->x = -1.0f;
                    direction->y = 0.0f;

                }

            }

            else{

                if(deltaY > 0.0f ){

                    (*listaInimigos.itr)->shape.move(0.0f, intersectY * (1.0f - push));
                    other->shape.move(0.0f, -intersectY * push);

                    direction->x = 0.0f;
                    direction->y = 1.0f;

                    if(!other->isInvincible)
                    {
                        int aux = other->getNumVidas();
                        aux--;
                        other->setNumVidas(aux);
                        other->startInv = clock();
                        other->isInvincible = true;
                    }



                }

                else{

                    (*listaInimigos.itr)->shape.move(0.0f, -intersectY * (1.0f - push));
                    other->shape.move(0.0f, intersectY * push);

                    direction->x = 0.0f;
                    direction->y = -1.0f;

                    listaInimigos.deletar(listaInimigos.itr);
                    (*score) += 500;

                }

            }

            mov++;

        }

    }

    if(mov > 0)
    {
        return true;
    }
    else
        return false;

}

bool Collider::checkCollision(Dragao* dragao, int* score)
{
    Vector2f otherPosition = dragao->shape.getPosition();
    Vector2f otherHalfSize = dragao->shape.getSize() / 2.0f;
    Vector2f thisPosition;
    Vector2f thisHalfSize;


    float deltaX;
    float deltaY;
    float intersectX;
    float intersectY;

    int mov = 0;
    for(int i = 0; i < listaPlataformas.plataformas.size(); i++)
    {
        thisPosition = listaPlataformas.plataformas[i]->shape.getPosition();
        thisHalfSize = listaPlataformas.plataformas[i]->shape.getSize()/2.0f;

        deltaX = otherPosition.x - thisPosition.x - 175;
        deltaY = otherPosition.y - thisPosition.y - 10;
        intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
        intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

        if(deltaX < 0)
        {
            intersectX = (deltaX * -1) - (thisHalfSize.x + otherHalfSize.x);
        }
        else
        {
            intersectX = deltaX - (thisHalfSize.x + otherHalfSize.x);
        }

        if(deltaY < 0)
        {
            intersectY = (deltaY * -1) - (thisHalfSize.y + otherHalfSize.y);
        }else
        {
            intersectY = deltaY - (thisHalfSize.y + otherHalfSize.y);
        }

        if(intersectX < 0.0f && intersectY < 0.0f){

            push = std::min(std::max(push, 0.0f), 1.0f);

            if(intersectX > intersectY){

            }

            else{

                if(deltaY > 0.0f ){

                    listaPlataformas.plataformas[i]->shape.move(0.0f, intersectY * (1.0f - push));
                    dragao->shape.move(0.0f, -intersectY * push);

                    dragao->onCollision(Vector2f(0.0f, 1.0f));

                }

                else{

                    listaPlataformas.plataformas[i]->shape.move(0.0f, -intersectY * (1.0f - push));
                    dragao->shape.move(0.0f, intersectY * push);

                    dragao->onCollision(Vector2f(0.0f, -1.0f));

                }

            }

            mov++;

        }

    }
    for(listaObstaculos.itr = listaObstaculos.lista.begin(); listaObstaculos.itr != listaObstaculos.lista.end(); ++listaObstaculos.itr)
    {
        thisPosition = listaObstaculos.itr->second.shape.getPosition();
        thisHalfSize = listaObstaculos.itr->second.shape.getSize()/2.0f;

        deltaX = otherPosition.x - thisPosition.x/* + 30*/;
        deltaY = otherPosition.y - thisPosition.y;
        intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
        intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

        if(deltaX < 0)
        {
            intersectX = (deltaX * -1) - (thisHalfSize.x + otherHalfSize.x);
        }
        else
        {
            intersectX = deltaX - (thisHalfSize.x + otherHalfSize.x);
        }

        if(deltaY < 0)
        {
            intersectY = (deltaY * -1) - (thisHalfSize.y + otherHalfSize.y);
        }else
        {
            intersectY = deltaY - (thisHalfSize.y + otherHalfSize.y);
        }

        if(intersectX < 0.0f && intersectY < 0.0f){

            push = std::min(std::max(push, 0.0f), 1.0f);

            if(intersectX > intersectY){

                if(deltaX > 0.0f ){

                    listaObstaculos.itr->second.shape.move(intersectX * (1.0f - push), 0.0f);
                    dragao->shape.move(-intersectX * push, 0.0f);

                    dragao->onCollision(Vector2f(1.0f, 0.0f));

                }

                else{

                    listaObstaculos.itr->second.shape.move(-intersectX * (1.0f - push), 0.0f);
                    dragao->shape.move(intersectX * push, 0.0f);

                    dragao->onCollision(Vector2f(-1.0f, 0.0f));

                }

            }

            else{

                if(deltaY > 0.0f ){

                    listaObstaculos.itr->second.shape.move(0.0f, intersectY * (1.0f - push));
                    dragao->shape.move(0.0f, -intersectY * push);

                    dragao->onCollision(Vector2f(0.0f, 1.0f));

                }

                else{

                    listaObstaculos.itr->second.shape.move(0.0f, -intersectY * (1.0f - push));
                    dragao->shape.move(0.0f, intersectY * push);

                    dragao->onCollision(Vector2f(0.0f, -1.0f));


                }

            }

            mov++;

        }
    }
    for(listaProjeteisP.itr = listaProjeteisP.deck.begin(); listaProjeteisP.itr != listaProjeteisP.deck.end(); ++listaProjeteisP.itr)
    {
        thisPosition = (*listaProjeteisP.itr)->shape.getPosition();
        thisHalfSize = (*listaProjeteisP.itr)->shape.getSize()/2.0f;

        deltaX = otherPosition.x - thisPosition.x - 175;
        deltaY = otherPosition.y - thisPosition.y + 50;
        intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
        intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

        if(deltaX < 0)
        {
            intersectX = (deltaX * -1) - (thisHalfSize.x + otherHalfSize.x);
        }
        else
        {
            intersectX = deltaX - (thisHalfSize.x + otherHalfSize.x);
        }

        if(deltaY < 0)
        {
            intersectY = (deltaY * -1) - (thisHalfSize.y + otherHalfSize.y);
        }else
        {
            intersectY = deltaY - (thisHalfSize.y + otherHalfSize.y);
        }

        if(intersectX < 0.0f && intersectY < 0.0f){

            push = std::min(std::max(push, 0.0f), 1.0f);

            if(intersectX > intersectY){

                if(deltaX > 0.0f ){

                    if(!dragao->isInvincible)
                    {
                        if(dragao->getNumVidas() - 1 == 0)
                        {
                            (*score) += 5000;
                        }
                        else
                        {
                            dragao->startInv = std::clock();
                            dragao->isInvincible = true;
                        }
                        int aux = dragao->getNumVidas();
                        aux--;
                        dragao->setNumVidas(aux);
                    }
                    listaProjeteisP.deletar(listaProjeteisP.itr);

                }

                else{

                    if(!dragao->isInvincible)
                    {
                        if(dragao->getNumVidas() - 1 == 0)
                        {
                            (*score) += 5000;
                        }
                        else
                        {
                            dragao->startInv = std::clock();
                            dragao->isInvincible = true;
                        }
                        int aux = dragao->getNumVidas();
                        aux--;
                        dragao->setNumVidas(aux);
                    }
                    listaProjeteisP.deletar(listaProjeteisP.itr);

                }

            }

            else{

                if(deltaY > 0.0f ){

                     if(!dragao->isInvincible)
                    {
                        if(dragao->getNumVidas() - 1 == 0)
                        {
                            (*score) += 5000;
                        }
                        else
                        {
                            dragao->startInv = std::clock();
                            dragao->isInvincible = true;
                        }
                        int aux = dragao->getNumVidas();
                        aux--;
                        dragao->setNumVidas(aux);
                    }
                    listaProjeteisP.deletar(listaProjeteisP.itr);

                }

                else{

                     if(!dragao->isInvincible)
                    {
                        if(dragao->getNumVidas() - 1 == 0)
                        {
                            (*score) += 5000;
                        }
                        else
                        {
                            dragao->startInv = std::clock();
                            dragao->isInvincible = true;
                        }
                        int aux = dragao->getNumVidas();
                        aux--;
                        dragao->setNumVidas(aux);
                    }
                    listaProjeteisP.deletar(listaProjeteisP.itr);

                }

            }

            mov++;

        }
    }

    if(mov > 0)
    {
        return true;
    }
    else
        return false;

}

bool Collider::checkCollisionPer(int* score)
{
    Vector2f otherPosition;
    Vector2f otherHalfSize;
    Vector2f thisPosition;
    Vector2f thisHalfSize;


    float deltaX;
    float deltaY;
    float intersectX;
    float intersectY;

    int mov = 0;

    for(listaInimigos.itr = listaInimigos.lista.begin(); listaInimigos.itr != listaInimigos.lista.end(); ++listaInimigos.itr)
    {
        otherPosition = (*listaInimigos.itr)->shape.getPosition();
        otherHalfSize = (*listaInimigos.itr)->shape.getSize() / 2.0f;
        for(int i = 0; i < listaPlataformas.plataformas.size(); i++)
        {
            thisPosition = listaPlataformas.plataformas[i]->shape.getPosition();
            thisHalfSize = listaPlataformas.plataformas[i]->shape.getSize()/2.0f;

            deltaX = otherPosition.x - thisPosition.x/* + 30*/;
            deltaY = otherPosition.y - thisPosition.y;
            intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
            intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

            if(deltaX < 0)
            {
                intersectX = (deltaX * -1) - (thisHalfSize.x + otherHalfSize.x);
            }
            else
            {
                intersectX = deltaX - (thisHalfSize.x + otherHalfSize.x);
            }

            if(deltaY < 0)
            {
                intersectY = (deltaY * -1) - (thisHalfSize.y + otherHalfSize.y);
            }else
            {
                intersectY = deltaY - (thisHalfSize.y + otherHalfSize.y);
            }

            if(intersectX < 0.0f && intersectY < 0.0f){

                push = std::min(std::max(push, 0.0f), 1.0f);

                if(intersectX > intersectY){

                    /*if(deltaX > 0.0f ){

                        listaPlataformas.plataformas[i]->shape.move(intersectX * (1.0f - push), 0.0f);
                        (*listaInimigos.itr)->shape.move(-intersectX * push, 0.0f);

                        (*listaInimigos.itr)->onCollision(Vector2f(1.0f, 0.0f));

                    }

                    else{

                        listaPlataformas.plataformas[i]->shape.move(-intersectX * (1.0f - push), 0.0f);
                        (*listaInimigos.itr)->shape.move(intersectX * push, 0.0f);

                        (*listaInimigos.itr)->onCollision(Vector2f(-1.0f, 0.0f));

                    }*/

                }

                else{

                    if(deltaY > 0.0f ){

                        listaPlataformas.plataformas[i]->shape.move(0.0f, intersectY * (1.0f - push));
                        (*listaInimigos.itr)->shape.move(0.0f, -intersectY * push);

                        (*listaInimigos.itr)->onCollision(Vector2f(0.0f, 1.0f));

                    }

                    else{

                        listaPlataformas.plataformas[i]->shape.move(0.0f, -intersectY * (1.0f - push));
                        (*listaInimigos.itr)->shape.move(0.0f, intersectY * push);

                        (*listaInimigos.itr)->onCollision(Vector2f(0.0f, -1.0f));

                    }

                }

                mov++;

            }

        }
         for(listaObstaculos.itr = listaObstaculos.lista.begin(); listaObstaculos.itr != listaObstaculos.lista.end(); ++listaObstaculos.itr)
        {
            thisPosition = listaObstaculos.itr->second.shape.getPosition();
            thisHalfSize = listaObstaculos.itr->second.shape.getSize()/2.0f;

            deltaX = otherPosition.x - thisPosition.x/* + 30*/;
            deltaY = otherPosition.y - thisPosition.y;
            intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
            intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

            if(deltaX < 0)
            {
                intersectX = (deltaX * -1) - (thisHalfSize.x + otherHalfSize.x);
            }
            else
            {
                intersectX = deltaX - (thisHalfSize.x + otherHalfSize.x);
            }

            if(deltaY < 0)
            {
                intersectY = (deltaY * -1) - (thisHalfSize.y + otherHalfSize.y);
            }else
            {
                intersectY = deltaY - (thisHalfSize.y + otherHalfSize.y);
            }

            if(intersectX < 0.0f && intersectY < 0.0f){

                push = std::min(std::max(push, 0.0f), 1.0f);

                if(intersectX > intersectY){

                    if(deltaX > 0.0f ){

                        listaObstaculos.itr->second.shape.move(intersectX * (1.0f - push), 0.0f);
                        (*listaInimigos.itr)->shape.move(-intersectX * push, 0.0f);

                        (*listaInimigos.itr)->onCollision(Vector2f(1.0f, 0.0f));

                    }

                    else{

                        listaObstaculos.itr->second.shape.move(-intersectX * (1.0f - push), 0.0f);
                        (*listaInimigos.itr)->shape.move(intersectX * push, 0.0f);

                        (*listaInimigos.itr)->onCollision(Vector2f(-1.0f, 0.0f));

                    }

                }

                else{

                    if(deltaY > 0.0f ){

                        listaObstaculos.itr->second.shape.move(0.0f, intersectY * (1.0f - push));
                        (*listaInimigos.itr)->shape.move(0.0f, -intersectY * push);

                        (*listaInimigos.itr)->onCollision(Vector2f(0.0f, 1.0f));

                    }

                    else{

                        listaObstaculos.itr->second.shape.move(0.0f, -intersectY * (1.0f - push));
                        (*listaInimigos.itr)->shape.move(0.0f, intersectY * push);

                        (*listaInimigos.itr)->onCollision(Vector2f(0.0f, -1.0f));


                    }

                }

                mov++;

            }
        }
        for(listaProjeteisP.itr = listaProjeteisP.deck.begin(); listaProjeteisP.itr != listaProjeteisP.deck.end(); ++listaProjeteisP.itr)
        {
            thisPosition = (*listaProjeteisP.itr)->shape.getPosition();
            thisHalfSize = (*listaProjeteisP.itr)->shape.getSize()/2.0f;

            deltaX = otherPosition.x - thisPosition.x/* + 30*/;
            deltaY = otherPosition.y - thisPosition.y;
            intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
            intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

            if(deltaX < 0)
            {
                intersectX = (deltaX * -1) - (thisHalfSize.x + otherHalfSize.x);
            }
            else
            {
                intersectX = deltaX - (thisHalfSize.x + otherHalfSize.x);
            }

            if(deltaY < 0)
            {
                intersectY = (deltaY * -1) - (thisHalfSize.y + otherHalfSize.y);
            }else
            {
                intersectY = deltaY - (thisHalfSize.y + otherHalfSize.y);
            }

            if(intersectX < 0.0f && intersectY < 0.0f){

                push = std::min(std::max(push, 0.0f), 1.0f);

                if(intersectX > intersectY){

                    if(deltaX > 0.0f ){

                        (*score) += 500;
                        listaInimigos.deletar(listaInimigos.itr);
                        listaProjeteisP.deletar(listaProjeteisP.itr);

                    }

                    else{

                        (*score) += 500;
                        listaInimigos.deletar(listaInimigos.itr);
                        listaProjeteisP.deletar(listaProjeteisP.itr);

                    }

                }

                else{

                    if(deltaY > 0.0f ){

                        (*score) += 500;
                        listaInimigos.deletar(listaInimigos.itr);
                        listaProjeteisP.deletar(listaProjeteisP.itr);

                    }

                    else{

                        (*score) += 500;
                        listaInimigos.deletar(listaInimigos.itr);
                        listaProjeteisP.deletar(listaProjeteisP.itr);

                    }

                }

                mov++;

            }
        }
    }
    if(mov > 0)
    {
        return true;
    }
    else
        return false;

}


bool Collider::checkCollisionProj()
{
    Vector2f otherPosition;
    Vector2f otherHalfSize;
    Vector2f thisPosition;
    Vector2f thisHalfSize;


    float deltaX;
    float deltaY;
    float intersectX;
    float intersectY;

    int mov = 0;

    for(listaProjeteis.itr = listaProjeteis.deck.begin(); listaProjeteis.itr != listaProjeteis.deck.end(); ++listaProjeteis.itr)
    {
        otherPosition = (*listaProjeteis.itr)->shape.getPosition();
        otherHalfSize = (*listaProjeteis.itr)->shape.getSize() / 2.0f;
        for(int i = 0; i < listaPlataformas.plataformas.size(); i++)
        {
            thisPosition = listaPlataformas.plataformas[i]->shape.getPosition();
            thisHalfSize = listaPlataformas.plataformas[i]->shape.getSize()/2.0f;

            deltaX = otherPosition.x - thisPosition.x/* + 30*/;
            deltaY = otherPosition.y - thisPosition.y;
            intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
            intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

            if(deltaX < 0)
            {
                intersectX = (deltaX * -1) - (thisHalfSize.x + otherHalfSize.x);
            }
            else
            {
                intersectX = deltaX - (thisHalfSize.x + otherHalfSize.x);
            }

            if(deltaY < 0)
            {
                intersectY = (deltaY * -1) - (thisHalfSize.y + otherHalfSize.y);
            }else
            {
                intersectY = deltaY - (thisHalfSize.y + otherHalfSize.y);
            }

            if(intersectX < 0.0f && intersectY < 0.0f){

                push = std::min(std::max(push, 0.0f), 1.0f);

                if(intersectX > intersectY){

                    if(deltaX > 0.0f ){

                        listaProjeteis.deletar(listaProjeteis.itr);

                    }

                    else{

                        listaProjeteis.deletar(listaProjeteis.itr);

                    }

                }

                else{

                    if(deltaY > 0.0f ){

                        listaProjeteis.deletar(listaProjeteis.itr);

                    }

                    else{

                        listaProjeteis.deletar(listaProjeteis.itr);

                    }

                }

                mov++;

            }

        }
         for(listaObstaculos.itr = listaObstaculos.lista.begin(); listaObstaculos.itr != listaObstaculos.lista.end(); ++listaObstaculos.itr)
        {
            thisPosition = listaObstaculos.itr->second.shape.getPosition();
            thisHalfSize = listaObstaculos.itr->second.shape.getSize()/2.0f;

            deltaX = otherPosition.x - thisPosition.x/* + 30*/;
            deltaY = otherPosition.y - thisPosition.y;
            intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
            intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

            if(deltaX < 0)
            {
                intersectX = (deltaX * -1) - (thisHalfSize.x + otherHalfSize.x);
            }
            else
            {
                intersectX = deltaX - (thisHalfSize.x + otherHalfSize.x);
            }

            if(deltaY < 0)
            {
                intersectY = (deltaY * -1) - (thisHalfSize.y + otherHalfSize.y);
            }else
            {
                intersectY = deltaY - (thisHalfSize.y + otherHalfSize.y);
            }

            if(intersectX < 0.0f && intersectY < 0.0f){

                push = std::min(std::max(push, 0.0f), 1.0f);

                if(intersectX > intersectY){

                    if(deltaX > 0.0f ){

                        listaObstaculos.itr->second.shape.move(intersectX * (1.0f - push), 0.0f);
                        (*listaProjeteis.itr)->shape.move(-intersectX * push, 0.0f);

                        listaProjeteis.deletar(listaProjeteis.itr);

                    }

                    else{

                        listaObstaculos.itr->second.shape.move(-intersectX * (1.0f - push), 0.0f);
                        (*listaProjeteis.itr)->shape.move(intersectX * push, 0.0f);

                        listaProjeteis.deletar(listaProjeteis.itr);

                    }

                }

                else{

                    if(deltaY > 0.0f ){

                        listaObstaculos.itr->second.shape.move(0.0f, intersectY * (1.0f - push));
                        (*listaProjeteis.itr)->shape.move(0.0f, -intersectY * push);

                        listaProjeteis.deletar(listaProjeteis.itr);

                    }

                    else{

                        listaObstaculos.itr->second.shape.move(0.0f, -intersectY * (1.0f - push));
                        (*listaProjeteis.itr)->shape.move(0.0f, intersectY * push);

                        listaProjeteis.deletar(listaProjeteis.itr);

                    }

                }

                mov++;

            }
        }
    }
    for(listaProjeteisP.itr = listaProjeteisP.deck.begin(); listaProjeteisP.itr != listaProjeteisP.deck.end(); ++listaProjeteisP.itr)
    {
        otherPosition = (*listaProjeteisP.itr)->shape.getPosition();
        otherHalfSize = (*listaProjeteisP.itr)->shape.getSize() / 2.0f;
        for(int i = 0; i < listaPlataformas.plataformas.size(); i++)
        {
            thisPosition = listaPlataformas.plataformas[i]->shape.getPosition();
            thisHalfSize = listaPlataformas.plataformas[i]->shape.getSize()/2.0f;

            deltaX = otherPosition.x - thisPosition.x/* + 30*/;
            deltaY = otherPosition.y - thisPosition.y;
            intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
            intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

            if(deltaX < 0)
            {
                intersectX = (deltaX * -1) - (thisHalfSize.x + otherHalfSize.x);
            }
            else
            {
                intersectX = deltaX - (thisHalfSize.x + otherHalfSize.x);
            }

            if(deltaY < 0)
            {
                intersectY = (deltaY * -1) - (thisHalfSize.y + otherHalfSize.y);
            }else
            {
                intersectY = deltaY - (thisHalfSize.y + otherHalfSize.y);
            }

            if(intersectX < 0.0f && intersectY < 0.0f){

                push = std::min(std::max(push, 0.0f), 1.0f);

                if(intersectX > intersectY){

                    if(deltaX > 0.0f ){

                        listaProjeteisP.deletar(listaProjeteisP.itr);

                    }

                    else{

                        listaProjeteisP.deletar(listaProjeteisP.itr);

                    }

                }

                else{

                    if(deltaY > 0.0f ){

                        listaProjeteisP.deletar(listaProjeteisP.itr);

                    }

                    else{

                        listaProjeteisP.deletar(listaProjeteisP.itr);

                    }

                }

                mov++;

            }

        }
         for(listaObstaculos.itr = listaObstaculos.lista.begin(); listaObstaculos.itr != listaObstaculos.lista.end(); ++listaObstaculos.itr)
        {
            thisPosition = listaObstaculos.itr->second.shape.getPosition();
            thisHalfSize = listaObstaculos.itr->second.shape.getSize()/2.0f;

            deltaX = otherPosition.x - thisPosition.x/* + 30*/;
            deltaY = otherPosition.y - thisPosition.y;
            intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
            intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

            if(deltaX < 0)
            {
                intersectX = (deltaX * -1) - (thisHalfSize.x + otherHalfSize.x);
            }
            else
            {
                intersectX = deltaX - (thisHalfSize.x + otherHalfSize.x);
            }

            if(deltaY < 0)
            {
                intersectY = (deltaY * -1) - (thisHalfSize.y + otherHalfSize.y);
            }else
            {
                intersectY = deltaY - (thisHalfSize.y + otherHalfSize.y);
            }

            if(intersectX < 0.0f && intersectY < 0.0f){

                push = std::min(std::max(push, 0.0f), 1.0f);

                if(intersectX > intersectY){

                    if(deltaX > 0.0f ){

                        listaObstaculos.itr->second.shape.move(intersectX * (1.0f - push), 0.0f);
                        (*listaProjeteisP.itr)->shape.move(-intersectX * push, 0.0f);

                        listaProjeteisP.deletar(listaProjeteisP.itr);

                    }

                    else{

                        listaObstaculos.itr->second.shape.move(-intersectX * (1.0f - push), 0.0f);
                        (*listaProjeteisP.itr)->shape.move(intersectX * push, 0.0f);

                        listaProjeteisP.deletar(listaProjeteisP.itr);

                    }

                }

                else{

                    if(deltaY > 0.0f ){

                        listaObstaculos.itr->second.shape.move(0.0f, intersectY * (1.0f - push));
                        (*listaProjeteisP.itr)->shape.move(0.0f, -intersectY * push);

                        listaProjeteisP.deletar(listaProjeteisP.itr);

                    }

                    else{

                        listaObstaculos.itr->second.shape.move(0.0f, -intersectY * (1.0f - push));
                        (*listaProjeteisP.itr)->shape.move(0.0f, intersectY * push);

                        listaProjeteisP.deletar(listaProjeteisP.itr);

                    }

                }

                mov++;

            }
        }
    }
    if(mov > 0)
    {
        return true;
    }
    else
        return false;
}
