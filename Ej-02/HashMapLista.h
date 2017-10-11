#ifndef HASHMAPLISTA_H
#define HASHMAPLISTA_H

#include "HashEntryLista.h"
#include "Lista.h"
#include <iostream>

using namespace std;

template<class K, class T>
class HashMapLista {
private:
    Lista<HashEntryLista<K, T>> *tabla;

    unsigned int tamanio;

    static unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);


public:
    HashMapLista(unsigned int tamanio);

    HashMapLista(unsigned int tamanio, unsigned int (*hashFuncP)(K clave));

    T get(K clave);

    void put(K clave, T valor);

    void remove(K clave);

    ~HashMap();

    bool esVacio();

    void print();

};

template<class K, class T>
HashMapLista<K, T>::HashMapLista(unsigned int tamanio) {
    this->tamanio = tamanio;
    hashFuncP = hashFunc;
    tabla = new Lista<HashEntryLista<K, T>>[tamanio];
}

template<class K, class T>
HashMapLista<K, T>::~HashMap() {
    for (int i = 0; i < tamanio; i++)
        tabla[i].vaciar();
}

template<class K, class T>
T HashMapLista<K, T>::get(K clave) {
    unsigned int pos = hashFuncP(clave) % tamanio;
    if (tabla[pos].esVacia())throw 2;
    return tabla[pos];
}

template<class K, class T>
void HashMapLista<K, T>::put(K clave, T valor) {
    tabla[hashFuncP(clave) % tamanio].insertarUltimo(valor);
}

template<class K, class T>
void HashMapLista<K, T>::remove(K clave) {
    unsigned int pos = hashFuncP(clave) % tamanio;
    if (tabla[pos].esVacia()) throw 3;
    tabla[pos].vaciar();
}

template<class K, class T>
bool HashMapLista<K, T>::esVacio() {
    for (int i = 0; i < tamanio; i++)
        if (!tabla[i].esVacia())
            return false;
    return true;
}

template<class K, class T>
unsigned int HashMapLista<K, T>::hashFunc(K clave) {
    return clave;
}

template<class K, class T>
HashMapLista<K, T>::HashMapLista(unsigned int tamanio, unsigned int (*fp)(K)) {
    this->tamanio = tamanio;
    this->hashFuncP = fp;
    tabla = new Lista<HashEntryLista<K, T>>[tamanio];
}

template<class K, class T>
void HashMapLista<K, T>::print() {
    int j = 0;
    for (int i = 0; i < tamanio; i++) {
        cout << " - ";
        while (tabla[i].esVacia()) {
            cout << endl << " " << tabla[i].getDato(j).getDato();
            j++;
        }
        cout << endl;
    }
}

#endif //HASHMAPLISTA_H