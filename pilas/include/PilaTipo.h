#ifndef PILATIPO_H
#define PILATIPO_H
#include "PilaADT.h"
#include <iostream>
#include <cassert>

template <class T>
class PilaTipo:public PilaADT<T>
{
	public:
		const PilaTipo<T>& operator=(const PilaTipo<T>&);

		void inicializarPila();

		bool estaVacia() const;

		bool estaLLena() const;

		void apilar(const T& item);

		T cima()const;

		void desapilar();


		PilaTipo(int capacidad=100);
		PilaTipo(const PilaTipo<T>& otro);
		~PilaTipo();

	protected:

	private:
		int capacidadMax;
		int cimaPila;
		T *lista;

		void copiarPila(const PilaTipo<T>& otro);
};



template <class T>
void PilaTipo<T>::inicializarPila()
{
	cimaPila=0;
}//end inicializarPila

template <class T>
bool PilaTipo<T>::estaVacia()const
{
	return (cimaPila==0);
}//end estaVacia;

template <class T>
bool PilaTipo<T>::estaLLena()const
{
	return (cimaPila==capacidadMax);
}//end EstaLLena

template <class T>
void PilaTipo<T>::apilar(const T& item)
{
	if(!estaLLena())
	{
		lista[cimaPila]=item;
		cimaPila++;
	}
	else
	{
		std::cout<<"La pila esta llena..."<<std::endl;
	}
}//end apilar

template <class T>
T PilaTipo<T>::cima() const
{
	assert(cimaPila!=0);
	return lista[cimaPila-1];
}//end cima

template <class T>
void PilaTipo<T>::desapilar()
{
	if(!estaVacia())
	{
		cimaPila--;
	}
	else
		std::cout<<"La pila esta vacia..."<<std::endl;
}//end desapilar

template <class T>
void PilaTipo<T>::copiarPila(const PilaTipo<T>& otro)
{
	delete [] lista;
	capacidadMax=otro.capacidadMax;
	cimaPila=otro.cimaPila;
	lista=new T[capacidadMax];

	for(int i=0;i<cimaPila;i++)
	{
		lista[i]=otro.lista[i];
	}
}//end copiarLista


template <class T>
PilaTipo<T>::PilaTipo(int capacidad)
{
	if(capacidad<=0)
	{
		std::cout<<"La capacidad debe ser positiva..."<<std::endl;
		std::cout<<"Secreara por defecto con capacidad de 100"<<std::endl;
		capacidadMax=100;
	}
	else
	{
		capacidadMax=capacidad;
	}
	cimaPila=0;
	lista=new T[capacidadMax];
	//ctor
}//end constructor

template <class T>
PilaTipo<T>::~PilaTipo()
{
	delete [] lista;
	//dtor
}//end destructor

template <class T>
PilaTipo<T>::PilaTipo(const PilaTipo<T>& otro)
{
	lista=NULL;
	copiarPila(otro);
}//end constructorCopia

template <class T>
const PilaTipo<T>& PilaTipo<T>::operator=(const PilaTipo<T>& otro)
{
	if(this!=&otro)
	{
		copiarPila(otro);
	}
	return *this;
}//end operator=

#endif // PILATIPO_H
