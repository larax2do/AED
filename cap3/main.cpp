#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

//UNO

template <typename Object>
void printLots(list<Object> L, list<int>P)
{
    typename list<int>::const_iterator pIterador;
        //para recorrer la lista P
    typename list<Object>::const_iterator lIterador;
        //para recorrer la lista L
    int inicio=0;
    lIterador=L.begin();
    for(pIterador=P.begin();pIterador!=P.end()&& lIterador!=L.end();pIterador++)
        //Recorre la lista hasta que una de ellas llegue al final
    {
        while(inicio<*pIterador && lIterador!=L.end())
        {
            //Busca la posicion
            inicio++;
            lIterador++;
        }
        if(lIterador!=L.end())
        {
            //salida del objeto
            std::cout<<*lIterador<<std::endl;
        }
    }
}

//DOS
//A

template<typename Object>
struct NodoTipo
{
    Object Dato;
    NodoTipo<Object>* siguiente;
};

template <typename Obejct>
void intercambio(NodoTipo<Object>* antes)
{
    //antes  se ubica detras de los nodos a intercambiar
    //se intercambia centro con despues
    NodoTipo<Object>* centro;
    NodoTipo<Object>* despues;

    centro=antes->siguiente;
    despues=centro->siguiente;

    centro->siguiente=despues->siguiente;
    antes->siguiente=despues;
    despues->siguiente=centro;
}

//B

template<typename Object>
struct NodoDTipo
{
    Object Dato;
    NodoDTipo<Object>* siguiente;
    NodoDTipo<Object>* anterior;
};

template <typename Obejct>
void intercambio(NodoDTipo<Object>* centro)
{
    //se intercambia centro con el despues
    NodoDTipo<T>* antes;
    NodoDTipo<T>* despues;

    //se asignan los punteros inicialmente
    antes=centro->anterior;
    despues=centro->siguiente;

    //se intercambian los enlaces
    centro->siguiente=despues->siguiente;
    antes->siguiente=despues;
    despues->siguiente=centro;
    centro->siguiente->anterior=centro;
    centro->anterior=despues;
    despues->anterior=antes;


int main()
{
    //UNO
    /*
    list<string> listaL;
    listaL.push_front("a");
    listaL.push_front("b");
    listaL.push_front("c");
    listaL.push_front("d");
    listaL.push_front("3");


    list<int> listaP;
    listaP.push_back(0);
    listaP.push_back(1);
    listaP.push_back(4);
    listaP.push_back(5);
    printLots(listaL,listaP);
    */

    //DOS

    cout << "Hello world!" << endl;
    return 0;
}
