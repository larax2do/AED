#include "ListaPilaTipo.h"

template <class T>
ListaPilaTipo<T>::ListaPilaTipo()
{
	cimaPila=NULL;
	//ctor
}

template <class T>
bool ListaPilaTipo<T>::estaVacia() const
{
	return(cimaPila==NULL);
}

template <class T>
bool ListaPilaTipo<T>::estaLLena() const
{
	return false;
}

template <class T>
void ListaPilaTipo<T>::inicializarPila()
{
	NodoTipo<T> *temporal;
	while(cimaPila!=NULL)
	{
		temporal = cimaPila;
		cimaPila=cimaPila->siguiente;
		delete temporal;
	}
}//end inicializarPila


template <class T>
void ListaPilaTipo<T>::apilar(const T& item)
{
	NodoTipo<T> *nuevo;
	nuevo=new NodoTipo<T>;

	nuevo->dato=item;
	nuevo->siguiente=cimaPila;
	cimaPila=nuevo;
}//end apilar

template <class T>
T ListaPilaTipo<T>::cima() const
{
	assert(cimaPila!=NULL);
	return cimaPila->dato;
}//end cima;

template <class T>
void ListaPilaTipo<T>::desapilar()
{
	NodoTipo<T>* temporal;
	if(cimaPila!=NULL)
	{
		temporal=cimaPila;
		cimaPila=cimaPila->siguiente;
		delete temporal;
	}
	else
	{
		std::cout<<"La pila esta vacia..."<<std::endl;
	}
}//end desapilar

template <class T>
void ListaPilaTipo<T>::copiarPila(const ListaPilaTipo<T>& otra)
{
	NodoTipo<T>* nuevo;
	NodoTipo<T>* actual;
	NodoTipo<T>* ultimo;

	if(cimaPila!=NULL)
	{
		inicializarPila();
	}
	if(otra.cimaPila==NULL)
	{
		cimaPila=NULL;
	}
	else
	{
		actual=otra.cimaPila;

		cimaPila=new NodoTipo<T>;
		cimaPila->dato=actual->dato;
		cimaPila->siguiente=NULL;
		ultimo=cimaPila;
		actual=actual->siguiente;

		while(actual!=NULL)
		{
			nuevo=new NodoTipo<T>;

			nuevo->dato=actual->dato;
			nuevo->siguiente=NULL;
			ultimo->siguiente=nuevo;
			ultimo=nuevo;
			actual=actual->siguiente;
		}//end while
	}//end else
}//end copiarLista

template <class T>
ListaPilaTipo<T>::~ListaPilaTipo()
{
	inicializarPila();
	//dtor
}

template <class T>
ListaPilaTipo<T>::ListaPilaTipo(const ListaPilaTipo<T>& otra)
{
	cimaPila=NULL;
	copiarPila(otra);
	//copy ctor
}//end constructor copia

template <class T>
const ListaPilaTipo<T>& ListaPilaTipo<T>::operator=(const ListaPilaTipo<T>& otra)
{
	if (this != &otra)
	{
		copiarPila(otra);
	}
	return *this; // handle self assignment
	//assignment operator
}//end operator=
