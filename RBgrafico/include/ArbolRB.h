#ifndef ARBOLRB_H_INCLUDED
#define ARBOLRB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
enum{RED, BLACK};

template <typename Comparable>
struct NodoRB
{
    Comparable dato;
    NodoRB *izquierda;
    NodoRB *derecha;
    NodoRB *p;
    int color;
};

template <typename Comparable>
struct ArbolRB
{
    NodoRB<Comparable>* raiz;
    NodoRB<Comparable>* NIL;
    ArbolRB()
    {
        NIL=new NodoRB<Comparable>;
        NIL->derecha=NIL;
        NIL->izquierda=NIL;
        NIL->p=NIL;
        NIL->color=BLACK;
        raiz=NIL;

    }
};

template <typename Comparable>
NodoRB<Comparable>* nuevo(ArbolRB<Comparable>* T, Comparable d)
{
    NodoRB<Comparable>* temp=new NodoRB<Comparable>;
    temp->dato=d;
    temp->derecha=T->NIL;
    temp->izquierda=T->NIL;
    temp->p=T->NIL;
    return temp;
}




#endif // ARBOLRB_H_INCLUDED
