#ifndef COLAADT_H
#define COLAADT_H


template <class T>
class ColaADT
{
	public:
		virtual bool estaVacia() const =0;
		virtual bool estaLLena() const =0;
		virtual void inicializarCola()=0;
		virtual T cabeza() const=0;
		virtual T cola() const=0;
		virtual void agregar(const T& item)=0;
		virtual void eliminar()=0;

	protected:

	private:
};

#endif // COLAADT_H
