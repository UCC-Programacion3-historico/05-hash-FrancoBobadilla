#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

template<class T>
class Lista {
private:
    Nodo<T> *inicio;
public:
    Lista();

    Lista(Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(int pos);

    T getDato(int pos);

    void reemplazar(int pos, T dato);

    void vaciar();
};


template<class T>
Lista<T>::Lista() {
    inicio = NULL;
}


template<class T>
Lista<T>::Lista(Lista<T> &li) {
    inicio = NULL;
    int fin = li.getTamanio();
    for (int i = 0; i < fin; i++)
        this->insertar(i, li.getDato(i));
}


template<class T>
Lista<T>::~Lista() {
    this->vaciar();
}


template<class T>
bool Lista<T>::esVacia() {
    return inicio == NULL;
}


template<class T>
int Lista<T>::getTamanio() {
    Nodo<T> *aux = inicio;
    int cont = 0;
    while (aux != NULL) {
        cont++;
        aux = aux->getNext();
    }
    return cont;
}


template<class T>
void Lista<T>::insertar(int pos, T dato) {
    if (pos == 0) {
        Nodo<T> *nn = new Nodo<T>(dato, inicio);
        inicio = nn;
        return;
    }
    int cont = 0;
    Nodo<T> *aux = inicio;

    while (aux != NULL && cont < pos - 1) {
        cont++;
        aux = aux->getNext();
    }
    if (aux == NULL) throw 1;

    Nodo<T> *nn = new Nodo<T>(dato, aux->getNext());
    aux->setNext(nn);
}


template<class T>
void Lista<T>::insertarPrimero(T dato) {
    Nodo<T> *nn = new Nodo<T>(dato, inicio);
    inicio = nn;
}


template<class T>
void Lista<T>::insertarUltimo(T dato) {
    Nodo<T> *aux = inicio;
    int cont = 0;
    if (inicio == NULL)Lista<T>::insertarPrimero(dato);
    else {
        while (aux->getNext() != NULL) {
            cont++;
            aux = aux->getNext();
        }
        Nodo<T> *nn = new Nodo<T>(dato, NULL);
        aux->setNext(nn);
    }
}


template<class T>
void Lista<T>::remover(int pos) {

    Nodo<T> *aux = inicio;
    Nodo<T> *tmp;
    int cont = 0;

    while (aux != NULL && cont < pos - 1) {
        cont++;
        aux = aux->getNext();
    }

    if (aux == NULL) throw 1;

    if (pos == 0) {
        inicio = inicio->getNext();
        return;
    }

    tmp = aux->getNext();

    if (tmp == NULL) throw 1;

    aux->setNext(tmp->getNext());

    delete tmp;
}


template<class T>
T Lista<T>::getDato(int pos) {
    Nodo<T> *aux = inicio;
    int cont = 0;
    while (cont < pos && aux != NULL) {
        cont++;
        aux = aux->getNext();
    }
    if (pos != cont || inicio == NULL) throw 1;
    return aux->getDato();
}


template<class T>
void Lista<T>::reemplazar(int pos, T dato) {
    Nodo<T> *aux = inicio;
    int cont = 0;
    while (cont < pos && aux != NULL) {
        cont++;
        aux = aux->getNext();
    }
    if (aux == NULL || inicio == NULL)throw 1;
    aux->setDato(dato);
}


template<class T>
void Lista<T>::vaciar() {
    Nodo<T> *aux = inicio;
    Nodo<T> *ant;
    while (aux != NULL) {
        ant = aux;
        aux = aux->getNext();
        delete ant;
    }
    inicio = NULL;
}


#endif //LISTA_H