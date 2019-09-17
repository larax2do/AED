#include <iostream>
//#include "ListaEnlazadaTipo.h"
#include "ListaDesordenada.h"
#include "ListaOrdenada.h"

using namespace std;

int main()
{
    //ListaDesordenada<int> lista;
    //lista.insertarDelante(1);
    //lista.insertarDelante(5);
    //lista.imprimir();

    ListaOrdenada<int> lista1;
    lista1.insertar(3);
    lista1.insertar(4);
    lista1.insertar(5);
    lista1.insertar(33);
    lista1.insertar(44);
    lista1.insertar(11);
    lista1.insertar(335);
    lista1.insertar(64);
    lista1.insertar(999);
    lista1.insertar(4);
    lista1.insertar(66);
    lista1.imprimir();
    //NodoTipo<int> *nodito = new NodoTipo<int>(10,NULL);
    cout << "Hello world!" << endl;
    return 0;
}
