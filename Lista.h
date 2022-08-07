#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>

template <class TL>

class Lista {

     public:

        Lista();
        ~Lista();

        void inicializar();
        bool adicionar(TL* pElemento);
        void listar();


        template <class TE>
        class Elemento {

            private:

                Elemento<TE>* pProximo;
                TE* pInfo;

            public:

                Elemento(){ pProximo = nullptr; pInfo = nullptr; }
                ~Elemento(){}

                void setProximo(Elemento<TE>* proximo){ pProximo = proximo; }
                Elemento<TE>* getProximo(){ return pProximo;}
                void setInfo(TE* info){ pInfo = info;}
                TE* getInfo(){ return pInfo; }


        };
        Elemento<TL>* begin()					{	return pPrimeiro;				}
        Elemento<TL>* end()						{	return pAtual->getProximo();	}



    private:



    protected:

        Elemento<TL>* pPrimeiro;
        Elemento<TL>* pAtual;

};


template <class TL>
Lista<TL>::Lista(){

    inicializar();

}

template <class TL>
Lista<TL>::~Lista(){}

template <class TL>
void Lista<TL>::inicializar(){

    pPrimeiro = nullptr;
    pAtual = nullptr;

}

template <class TL>
bool Lista<TL>::adicionar(TL* pElemento){

    Elemento<TL>* pAux;

    pAux = new Elemento<TL>();

    pAux->setInfo(pElemento);

    if(pAux != nullptr){

        if(pPrimeiro == nullptr){

            pPrimeiro = pAux;
            pAtual = pPrimeiro;

        }

        else{

            pAux->setProximo(nullptr);
            pAtual->setProximo(pAux);
            pAtual = pAtual->getProximo();

        }

        return true;
    }

    return false;
}

template <class TL>
void Lista<TL>::listar(){

    Elemento<TL>* pAux;
    pAux = pPrimeiro;

    if(pPrimeiro != nullptr){

        while(pAux != nullptr){

            pAux = pAux->getProximo();

        }

    }

}


#endif // LISTA_H_INCLUDED
