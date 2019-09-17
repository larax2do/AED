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

#endif // PILATIPO_H
