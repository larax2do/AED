#ifndef LISTAPILATIPO_H
#define LISTAPILATIPO_H
#include <iostream>
#include <cassert>
#include "PilaADT.h"

template <class T>
struct NodoTipo
{
	T dato;
	NodoTipo<T>* siguiente;
};

template <class T>
class ListaPilaTipo: public PilaADT<T>
{
	public:
		const ListaPilaTipo<T>& operator=(const ListaPilaTipo<T>& otra);
		bool estaVacia()const;
		bool estaLLena()const;
		void inicializarPila();
		void apilar(const T& item);
		T cima() const;
		void desapilar();

		ListaPilaTipo();
		ListaPilaTipo(const ListaPilaTipo<T>& otra);
		~ListaPilaTipo();

	protected:

	private:
		NodoTipo<T>* cimaPila;
		void copiarPila(const ListaPilaTipo<T>& otra);
};

#endif // LISTAPILATIPO_H
