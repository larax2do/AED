#ifndef LISTAENLAZADAITERADOR_H
#define LISTAENLAZADAITERADOR_H
//#include <cstddef>
#include "NodoTipo.h"

template <class T>
class IteradorLista
{
    public:
        IteradorLista();
        IteradorLista(NodoTipo<T> *ptr);
        T operator*();
        IteradorLista<T> operator++();
        bool operator==(const IteradorLista<T>& derecha)const;
        bool operator!=(const IteradorLista<T>& derecha)const;

    protected:

    private:
        NodoTipo<T> *actual;
};

template <class T>
IteradorLista<T>::IteradorLista()
{
    actual=NULL;
    //ctor
}

template <class T>
IteradorLista<T>::IteradorLista(NodoTipo<T> *ptr)
{
    actual=ptr;
}

template <class T>
T IteradorLista<T>::operator*()
{
    return actual->dato;
}

template <class T>
IteradorLista<T> IteradorLista<T>::operator++()
{
    actual=actual->siguiente;
    return *this;
}

template <class T>
bool IteradorLista<T>::operator==(const IteradorLista<T>& derecha)const
{
    return (actual==derecha.actual);
}

template <class T>
bool IteradorLista<T>::operator!=(const IteradorLista<T>& derecha)const
{
    return (actual!=derecha.actual);
}


#endif // LISTAENLAZADAITERADOR_H
