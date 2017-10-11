#ifndef NODO_H
#define NODO_H

#include <iostream>

template <class T>
class Nodo{
private:
    T dato;
    Nodo *next;
public:
    Nodo() {next=NULL;}
    Nodo(T d, Nodo *n) {dato=d; next=n;}
    void setDato(T d) {dato=d;}
    void setNext(Nodo *n) {next=n;}
    T getDato() {return dato;}
    Nodo *getNext() {return next;}
};

#endif //NODO_H
