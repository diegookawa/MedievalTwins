#include "Floresta.h"

#include <SFML/Graphics.hpp>

Floresta::Floresta():
Fase(){

    texture.loadFromFile("background/forest2.png");
    shape.setTexture(&texture);
    shape.setPosition(Vector2f(-800.0f, -1050.0f));
    shape.setSize(Vector2f(800.0f, 600.0f));

}

Floresta::~Floresta(){}


void Floresta::build()
{

    Caixa* cx;
    MagoI* m;
    Plataforma* p;
    Cavaleiro* c;
    Barril* b;
    int obs = 0;

    sf::Texture textura;
    textura.loadFromFile("Texturas/jungle.png");


    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(0.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p->isOccupied = true;
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(-300.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(500.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(900.0f, 100.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(1400.0f, 0.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(1300.0f, 250.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(1700.0f, 0.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(2000.0f, 100.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(2400.0f, 200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(2800.0f, 100.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(3200.0f, 0.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(3700.0f, -100.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(3700.0f, 100.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(4000.0f, -100.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(4300.0f, -100.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(4600.0f, -100.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(4900.0f, -200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(5200.0f, -300.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(5500.0f, -400.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p->isOccupied = true;
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(5900.0f, -400.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(6200.0f, -400.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(6450.0f, -250.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(6650.0f, -400.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(6950.0f, -400.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(7250.0f, -300.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(300.0f, 75.0f), Vector2f(7550.0f, -200.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");
    p->shape.setTexture(&(*p).texture);
    p = new Plataforma(&textura, Vector2f(200.0f, 100.0f), Vector2f(7900.0f, -100.0f));
    colisor.listaPlataformas.incluir(p);
    p->texture.loadFromFile("Texturas/jungle.png");p->shape.setTexture(&(*p).texture);
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
   int numeroCaixas = rand() %2 + 5;

   for(int i = 0; i < numeroCaixas; i++){

        int aux;
        do
        {
            aux = rand() % (colisor.listaPlataformas.plataformas.size() - 1);
        }
        while(colisor.listaPlataformas.plataformas[aux]->isOccupied);

        p = (colisor.listaPlataformas.plataformas[aux]);

        sf::Vector2f size(70.0f, 70.0f);
        sf::Vector2f posi;

        posi = sf::Vector2f(p->shape.getPosition().x - p->shape.getSize().x/ 2.8f, p->shape.getPosition().y - p->shape.getSize().y / 1.4f);


        cx = new Caixa(posi, size);
        colisor.listaObstaculos.incluir(obs, (*cx));
        obs++;

        posi = sf::Vector2f(p->shape.getPosition().x + p->shape.getSize().x /2.6f, p->shape.getPosition().y - p->shape.getSize().y / 1.4f);

        cx = new Caixa(posi, size);
        colisor.listaObstaculos.incluir(obs, (*cx));
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
