#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include <stdexcept>
//#include "memtrace.h"
template <class T> class Lista {
    struct Listaelem{
        T adat;
        Listaelem *kov;
        Listaelem(Listaelem *p = NULL): kov(p) {}
    };
    Listaelem *elso;
    bool hasonlit(T d1, T d2) {return d1 < d2;}
public:
    Lista() {elso = new Listaelem;}
    void beszur(const T& dat);
class iterator{
    Listaelem *akt;
public:
    iterator():akt(NULL){};
    iterator(const Lista& l): akt(l.elso) {
        if(akt->kov == NULL) akt = NULL;
        }
    iterator& operator++(){
        if(akt != NULL){
            akt = akt->kov;
            if(akt->kov == NULL) akt = NULL;
        }
    return *this;
    }
    iterator operator++(int){
        iterator tmp = *this;
        operator++();
        return tmp;
    }
    bool operator!=(const iterator& i) const {
        return akt != i.akt;
    }
    T& operator*(){
        if(akt != NULL) return akt->adat;
        else throw std::out_of_range("Hibás");
    }
    T* operator->(){
        if(akt != NULL) return &akt->adat;
        else throw std::out_of_range("Hibás");
    }
};

    iterator begin(){return (iterator(*this));}
    iterator end(){return (iterator());}

    void torol(const T& dat);
    ~Lista();
};

template <class T>
void Lista<T>::beszur(const T& dat){
    Listaelem *p;
    for(p = elso; p->kov != NULL && hasonlit(p->adat, dat); p = p->kov);

    Listaelem *uj = new Listaelem(*p);
    p->adat = dat;
    p->kov = uj;
}

template <class T>
Lista<T>::~Lista(){
    while(elso != NULL){
        Listaelem* temp = elso->kov;
        delete elso;
        elso = temp;
    }
}

template <class T>
void Lista<T>::torol(const T& dat){
    Listaelem *lemarado = NULL;
    Listaelem *futo = elso;

    while(futo != NULL && &(futo->adat) != &dat){
        lemarado = futo;
        futo = futo->kov;
    }
    if(futo != NULL){
        if(lemarado == NULL)
            elso = futo->kov;
        else
            lemarado->kov = futo->kov;
        delete futo;
    }

}

#endif // LISTA_H_INCLUDED
