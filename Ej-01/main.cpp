#include <iostream>
#include"../HashMap/HashMap.h"

using namespace std;

unsigned int hashfuncion(int n){return (n*n)%23;};

HashMap<int, int> tabla(23, hashfuncion);

int main() {
    bool i = true;
    while (i == true) {
        int n = 0, clave, valor;
        cout << endl << "Seleccione una opcion:"
             << endl << " 1)Insertar elemento"
             << endl << " 2)Obtener elemento"
             << endl << " 3)Eliminar elemnto"
             << endl << " 4)Salir" << endl;
        cin >> n;
        switch (n) {
            case 1: {
                cout << endl << "Ingrese valor:" << endl;
                cin >> valor;
                cout << endl << "Ingrese clave:" << endl;
                cin >> clave;
                try {
                    tabla.put(clave, valor);
                    cout << endl << "Elemento ingresado" << endl;
                } catch (int e) {
                    cout << endl << "ERROR: CELDA OCUPADA" << endl;
                }

                break;
            }
            case 2: {
                cout << endl << "Ingrese clave:" << endl;
                cin >> clave;
                try {
                    cout << endl << tabla.get(clave) << endl;
                } catch (int e) {
                    cout << endl << "Celda vacia" << endl;
                }
                break;
            }
            case 3: {
                cout << endl << "Ingrese clave:" << endl;
                cin >> clave;
                try {
                    tabla.remove(clave);
                    cout << endl << "Elemento removido" << endl;
                } catch (int e) {
                    cout << endl << "Celda vacia" << endl;
                }
                break;
            }
            case 4: {
                i = false;
            }
            default: {
                cout << endl << "Opcion invalida" << endl;
                break;
            }
        }
    }
    return 0;
}