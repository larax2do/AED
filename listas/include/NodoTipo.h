#ifndef NODOTIPO_H
#define NODOTIPO_H

template <typename T>
struct NodoTipo
{
    T dato;
    NodoTipo<T>* siguiente;
};


#endif // NODOTIPO_H
