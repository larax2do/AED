#include "ColaTipo.h"

template <class T>
bool ColaTipo<T>::estaVacia() const
{
	return (contador==0);
}//end estaVacia

template <class T>
bool ColaTipo<T>::estaLLena() const
{
	return (contador==capacidadMaxima);
}//end estaLLena

template <class T>
void ColaTipo<T>::inicializarCola()
{
	delante=0;
	atras=capacidadMaxima-1;
	contador=0;
}//end InicializarCola

template <class T>
T ColaTipo<T>::cabeza() const
{
	assert(!estaVacia());
	return lista[delante];
}//end cabeza

template <class T>
T ColaTipo<T>::cola() const
{
	assert(!estaVacia());
	return lista[atras];
}//end cola

template <class T>
void ColaTipo<T>::agregar(const T& item)
{
	if(!estaLLena())
	{
		atras=(atras+1)%capacidadMaxima;
		contador++;
		lista[atras=item];
	}
	else
	{
		std::cout<<"La cola esta llena...."<<std::endl;
	}
}//end agragar

template <class T>
void ColaTipo<T>::eliminar()
{
	if(!estaVacia())
	{
		contador--;
		delante=(delante+1)%capacidadMaxima;
	}
	else
	{
		std::cout<<"la pila esta vacia..."<<std::endl;
	}
}//end eliminar

template <class T>
ColaTipo<T>::ColaTipo(int capacidad)
{
	if(capacidad<=0)
	{
		std::cout<<"La capacidad no puede ser menor a 0..."<<std::endl;
		std::cout<<"Se usara capacidad=100 por defecto"<<std::endl;
		capacidadMaxima=100;
	}
	else
	{
		capacidadMaxima=capacidad;
	}
	delante=0;
	atras=capacidadMaxima-1;
	contador=0;
	lista=new T[capacidadMaxima];
	//ctor
}//end constructor

template <class T>
ColaTipo<T>::~ColaTipo()
{
	delete [] lista;
	//dtor
}

template <class T>
ColaTipo<T>::ColaTipo(const ColaTipo& other)
{
	//copy ctor
}

template <class T>
const ColaTipo<T>& ColaTipo<T>::operator=(const ColaTipo<T>& rhs)
{
	if (this == &rhs) return *this; // handle self assignment
	//assignment operator
	return *this;
}
