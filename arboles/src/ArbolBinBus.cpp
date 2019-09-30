#include "ArbolBinBus.h"

template <typename Comparable>
bool ArbolBinBus<Comparable>::contiene(const Comparable& x)const
{
    return contiene(x,raiz);
}

template <typename Comparable>
void ArbolBinBus<Comparable>::insertar(const Comparable& x)
{
    insertar(x,raiz);
}

template <typename Comparable>
void ArbolBinBus<Comparable>::remover(const Comparable& x)
{
    remover(x,raiz);
}

template <typename Comparable>
bool ArbolBinBus<Comparable>::contiene(const Comparable& x,NodoBinario* t) const
{
    if(t==nullptr)
    {
        return false;
    }
    else if(x < t->dato)
    {
        return contiene(x,t->izquierda);
    }
    else if(x > t->dato)
    {
        return contiene(x,t->derecha);
    }
    else
    {
        return true;
    }
}
/*
ArbolBinBus::ArbolBinBus()
{
    //ctor
}

ArbolBinBus::~ArbolBinBus()
{
    //dtor
}

ArbolBinBus::ArbolBinBus(const ArbolBinBus& other)
{
    //copy ctor
}

ArbolBinBus& ArbolBinBus::operator=(const ArbolBinBus& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
*/
