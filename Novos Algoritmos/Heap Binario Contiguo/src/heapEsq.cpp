#include "heapEsq.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

heapEsq::heapEsq(){
    //ctor
}
No* heapEsq::criaHeapEsq(int ch){

    No* aux = new No();
    aux->setValor(ch);
    aux->setMarca(1);
    aux->setAnt(NULL);
    aux->setProx(NULL);

    return aux;
}
int heapEsq::menor(int a, int b){
    if (a<b)
        return a;
    else return b;
}
int heapEsq::calculaDist(No* p){
    if(p == NULL) return 0;
    return (1 + menor( calculaDist(p->getAnt()) , calculaDist(p->getProx())));
}
No* heapEsq::uniaoHeapEsq(No* H1, No* H2){
    if(H1 == NULL) return H2;
    if(H2 == NULL) return H1;
    if(H1->getValor() < H2->getValor()){
        No* aux;
        aux = H1;
        H1 = H2;
        H2 = aux;
    }
    if(H1->getAnt() == NULL)
        H1->setAnt(H2);
    else{
        No* H3;
        H3 = H1->getProx();
        H3 = uniaoHeapEsq(H3, H2);
        H1->setProx(H3);
        H1->getAnt()->setMarca(calculaDist(H1->getAnt()));
        H1->getProx()->setMarca(calculaDist(H1->getProx()));
        if(H1->getAnt()->getMarca() < H1->getProx()->getMarca()){
            No* aux;
            aux = H1->getAnt();
            H1->setAnt(H1->getProx());
            H1->setProx(aux);
        }

    }
    H1->setMarca(calculaDist(H1) + 1);
    return H1;
}
void heapEsq::insere(int x){

    if(H == NULL) {
        H = criaHeapEsq(x);
    }
    No* H2 = criaHeapEsq(x);
    H = uniaoHeapEsq(H, H2);
}
void heapEsq::remover(No* H1){

    H = uniaoHeapEsq(H, uniaoHeapEsq(H1->getAnt(), H1->getProx()));

}
No* heapEsq::busca(No* H1, int x){

    No* aux;
    if(H1 == NULL){

        return NULL;

    }else{

        if(H1->getValor() == x){

            return H1;

        }else{

            aux = busca(H1->getAnt(),x);
            if(aux != NULL){

                return aux;

            }else{

                aux = busca(H1->getProx(),x);
                return aux;

            }

        }

    }

}
void heapEsq::removeValor(int x){

    No* aux = busca(H,x);
    if(aux == NULL){

        cout<<"No a remover nao existe"<<endl;

    }else{

        remover(aux);
        delete aux;

    }

}
void heapEsq::deletaH(No* H1){

    if(H1 != NULL){

        deletaH(H1->getAnt());
        deletaH(H1->getProx());
        delete H1;

    }

}
void heapEsq::imprime(No* H1){

    if(H1 != NULL){

        imprime(H1->getAnt());
        imprime(H1->getProx());
        cout <<"O no "<<H1->getValor()<<" tem os filho(s) ";
        if(H1->getAnt() != NULL){

            cout<<H1->getAnt()->getValor();

        }
        if(H1->getProx() != NULL){

            cout<<" e "<<H1->getProx()->getValor()<<"."<<endl;

        }
        cout<<endl;
    }

}
void heapEsq::imprimeHeap(){

    imprime(H);

}
No* heapEsq::getRaiz(){

    return H;

}
heapEsq::~heapEsq(){

    deletaH(H);

}
