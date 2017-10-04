#include <iostream>
#include"../HashMap/HashMap.h"
using namespace std;
unsigned int hashfuncion(int);
HashMap tabla(10,hashfuncion);
int main() {
    int n=0;
    cout<<endl<<"Seleccione una opcion:"
        <<endl<<" 1)Insertar elemento"
        <<endl<<" 2)Obtener elemento"
        <<endl<<" 3)Eliminar elemnto"
        <<endl<<" 4)Salir"<<endl;
    cin>>n;
    
}

unsigned int hashfuncion(int num){

}