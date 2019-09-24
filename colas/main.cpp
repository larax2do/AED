#include <iostream>
#include "ColaTipo.h"
#include "ListaColaTipo.h"

using namespace std;

int main()
{
    ListaColaTipo<int> colita;
    colita.agregar(1);
    colita.agregar(2);
    colita.agregar(3);
    colita.agregar(4);
    colita.agregar(5);
    colita.agregar(6);
    colita.mostrar();
    ListaColaTipo<int> col2(colita);
    //col2=colita;
    colita.mostrar();
    colita.inicializarCola();
    colita.mostrar();
    colita.agregar(123);
    colita.mostrar();

    cout << "Hello world!" << endl;
    col2.mostrar();
    return 0;
}
