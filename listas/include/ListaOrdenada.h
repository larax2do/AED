#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H
#include <iostream>
#include "ListaEnlazadaTipo.h"

template <class T>
class ListaOrdenada: public ListaEnlazadaTipo<T>
{
    public:
        bool buscar(const T& item) const;
        void insertar(const T& item);
        void insertarDelante(const T& item);
        void insertarDetras(const T& item);
        void eliminarNodo(const T& item);

    protected:

    private:
};

template <class T>
bool ListaOrdenada<T>::buscar(const T& item) const
{
    bool busqueda=false;
    NodoTipo<T> *actual;
    actual=this->primero;

    while(actual!=NULL && !busqueda)
    {
        if(actual->dato>=item)
        {
            busqueda=true;
        }
        else
        {
            actual=actual->siguiente;
        }
    }
    if(busqueda)
    {
        busqueda=(actual->dato==item);
    }
    return busqueda;
}//end buscar

template <class T>
void ListaOrdenada<T>::insertar(const T& item)
{
    NodoTipo<T> *actual;
    NodoTipo<T> *actualAnterior;
    NodoTipo<T> *nuevo;

    bool busqueda;

    nuevo=new NodoTipo<T>;
    nuevo->dato=item;
    nuevo->siguiente=NULL;

    if(this->primero==NULL)
    {
        this->primero=nuevo;
        this->ultimo=nuevo;
        this->contador++;
    }
    else
    {
        actual=this->primero;
        busqueda=false;

        while(actual!=NULL && !busqueda)
        {
            if(actual->dato>=item)
            {
                busqueda=true;
            }
            else
            {
                actualAnterior=actual;
                actual=actual->siguiente;
            }
        }//end while
        if(actual==this->primero)
        {
            nuevo->siguiente=this->primero;
            this->primero=nuevo;
            this->contador++;
        }
        else
        {
            actualAnterior->siguiente=nuevo;
            nuevo->siguiente=actual;
            if(actual==NULL)
            {
                this->ultimo=nuevo;
            }
            this->contador++;
        }
    }//end else
}//end insert

template <class T>
void ListaOrdenada<T>::insertarDelante(const T& item)
{
    insertar(item);
}//end insertar primero

template <class T>
void ListaOrdenada<T>::insertarDetras(const T& item)
{
    insertar(item);
}//end insertar ultimo

template <class T>
void ListaOrdenada<T>::eliminarNodo(const T& item)
{
    NodoTipo<T> *actual;
    NodoTipo<T> *actualAnterior;
    bool busqueda;

    if(this->primero==NULL)
    {
        std::cout<<"La lista esta vacia pss"<<std::endl;
    }
    else
    {
        actual=this->primero;
        busqueda=false;

        while(actual!=NULL && !busqueda)
        {
            if(actual->dato >= item)
            {
                busqueda=true;
            }
            else
            {
                actualAnterior=actual;
                actual=actual->siguiente;
            }
        }//end while
        if(actual==NULL)
        {
            std::cout<<"El elemento no se encontro"<<std::endl;
        }
        else
        {
            if(actual->dato==item)
            {
                if(this->primero==actual)
                {
                    this->primero=this->primero->siguiente;
                    if(this->primero==NULL)
                    {
                        this->ultimo=NULL;
                    }
                    delete actual;
                }
                else
                {
                    actualAnterior->siguiente=actual->siguiente;
                    if(actual==this->ultimo)
                    {
                        this->ultimo=actualAnterior;
                    }
                    delete actual;
                }
                this->contador--;
            }
            else
            {
                std::cout<<"El item no se encontro"<<std::endl;
            }
        }//end else
    }//end else
}//end eliminar

#endif // LISTAORDENADA_H
