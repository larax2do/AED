#ifndef ARBOLBINBUS_H
#define ARBOLBINBUS_H
#include <iostream>
#include <ostream>


template <typename Comparable>
class ArbolBinBus
{
    public:
        ArbolBinBus();//constructor por defecto
        ArbolBinBus(const ArbolBinBus& rhs);//constructor copia para lvalues
        ArbolBinBus(ArbolBinBus && rhs);//constructor move para rvalues
        ~ArbolBinBus();//destructor

        const Comparable& buscarMinimo()const;
        const Comparable& buscarMaximo()const;
        bool contiene(const Comparable& x)const;
        bool estaVacio()const;
        void mostrarArbol(std::ostream& salida=std::cout)const;

        void prepararVacio();
        void insertar(const Comparable& x);
        void insertar(Comparable&& x);
        void remover(const Comparable& x);


        ArbolBinBus& operator=(const ArbolBinBus& rhs);
        ArbolBinBus& operator=(ArbolBinBus&& rhs);

    protected:

    private:

        struct NodoBinario
        {
            Comparable dato;
            NodoBinario *izquierda;
            NodoBinario *derecha;

            NodoBinario(const Comparable& elemento, NodoBinario* subIzquierdo, NodoBinario* subDerecho)
            {
                dato=elemento;
                izquierda=subIzquierdo;
                derecha=subDerecho;
            }
            NodoBinario(Comparable&& elemento, NodoBinario* subIzquierdo, NodoBinario* subDerecho)
            {
                dato=std::move(elemento);
                izquierda=subIzquierdo;
                derecha=subDerecho;
            }

        };

        NodoBinario* raiz;

        void insertar(const Comparable& x, NodoBinario*& t);
        void insertar(Comparable&& x, NodoBinario*& t);
        void remover(const Comparable& x, NodoBinario*& t);

        NodoBinario* buscarMinimo(NodoBinario* t) const;
        NodoBinario* buscarMaximo(NodoBinario* t)const;

        bool contiene(const Comparable& x,NodoBinario* t)const;
        void prepararVacio(NodoBinario*& t);
        void mostrarArbol(NodoBinario* t, std::ostream& salida)const;
        NodoBinario* clonar(NodoBinario* t)const;
};



#endif // ARBOLBINBUS_H
