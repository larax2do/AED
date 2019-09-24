#ifndef LISTACOLATIPO_H
#define LISTACOLATIPO_H
#include <iostream>
#include <cassert>
#include "ColaADT.h"

template <class T>
struct NodoTipo
{
    T dato;
    NodoTipo<T>* siguiente;
};


template <class T>
class ListaColaTipo: public ColaADT<T>
{
    public:

        const ListaColaTipo<T>& operator=(const ListaColaTipo<T>& otra);
        bool estaVacia() const;
        bool estaLLena() const;
        void inicializarCola();
        T cabeza() const;
        T cola() const;
        void agregar(const T& item);
        void eliminar();
        void mostrar()const;

        ListaColaTipo();
        ListaColaTipo(const ListaColaTipo<T>& otra);
        ~ListaColaTipo();

    protected:

    private:
        NodoTipo<T>* delante;
        NodoTipo<T>* detras;
        void copiarCola(const ListaColaTipo<T>& otra);
};


template <class T>
bool ListaColaTipo<T>::estaVacia()const
{
    return (delante==NULL);
}//end estaVacia

template <class T>
bool ListaColaTipo<T>::estaLLena()const
{
    return false;
}//end estaLLena

template <class T>
void ListaColaTipo<T>::inicializarCola()
{
    NodoTipo<T>* temp;
    while(delante!=NULL)
    {
        temp=delante;
        delante=delante->siguiente;
        delete temp;
    }
    detras=NULL;
}//end inicializarCola

template <class T>
void ListaColaTipo<T>::agregar(const T& item)
{
    NodoTipo<T>* nuevo;
    nuevo=new NodoTipo<T>;
    nuevo->dato=item;
    nuevo->siguiente=NULL;

    if(delante==NULL)
    {
        delante=nuevo;
        detras=nuevo;
    }
    else
    {
        detras->siguiente=nuevo;
        detras=nuevo;
    }
}//end agregar

template <class T>
T ListaColaTipo<T>::cabeza()const
{
    assert(delante!=NULL);
    return delante->dato;
}//end cabeza

template <class T>
T ListaColaTipo<T>::cola()const
{
    assert(detras!=NULL);
    return detras->dato;
}//end cola

template <class T>
void ListaColaTipo<T>::eliminar()
{
    NodoTipo<T>* temp;
    if(!estaVacia())
    {
        temp=delante;
        delante=delante->siguiente;
        delete temp;
        if(delante==NULL)
        {
            detras=NULL;
        }
    }
    else
    {
        std::cout<<"La cola esta vacia"<<std::endl;
    }
}//end eliminar

template <class T>
ListaColaTipo<T>::ListaColaTipo()
{
    delante=NULL;
    detras=NULL;
    //ctor
}

template <class T>
ListaColaTipo<T>::~ListaColaTipo()
{
    inicializarCola();
    //dtor
}

template <class T>
void ListaColaTipo<T>::copiarCola(const ListaColaTipo<T>& otra)
{
    NodoTipo<T>* nuevo;
    NodoTipo<T>* actual;


    if(delante!=NULL)
    {
        inicializarCola();
    }
    if(otra.delante==NULL)
    {
        delante=NULL;
        detras=NULL;
    }
    else
    {
        actual=otra.delante;
        delante=new NodoTipo<T>;
        delante->dato=actual->dato;
        delante->siguiente=NULL;
        detras=delante;
        actual=actual->siguiente;

        while(actual!=NULL)
        {
            nuevo=new NodoTipo<T>;

            nuevo->dato=actual->dato;
            nuevo->siguiente=NULL;
            detras->siguiente=nuevo;
            detras=nuevo;
            actual=actual->siguiente;
        }//end while
    }//end else
}//end copiar


template <class T>
void ListaColaTipo<T>::mostrar()const
{
    NodoTipo<T>* actual;
    actual=delante;
    while(actual!=NULL)
    {
        std::cout<<actual->dato<<" ";
        actual=actual->siguiente;
    }
    std::cout<<"fin"<<std::endl;
}

template <class T>
ListaColaTipo<T>::ListaColaTipo(const ListaColaTipo<T>& otra)
{
    delante=NULL;
    detras=NULL;
    copiarCola(otra);
    //copy ctor
}

template <class T>
const ListaColaTipo<T>& ListaColaTipo<T>::operator=(const ListaColaTipo<T>& otra)
{
    if (this != &otra)
        copiarCola(otra);

    return *this;
}//end operator=


#endif // LISTACOLATIPO_H
