#include "Jogo.h"

Jogo::Jogo()
{
    fonte.loadFromFile("kongtext.ttf");

    playable = true;
    playing = false;


    menuP.fonte = fonte;
    menuP.playable = &playable;
    menuPrin.fonte = fonte;
    menuPrin.playable = &playing;
}

Jogo::~Jogo()
{

}

void Jogo::executar()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Medieval Twins");
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 600.0f));

    Clock clock;
    Clock clockMago;
    Clock clockA;
    float deltaTime = 0.0f;
    float deltaTimeOp = 0.0f;
    float deltaTimeOprin = 0.0f;

    int indiceCaminho = 0;
    int indiceMago = 0;
    int opMenu = -1;
    int opMenuPrin = -1;


    bool magePlaying = false;
    bool stageSelect = false;
    int fase = 0;
    int score = 0;

    Text vidasGuerreiro, vidasGuerreiroShade, vidasMago, vidasMagoShade, scoreTexto;
    Text opcoes[4];

    RectangleShape blank, menu;
    Vector2f direction;

    Texture texturaG, texturaM;

    std::clock_t startG = std::clock();
    std::clock_t startM = std::clock();
    std::clock_t startT = std::clock();
    std::clock_t startOp = std::clock();
    std::clock_t startOprin = std::clock();

    floresta.build();
    castelo.build();
    fim.build();

    while (window.isOpen()){

        deltaTime = clockA.restart().asSeconds();

        Event event;
        while (window.pollEvent(event)){

            if (event.type == Event::Closed)
                window.close();
        }
        if(!playing)
        {
            menuPrin.atualizar(&window, &view, deltaTimeOprin);
        }
        else
        {

            switch(opMenuPrin)
            {
            case 1:
                magePlaying = false;
                stageSelect = true;
                opMenuPrin = -1;
                opMenu = -1;
                break;
            case 2:
                magePlaying = true;
                stageSelect = true;
                opMenuPrin = -1;
                opMenu = -1;
                break;
            case 3:
                do
                {
                    window.pollEvent(event);
                }while(event.type != sf::Event::EventType::KeyPressed && event.type != sf::Event::EventType::Closed);
                playing = true;
                playable = true;
                opMenuPrin = -1;
                opMenu = -1;
                break;
            case 4:
                std::cout << "Ainda nao Implementado22" << std::endl;
                opMenuPrin = -1;
                opMenu = -1;
                break;
            default:
                break;

            }


            if(playable)
            {

                if(opMenu == 0)
                {
                    playable = true;
                    playing = true;
                }
                else if(opMenu == 1)
                {
                    playable = false;
                    playing = false;
                }



                if(Keyboard::isKeyPressed(Keyboard::P) || Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    deltaTimeOp = (std::clock() - startOp)/ (float)CLOCKS_PER_SEC;
                    if(deltaTimeOp >= 0.2f)
                    {
                        menuP.atualizar(&window, &view, deltaTimeOp);
                        startOp = std::clock();
                    }
                }


                if(!(Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::W)
                 || Keyboard::isKeyPressed(Keyboard::E)))
                {

                    if(guerreiro.getFaceRight())
                        texturaG.loadFromFile("Texturas/Dungeon/Sprites/Player/Sword/Defence0/parado0.1.png");
                    else
                        texturaG.loadFromFile("Texturas/Dungeon/Sprites/Player/Sword/Defence0/esquerdaParado.png");

                    guerreiro.shape.setTexture(&texturaG);

                }
                if(Keyboard::isKeyPressed(Keyboard::D)){

                string caminho = "Texturas/Dungeon/Sprites/Player/Sword/Defence0/andar";

                if(clock.getElapsedTime().asSeconds() > 0.10f){

                    if(indiceCaminho == 4)
                        indiceCaminho = 0;

                    else{

                        caminho = caminho + to_string(indiceCaminho) + ".png";
                        texturaG.loadFromFile(caminho);
                        caminho = "Texturas/Dungeon/Sprites/Player/Sword/Defence0/andar";
                        indiceCaminho++;

                    }

                    guerreiro.shape.setTexture(&texturaG);

                    clock.restart();

                }

                guerreiro.setFaceRight(true);

            }

            if(Keyboard::isKeyPressed(Keyboard::A)){

                string caminho = "Texturas/Dungeon/Sprites/Player/Sword/Defence0/esquerda";

                if(clock.getElapsedTime().asSeconds() > 0.10f){

                    if(indiceCaminho == 4)
                        indiceCaminho = 0;

                    else{

                        caminho = caminho + to_string(indiceCaminho) + ".png";
                        texturaG.loadFromFile(caminho);
                        caminho = "Texturas/Dungeon/Sprites/Player/Sword/Defence0/esquerda";
                        indiceCaminho++;

                    }

                    guerreiro.shape.setTexture(&texturaG);

                    clock.restart();
                    guerreiro.setFaceRight(false);

                }

            }
            if(Keyboard::isKeyPressed(Keyboard::E))
            {

                float deltaTiroG = (std::clock() - startG)/ (float)CLOCKS_PER_SEC;
                if(deltaTiroG >= 1.0f)
                {

                    if(guerreiro.getFaceRight())
                        texturaG.loadFromFile("Texturas/Dungeon/Sprites/Player/Sword/Defence0/ataque02.png");

                    else
                        texturaG.loadFromFile("Texturas/Dungeon/Sprites/Player/Sword/Defence0/ataque02esquerda.png");

                    guerreiro.shape.setTexture(&texturaG);
                }
            }


            if(magePlaying)
            {
                if(!(Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::Up)
                  || Keyboard::isKeyPressed(Keyboard::M)))
                    {

                        if(mago.getFaceRight())
                            texturaM.loadFromFile("Texturas/Dungeon/Sprites/Player/Scepter/Defence1/mago_idle_1.png");
                        else
                            texturaM.loadFromFile("Texturas/Dungeon/Sprites/Player/Scepter/Defence1/idleE1.png");

                        mago.shape.setTexture(&texturaM);
                    }
                                if(Keyboard::isKeyPressed(Keyboard::Right)){

                string caminho = "Texturas/Dungeon/Sprites/Player/Scepter/Defence1/andar";

                if(clockMago.getElapsedTime().asSeconds() > 0.10f){

                    if(indiceMago == 4)
                        indiceMago = 0;

                    else{

                        caminho = caminho + to_string(indiceMago) + ".png";
                        texturaM.loadFromFile(caminho);
                        caminho = "Texturas/Dungeon/Sprites/Player/Scepter/Defence1/andar";
                        indiceMago++;

                        }
                    mago.shape.setTexture(&texturaM);
                    clockMago.restart();
                    }
                mago.setFaceRight(true);
                }

            if(Keyboard::isKeyPressed(Keyboard::Left)){

                string caminho = "Texturas/Dungeon/Sprites/Player/Scepter/Defence1/esquerda";

                if(clockMago.getElapsedTime().asSeconds() > 0.10f){

                    if(indiceMago == 4)
                        indiceMago = 0;

                    else
                    {

                        caminho = caminho + to_string(indiceMago) + ".png";
                        texturaM.loadFromFile(caminho);
                        caminho = "Texturas/Dungeon/Sprites/Player/Scepter/Defence1/esquerda";
                        indiceMago++;

                    }

                    mago.shape.setTexture(&texturaM);

                    clockMago.restart();
                    mago.setFaceRight(false);

                }

            }
            if(Keyboard::isKeyPressed(Keyboard::M))
            {

                float deltaTiroM = (std::clock() - startM)/ (float)CLOCKS_PER_SEC;
                if(deltaTiroM >= 1.0f)
                {

                    if(mago.getFaceRight())

                        texturaM.loadFromFile("Texturas/Dungeon/Sprites/Player/Scepter/Defence1/atacar2.png");

                    else
                        texturaM.loadFromFile("Texturas/Dungeon/Sprites/Player/Scepter/Defence1/atacarE2.png");

                    mago.shape.setTexture(&texturaM);


                    MagiaMana* p;
                    p = new MagiaMana(mago.shape.getPosition(), mago.getFaceRight());
                    if(fase == 1)
                        floresta.colisor.listaProjeteisP.incluir(static_cast<Projetil*>(p));
                    else if(fase == 2)
                        castelo.colisor.listaProjeteisP.incluir(static_cast<Projetil*>(p));
                    else if(fase == 3)
                        fim.colisor.listaProjeteisP.incluir(static_cast<Projetil*>(p));
                    deltaTiroM = 0.0f;
                    startM = std::clock();
                }

            }

        }
            if(!stageSelect)
            {
                guerreiro.atualizar(deltaTime);

                if(magePlaying)
                {
                    mago.atualizar(deltaTime);
                }
            }



            if(guerreiro.shape.getPosition().y >= 500.0f)
            {
                guerreiro.shape.setPosition(-20.0f, -400.0f);
                mago.shape.setPosition(-20.0f, -400.0f);

                if(!guerreiro.isInvincible)
                {
                    int aux = guerreiro.getNumVidas();
                    aux--;
                    guerreiro.setNumVidas(aux);
                    guerreiro.isInvincible = true;
                    guerreiro.startInv = std::clock();
                }
            }
                if(mago.shape.getPosition().y >= 500.0f)
                {
                    guerreiro.shape.setPosition(-20.0f, -400.0f);
                    mago.shape.setPosition(-20.0f, -400.0f);

                    if(!mago.isInvincible)
                    {
                        int aux = mago.getNumVidas();
                        aux--;
                        mago.setNumVidas(aux);
                        mago.isInvincible = true;
                        mago.startInv = std::clock();
                    }
                }

                if(fase == 1){

                        if(floresta.colisor.checkCollision(&guerreiro, &direction, &score))
                            guerreiro.onCollision(direction);
                        else
                            guerreiro.canJump = false;
                        if(magePlaying)
                        {
                            if(floresta.colisor.checkCollision(&mago, &direction, &score))
                                mago.onCollision(direction);
                            else
                                mago.canJump = false;
                        }

                        floresta.colisor.checkCollisionPer(&score);
                        floresta.colisor.checkCollisionProj();
                        floresta.colisor.atualizar(deltaTime);

                    for (floresta.colisor.listaProjeteisP.itr = floresta.colisor.listaProjeteisP.deck.begin(); floresta.colisor.listaProjeteisP.itr != floresta.colisor.listaProjeteisP.deck.end(); ++floresta.colisor.listaProjeteisP.itr)
                    {
                        if((*floresta.colisor.listaProjeteisP.itr)->atualizar())
                        {

                        }
                        else
                        {
                            floresta.colisor.listaProjeteisP.deletar(floresta.colisor.listaProjeteisP.itr);
                        }
                    }

                    for (floresta.colisor.listaProjeteis.itr = floresta.colisor.listaProjeteis.deck.begin(); floresta.colisor.listaProjeteis.itr != floresta.colisor.listaProjeteis.deck.end(); ++floresta.colisor.listaProjeteis.itr)
                    {
                        if((*floresta.colisor.listaProjeteis.itr)->atualizar())
                        {

                        }
                        else
                        {
                            floresta.colisor.listaProjeteis.deletar(floresta.colisor.listaProjeteis.itr);
                        }
                    }
                }

                if(fase == 2){

                        if(castelo.colisor.checkCollision(&guerreiro, &direction, &score))
                            guerreiro.onCollision(direction);
                        else
                            guerreiro.canJump = false;
                        if(magePlaying)
                        {
                            if(castelo.colisor.checkCollision(&mago, &direction, &score))
                                mago.onCollision(direction);
                            else
                                mago.canJump = false;
                        }

                        castelo.colisor.checkCollisionPer(&score);
                        castelo.colisor.checkCollisionProj();
                        castelo.colisor.atualizar(deltaTime);

                    for (castelo.colisor.listaProjeteisP.itr = castelo.colisor.listaProjeteisP.deck.begin(); castelo.colisor.listaProjeteisP.itr != castelo.colisor.listaProjeteisP.deck.end(); ++castelo.colisor.listaProjeteisP.itr)
                    {
                        if((*castelo.colisor.listaProjeteisP.itr)->atualizar())
                        {

                        }
                        else
                        {
                            castelo.colisor.listaProjeteisP.deletar(castelo.colisor.listaProjeteisP.itr);
                        }
                    }

                    for (castelo.colisor.listaProjeteis.itr = castelo.colisor.listaProjeteis.deck.begin(); castelo.colisor.listaProjeteis.itr != castelo.colisor.listaProjeteis.deck.end(); ++castelo.colisor.listaProjeteis.itr)
                    {
                        if((*castelo.colisor.listaProjeteis.itr)->atualizar())
                        {

                        }
                        else
                        {
                            castelo.colisor.listaProjeteis.deletar(castelo.colisor.listaProjeteis.itr);
                        }
                    }
                }

                if(fase == 3){

                        if(fim.colisor.checkCollision(&guerreiro, &direction, &score))
                            guerreiro.onCollision(direction);
                        else
                            guerreiro.canJump = false;
                        if(magePlaying)
                        {
                            if(fim.colisor.checkCollision(&mago, &direction, &score))
                                mago.onCollision(direction);
                            else
                                mago.canJump = false;
                        }
                        if(fim.colisor.pDrag != nullptr)
                        {
                            if(fim.colisor.checkCollision(fim.colisor.pDrag, &guerreiro, &direction, &score))
                                guerreiro.onCollision(direction);

                            if(magePlaying)
                            {
                                if(fim.colisor.checkCollision(fim.colisor.pDrag, &mago, &direction, &score))
                                    mago.onCollision(direction);
                            }
                            fim.colisor.checkCollision(fim.colisor.pDrag, &score);
                        }

                        fim.colisor.checkCollisionPer(&score);
                        fim.colisor.checkCollisionProj();
                        fim.colisor.atualizar(deltaTime);

                    for (fim.colisor.listaProjeteisP.itr = fim.colisor.listaProjeteisP.deck.begin(); fim.colisor.listaProjeteisP.itr != fim.colisor.listaProjeteisP.deck.end(); ++fim.colisor.listaProjeteisP.itr)
                    {
                        if((*fim.colisor.listaProjeteisP.itr)->atualizar())
                        {

                        }
                        else
                        {
                            fim.colisor.listaProjeteisP.deletar(fim.colisor.listaProjeteisP.itr);
                        }
                    }

                    for (fim.colisor.listaProjeteis.itr = fim.colisor.listaProjeteis.deck.begin(); fim.colisor.listaProjeteis.itr != fim.colisor.listaProjeteis.deck.end(); ++fim.colisor.listaProjeteis.itr)
                    {
                        if((*fim.colisor.listaProjeteis.itr)->atualizar())
                        {

                        }
                        else
                        {
                            fim.colisor.listaProjeteis.deletar(fim.colisor.listaProjeteis.itr);
                        }
                    }
                }
            }

            if(guerreiro.getNumVidas() <= 0 || mago.getNumVidas() <= 0)
            {
                string s;
                scoreTexto.setPosition(view.getCenter().x - view.getSize().x / 3.0f, view.getCenter().y - view.getSize().y / 15.75f);
                s = "Score: " + to_string(score);
                scoreTexto.setString(s);
                scoreTexto.setCharacterSize(50);
                scoreTexto.setFillColor(sf::Color::White);
                scoreTexto.setFont(fonte);

                Texture textura;
                textura.loadFromFile("morte.png");
                blank.setTexture(&textura);
                blank.setFillColor(Color::Transparent);
                blank.setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2);
                blank.setSize(Vector2f(80.0f, 60.0f));

                if(fase == 1)
                    window.draw(floresta.shape);
                else if(fase == 2)
                    window.draw(castelo.shape);
                else if(fase == 3)
                    window.draw(fim.shape);
                window.draw(scoreTexto);
                window.display();


                do
                {
                    window.pollEvent(event);
                }while(event.type != sf::Event::EventType::KeyPressed && event.type != sf::Event::EventType::Closed);

                window.close();
            }

            vidasGuerreiro.setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2);
            string s = "Vidas Guer: " + to_string(guerreiro.getNumVidas());
            vidasGuerreiro.setString(s);
            vidasGuerreiro.setCharacterSize(20);
            vidasGuerreiro.setFillColor(sf::Color::Blue);
            vidasGuerreiro.setFont(fonte);

            vidasGuerreiroShade.setPosition(view.getCenter().x - view.getSize().x / 2 + 1, view.getCenter().y - view.getSize().y / 2 + 1);
            s = "Vidas Guer: " + to_string(guerreiro.getNumVidas());
            vidasGuerreiroShade.setString(s);
            vidasGuerreiroShade.setCharacterSize(20);
            vidasGuerreiroShade.setFillColor(sf::Color::White);
            vidasGuerreiroShade.setFont(fonte);

            if(magePlaying)
            {
                vidasMago.setPosition(view.getCenter().x + view.getSize().x / 4 - 60, view.getCenter().y - view.getSize().y / 2);
                s = "Vidas Mago: " + to_string(mago.getNumVidas());
                vidasMago.setString(s);
                vidasMago.setCharacterSize(20);
                vidasMago.setFillColor(sf::Color::Red);
                vidasMago.setFont(fonte);

                vidasMagoShade.setPosition(view.getCenter().x + view.getSize().x / 4 - 59, view.getCenter().y - view.getSize().y / 2 + 1);
                s = "Vidas Mago: " + to_string(mago.getNumVidas());
                vidasMagoShade.setString(s);
                vidasMagoShade.setCharacterSize(20);
                vidasMagoShade.setFillColor(sf::Color::White);
                vidasMagoShade.setFont(fonte);
            }
            else
            {
                vidasMago.setPosition(view.getCenter().x + view.getSize().x / 4 - 60, view.getCenter().y - view.getSize().y / 2);
                vidasMago.setFillColor(sf::Color::Black);
                vidasMagoShade.setPosition(view.getCenter().x + view.getSize().x / 4 - 59, view.getCenter().y - view.getSize().y / 2 + 1);
                vidasMagoShade.setFillColor(sf::Color::Black);
            }

            scoreTexto.setPosition(view.getCenter().x + view.getSize().x / 256 - 100, view.getCenter().y - view.getSize().y / 2);
            s = "Score: " + to_string(score);
            scoreTexto.setString(s);
            scoreTexto.setCharacterSize(20);
            scoreTexto.setFillColor(sf::Color::White);
            scoreTexto.setFont(fonte);

            blank.setTexture(nullptr);
            blank.setFillColor(Color::Black);
            blank.setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2);
            blank.setSize(Vector2f(800.0f, 25.0f));


            if(fase == 0)
            {
                fase = 1;
            }

            if(fase == 1){

                floresta.shape.setPosition(view.getCenter().x - floresta.shape.getGlobalBounds().width / 2, view.getCenter().y - floresta.shape.getGlobalBounds().height / 2);
                window.draw(floresta.shape);
                floresta.colisor.desenhar(&window);
                window.draw(guerreiro.shape);
                if(magePlaying)
                    window.draw(mago.shape);


            }

            else if(fase == 2){

                castelo.shape.setPosition(view.getCenter().x - castelo.shape.getGlobalBounds().width / 2, view.getCenter().y - castelo.shape.getGlobalBounds().height / 2);
                window.draw(castelo.shape);
                castelo.colisor.desenhar(&window);
                window.draw(guerreiro.shape);
                if(magePlaying)
                    window.draw(mago.shape);


            }

            else if(fase == 3){

                fim.shape.setPosition(view.getCenter().x - fim.shape.getGlobalBounds().width / 2, view.getCenter().y - fim.shape.getGlobalBounds().height / 2);
                window.draw(fim.shape);
                fim.colisor.desenhar(&window);
                window.draw(guerreiro.shape);
                if(magePlaying)
                    window.draw(mago.shape);


            }


            window.draw(blank);
            window.draw(vidasGuerreiroShade);
            window.draw(vidasMagoShade);
            window.draw(vidasGuerreiro);
            window.draw(vidasMago);
            window.draw(scoreTexto);

        }
        if(magePlaying)
                view.setCenter((guerreiro.shape.getPosition().x + mago.shape.getPosition().x)/2, (guerreiro.shape.getPosition().y + mago.shape.getPosition().y)/2);
            else
                view.setCenter(guerreiro.shape.getPosition().x, guerreiro.shape.getPosition().y);
            window.setView(view);


        if(!playable)
        {
            deltaTimeOp = (std::clock() - startOp)/ (float)CLOCKS_PER_SEC;
            if(menuP.controlar(deltaTimeOp, &view, &opMenu))
            {
                startOp = std::clock();
            }
            menuP.imprimir(&window);
        }
        if(!playing)
        {
            deltaTimeOprin = (std::clock() - startOprin)/ (float)CLOCKS_PER_SEC;
            if(menuPrin.controlar(deltaTimeOprin, &view, &opMenuPrin))
            {
                startOprin = std::clock();
            }
            menuPrin.imprimir(&window);
        }
        int aux;
        if(stageSelect)
        {
            deltaTimeOprin = (std::clock() - startOprin)/ (float)CLOCKS_PER_SEC;
            if(menuPrin.controlar(deltaTimeOprin, &view, &stageSelect, &fase, &aux))
            {
                startOprin = std::clock();
            }
            menuPrin.imprimir(&window);
            deltaTime = 0.0f;
        }

        if(magePlaying)
        {
            if(guerreiro.shape.getPosition().x >= 7800 && guerreiro.shape.getPosition().y <= -100 && mago.shape.getPosition().x >= 7800 && mago.shape.getPosition().y <= -100 && fase == 1){

                guerreiro.shape.setPosition(Vector2f(-20.0f, -200.0f));
                mago.shape.setPosition(Vector2f(-20.0f, -200.0f));
                fase = 2;
                floresta.colisor.listaProjeteisP.deck.clear();
                floresta.colisor.listaPlataformas.plataformas.clear();
                floresta.colisor.listaObstaculos.lista.clear();
                floresta.colisor.listaInimigos.lista.clear();
                floresta.colisor.listaProjeteis.deck.clear();
                castelo.build();
            }
        }
        else if(guerreiro.shape.getPosition().x >= 7800 && guerreiro.shape.getPosition().y <= -100 && fase == 1)
        {
            guerreiro.shape.setPosition(Vector2f(-20.0f, -200.0f));
            fase = 2;
            floresta.colisor.listaProjeteisP.deck.clear();
            floresta.colisor.listaPlataformas.plataformas.clear();
            floresta.colisor.listaObstaculos.lista.clear();
            floresta.colisor.listaInimigos.lista.clear();
            floresta.colisor.listaProjeteis.deck.clear();
            castelo.build();
        }
        if(magePlaying)
        {
            if(guerreiro.shape.getPosition().x >= 8900 && guerreiro.shape.getPosition().y <= -50 && mago.shape.getPosition().x >= 8900 && mago.shape.getPosition().y <= -50 && fase == 2){

                guerreiro.shape.setPosition(Vector2f(-20.0f, -200.0f));
                mago.shape.setPosition(Vector2f(-20.0f, -200.0f));
                fase = 3;
                castelo.colisor.listaProjeteisP.deck.clear();
                castelo.colisor.listaPlataformas.plataformas.clear();
                castelo.colisor.listaObstaculos.lista.clear();
                castelo.colisor.listaInimigos.lista.clear();
                castelo.colisor.listaProjeteis.deck.clear();
                fim.build();
            }
        }
        else if(guerreiro.shape.getPosition().x >= 8900 && guerreiro.shape.getPosition().y <= -50 && fase == 2)
        {
            guerreiro.shape.setPosition(Vector2f(-20.0f, -200.0f));
            fase = 3;
            castelo.colisor.listaProjeteisP.deck.clear();
            castelo.colisor.listaPlataformas.plataformas.clear();
            castelo.colisor.listaObstaculos.lista.clear();
            castelo.colisor.listaInimigos.lista.clear();
            castelo.colisor.listaProjeteis.deck.clear();
            fim.build();
        }
        window.display();
        window.clear();
    }
}
