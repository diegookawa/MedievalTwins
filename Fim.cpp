#include "Fim.h"

#include <SFML/Graphics.hpp>

using namespace sf;

Fim::Fim():
Fase(){

    texture.loadFromFile("background/bg.jpg");
    shape.setTexture(&texture);
    shape.setPosition(Vector2f(-800.0f, -1050.0f));
    shape.setSize(Vector2f(800.0f, 600.0f));

}

Fim::~Fim(){}

void Fim::build()
{
    Plataforma* p;
    Dragao* d;

    sf::Texture textura;
    textura.loadFromFile("Texturas/bloco.png");


    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(0.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(300.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(600.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(900.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(1200.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(1500.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(1800.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(2100.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(2400.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(2700.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(3000.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(3300.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(3600.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(3900.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(4200.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(4500.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(4800.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(5100.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);

    d = new Dragao(p, &colisor.listaProjeteis);
    colisor.pDrag = d;

}
