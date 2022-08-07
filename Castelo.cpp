#include "Castelo.h"

#include <SFML/Graphics.hpp>

using namespace sf;

Castelo::Castelo():
Fase(){

    texture.loadFromFile("background/castelo.jpg");
    shape.setTexture(&texture);
    shape.setPosition(Vector2f(-800.0f, -1050.0f));
    shape.setSize(Vector2f(800.0f, 600.0f));

}

Castelo::~Castelo(){}


void Castelo::build()
{

    Barril* b;
    MagoI* m;
    Plataforma* p;
    Cavaleiro* c;
    Espinho* e;
    int obs = 0;

    sf::Texture textura;
    textura.loadFromFile("Texturas/bloco.png");


    p = new Plataforma(&textura, Vector2f(200.0f, 100.0f), Vector2f(0.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p->isOccupied = true;
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(300.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(650.0f, 100.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(1000.0f, -10.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(1500.0f, -100.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(2000.0f, 150.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(2300.0f, 150.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(2700.0f, 50.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(3100.0f, -50.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(3400.0f, -50.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(3800.0f, -50.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(4100.0f, -50.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(4400.0f, -50.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(4800.0f, -150.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(5100.0f, -150.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(5400.0f, -150.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(5800.0f, -50.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 100.0f), Vector2f(6100.0f, -50.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(6450.0f, -200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p->isOccupied = true;
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(6450.0f, 100.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(6800.0f, -50.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(7100.0f, -150.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(7450.0f, -50.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(7800.0f, -150.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(8100.0f, -250.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(8400.0f, -350.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(200.0f, 100.0f), Vector2f(8900.0f, -50.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/bloco.png");
    p->shape.setTexture(&(*p).texture);
    p->isOccupied = true;

    p->texture.loadFromFile("Texturas/blocoPreto.png");
    p->shape.setTexture(&(*p).texture);

    srand(time(NULL));
    int numeroCavaleiros = rand() %2 + 5;

    for(int i = 0; i < numeroCavaleiros; i++){

        int aux;
        do
        {
            aux = rand() % (colisor.listaPlataformas.plataformas.size() - 1);
        }
        while(colisor.listaPlataformas.plataformas[aux]->isOccupied);

        p = (colisor.listaPlataformas.plataformas[aux]);


        c = new Cavaleiro(p);
        colisor.listaInimigos.incluir(c);
        p->isOccupied = true;

   }

   srand(time(NULL));
   int numeroMagos = rand() %2 + 5;

   for(int i = 0; i < numeroMagos; i++){

        int aux;
        do
        {
            aux = rand() % (colisor.listaPlataformas.plataformas.size() - 1);
        }
        while(colisor.listaPlataformas.plataformas[aux]->isOccupied);

        p = (colisor.listaPlataformas.plataformas[aux]);


        m = new MagoI(p, &colisor.listaProjeteis);
        colisor.listaInimigos.incluir(m);
        p->isOccupied = true;

   }

   srand(time(NULL));
   int numeroEspinhos = rand() %2 + 5;



   for(int i = 0; i < numeroEspinhos; i++){

        int aux;
        do
        {
            aux = rand() % (colisor.listaPlataformas.plataformas.size() - 1);
        }
        while(colisor.listaPlataformas.plataformas[aux]->isOccupied);

        p = (colisor.listaPlataformas.plataformas[aux]);

        sf::Vector2f size(50.0f, 50.0f);
        sf::Vector2f posi;

        posi = sf::Vector2f(p->shape.getPosition().x - p->shape.getSize().x/ 2.8f, p->shape.getPosition().y - p->shape.getSize().y / 2.4f);


        e = new Espinho(posi, size);
        colisor.listaObstaculos.incluir(obs, (*e));
        obs++;

        posi = sf::Vector2f(p->shape.getPosition().x + p->shape.getSize().x /2.35f, p->shape.getPosition().y - p->shape.getSize().y / 2.4f);

        e = new Espinho(posi, size);
        colisor.listaObstaculos.incluir(obs, (*e));
        obs++;

        p->isOccupied = true;

   }

   srand(time(NULL));
   int numeroBarris = rand() %2 + 5;

   for(int i = 0; i < numeroBarris; i++){

        int aux;
        do
        {
            aux = rand() % (colisor.listaPlataformas.plataformas.size() - 1);
        }
        while(colisor.listaPlataformas.plataformas[aux]->isOccupied);

        p = (colisor.listaPlataformas.plataformas[aux]);

        sf::Vector2f size(50.0f, 70.0f);
        sf::Vector2f posi;

        posi = sf::Vector2f(p->shape.getPosition().x - p->shape.getSize().x/ 2.8f, p->shape.getPosition().y - p->shape.getSize().y / 1.4f);


        b = new Barril(posi, size);
        colisor.listaObstaculos.incluir(obs, (*b));
        obs++;

        posi = sf::Vector2f(p->shape.getPosition().x + p->shape.getSize().x /2.5f, p->shape.getPosition().y - p->shape.getSize().y / 1.4f);

        b = new Barril(posi, size);
        colisor.listaObstaculos.incluir(obs, (*b));
        obs++;

        p->isOccupied = true;

   }


}
