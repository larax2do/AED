#ifndef COLATIPO_H
#define COLATIPO_H
#include <iostream>
#include <cassert>
#include "ColaADT.h"

template <class T>
class ColaTipo: public ColaADT<T>
{
	public:
		const ColaTipo<T>& operator=(const ColaTipo<T>& otra);
		bool estaVacia() const;
		bool estaLLena() const;
		void inicializarCola();
		T cabeza() const;
		T cola() const;
		void agregar(const T& item);
		void eliminar();
		ColaTipo(int capacidad=100);
		~ColaTipo();
		ColaTipo(const ColaTipo<T>& otra);


	protected:

	private:
		int capacidadMaxima;
		int contador;
		int delante;
		int atras;
		T *lista;
};

#endif // COLATIPO_H
