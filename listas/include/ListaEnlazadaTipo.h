#ifndef LISTAENLAZADATIPO_H
#define LISTAENLAZADATIPO_H
#include <cstddef>
#include <iostream>
#include "NodoTipo.h"
#include "IteradorLista.h"


template <class T>
class ListaEnlazadaTipo
{
    public:
        const ListaEnlazadaTipo<T>& operator=(const ListaEnlazadaTipo<T>&);
        void inicializarLista();
        bool esListaVacia() const;
        void imprimir() const;
        int longitud() const;
        void destruirLista();
        T cabeza() const;
        T cola() const;
        virtual bool buscar(const T& item) const=0;
        virtual void insertarDelante(const T& nuevo) =0;
        virtual void insertarDetras(const T& nuevo) =0;
        virtual void eliminarNodo(const T& item) =0;
        IteradorLista<T> inicio();
        IteradorLista<T> fin();
        ListaEnlazadaTipo();
        ListaEnlazadaTipo(const ListaEnlazadaTipo<T>& otra);
        ~ListaEnlazadaTipo();

    protected:
        int contador;
        NodoTipo<T> *primero;
        NodoTipo<T> *ultimo;

    private:
        void copiarLista(const ListaEnlazadaTipo<T>& otra);
};



template <class T>
bool ListaEnlazadaTipo<T>::esListaVacia() const
{
    return (primero==NULL);
}

template <class T>
ListaEnlazadaTipo<T>::ListaEnlazadaTipo()
{
    contador=0;
    ultimo=NULL;
    primero=NULL;
    //ctor
}

template <class T>
void ListaEnlazadaTipo<T>::destruirLista()
{
    NodoTipo<T> *temp;
    while(this->primero!=NULL)
    {
        temp=primero;
        primero=primero->siguiente;
        delete temp;
    }
    ultimo=NULL;
    contador=0;
}

template <class T>
void ListaEnlazadaTipo<T>::inicializarLista()
{
    destruirLista();
}//end inicializarLista

template <class T>
void ListaEnlazadaTipo<T>::imprimir() const
{
    NodoTipo<T> * actual;
    actual=primero;
    while(actual!=NULL)
    {
        std::cout<<actual->dato<<" ";
        actual=actual->siguiente;
    }
}//fin Imprimir

template <class T>
int ListaEnlazadaTipo<T>::longitud() const
{
    return this.contador;
}//end longitud

template <class T>
T ListaEnlazadaTipo<T>::cabeza() const
{
    assert(this.primero!=NULL);
    return this.primero->dato;
}//end cabeza

template <class T>
T ListaEnlazadaTipo<T>::cola() const
{
    assert(this.primero!=NULL);
    return this.ultimo->dato;
}//end cola

template <class T>
IteradorLista<T> ListaEnlazadaTipo<T>::inicio()
{
    IteradorLista<T> temp(primero);
    return temp;
}

template <class T>
IteradorLista<T> ListaEnlazadaTipo<T>::fin()
{
    IteradorLista<T> temp(NULL);
    return temp;
}

template <class T>
void ListaEnlazadaTipo<T>::copiarLista(const ListaEnlazadaTipo<T>& otra)
{
    NodoTipo<T> *nuevoNodo;
    NodoTipo<T> *actual;
    if(primero!=NULL)
    {
        destruirLista();
    }
    if(otra.primero==NULL)
    {
        primero=NULL;
        ultimo=NULL;
        contador=0;
    }
    else
    {
        actual=otra.primero;
        contador=otra.contador;

        primero=new NodoTipo<T>(actual->dato,NULL);
        ultimo=primero;
        actual=actual->siguiente;

        while(actual!=NULL)
        {
            nuevoNodo=new NodoTipo<T>(actual->dato,NULL);
            ultimo->siguiente=nuevoNodo;
            ultimo=nuevoNodo;

            actual=actual->siguiente;
        }//end while
    }//end else
}//end copiarLista

template <class T>
ListaEnlazadaTipo<T>::~ListaEnlazadaTipo()
{
    destruirLista();
    //dtor
}

template <class T>
ListaEnlazadaTipo<T>::ListaEnlazadaTipo(const ListaEnlazadaTipo<T>& otra)
{
    primero=NULL;
    copiarLista(otra);
}//end copy constructor

template <class T>
const ListaEnlazadaTipo<T>& ListaEnlazadaTipo<T>::operator=(const ListaEnlazadaTipo<T>& otra)
{
    if(this!=&otra)
    {
        copiarLista(otra);
    }

    return *this;
}


#endif // LISTAENLAZADATIPO_H
