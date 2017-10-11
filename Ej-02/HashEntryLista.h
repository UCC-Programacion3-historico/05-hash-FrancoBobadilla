#ifndef HASHENTRY_H
#define HASHENTRY_H

template<class K, class T>
class HashEntryLista {
private:
    K key;
    T dato;
public:

    HashEntryLista(K key, T dato) : key(key), dato(dato) {}

    K getKey() const {
        return key;
    }

    void setKey(K key) {
        HashEntryLista::key = key;
    }

    T getDato() const {
        return dato;
    }

    void setDato(T dato) {
        HashEntryLista::dato = dato;
    }
};

#endif //HASHENTRY_H