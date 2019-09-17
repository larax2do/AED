#ifndef LISTADESORDENADA_H
#define LISTADESORDENADA_H
#include "ListaEnlazadaTipo.h"

template <class T>
class ListaDesordenada: public ListaEnlazadaTipo<T>
{
    public:
        bool buscar(const T& item)const;
        void insertarDelante(const T& nuevo);
        void insertarDetras(const T& nuevo);
        void eliminarNodo(const T& item);

    protected:

    private:
};


template <class T>
bool ListaDesordenada<T>::buscar(const T& item)const
{
    NodoTipo<T> *actual;
    bool busqueda=false;

    actual=this->primero;

    while(actual!=NULL && !busqueda)
    {
        if(actual->dato==item)
        {
            busqueda=true;
        }
        else
        {
            actual=actual->siguiente;
        }
    }
    return busqueda;
}//end buscar

template <class T>
void ListaDesordenada<T>::insertarDelante(const T& nuevo)
{
    NodoTipo<T> *nuevoNodo;

    nuevoNodo=new NodoTipo<T>;
    nuevoNodo->dato=nuevo;
    nuevoNodo->siguiente=this->primero;
    this->primero=nuevoNodo;
    this->contador++;
    if(this->ultimo==NULL)
        this->ultimo=nuevoNodo;
}//end insertar delante

template <class T>
void ListaDesordenada<T>::insertarDetras(const T& nuevo)
{
    NodoTipo<T> *nuevoNodo=new NodoTipo<T>;
    nuevoNodo->dato=nuevo;
    nuevoNodo->siguiente=NULL;

    if(this->primero==NULL)
    {
        this->primero=nuevoNodo;
        this->ultimo=nuevoNodo;
        this->contador++;
    }
    else
    {
        this->ultimo->siguiente=nuevoNodo;
        this->ultimo=nuevoNodo;
        this->contador++;
    }
}//end insertar ultimo

template <class T>
void ListaDesordenada<T>::eliminarNodo(const T& item)
{
    NodoTipo<T> *actual;
    NodoTipo<T> *anteriorActual;
    bool busqueda;

    if(this->primero==NULL)
    {
        std::cout<<"La lista esta vacia"<<std::endl;
    }
    else
    {
        if(this->primero->dato==item)
        {
            actual=this->primero;
            this->primero=this->primero->siguiente;
            this->contador--;
            if(this->primero==NULL)
            {
                this->ultimo=NULL;
            }
            delete actual;
        }
        else
        {
            busqueda=false;
            anteriorActual=this->primero;
            actual=this->primero->siguiente;
            while(actual!=NULL && !busqueda)
            {
                if(actual->dato!=item)
                {
                    anteriorActual=actual;
                    actual=actual->siguiente;
                }
                else
                {
                    busqueda=true;
                }
            }//end while
            if(busqueda)
            {
                anteriorActual->siguiente=actual->siguiente;
                this->contador--;
                if(this->ultimo==actual)
                {
                    this->ultimo=anteriorActual;
                }
                delete actual;
            }
            else
            {
                std::cout<<"No se encontro el item en la lista"<<std::endl;
            }
        }//end else
    }//end else
}//end eliminar nodo


#endif // LISTADESORDENADA_H
