#ifndef PILAADT_H
#define PILAADT_H

template <class T>
class PilaADT
{
	public:
		virtual void inicializarPila()=0;
			//Inicializa la Pila vacia
			//Postcondition: La pila esta vacia
		virtual bool estaVacia()const=0;
			//determina si la pila esta vacia
			//Postcondition:Retorna TRUE si esta vacia
			//y FALSE en los demas casos
		virtual bool estaLLena()const=0;
			//Determina si la pila esta llena
			//Postcondition: Retorna TRUE si la pila esta llena
			//en los demas casos FALSE
		virtual void apilar(const T& item)=0;
			//Agrega el nuevo elemento a la pila
			//Precondition: debe existir la pila y no debe estar llena
			//Postcondition: Se agrega "item" a la cima de la pila
		virtual T cima() const=0;
			//Retorna el elemento de la cima de la pila
			//Precondition: Debe existir la pila y no debe estar llena
			//Postcondition: Si la pila esta vacia el programa termina
			//en los demas casos, se retorna el contenido del elemento
			// de la cima
		virtual void desapilar()=0;
			//Remueve el elemento de la cima
			//Precondition: Debe existir la pila y no debe estar llena
			//Postcondition: Se remueve el elemento de la cima

	protected:

	private:
};

#endif // PILAADT_H
