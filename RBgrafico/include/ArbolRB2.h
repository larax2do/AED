#ifndef ARBOLRB2_H
#define ARBOLRB2_H
#include <fstream>
#include <string>

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
class ArbolRB2
{
public:
    ArbolRB2()
    {
        NIL=new NodoRB<Comparable>;
        NIL->derecha=NIL;
        NIL->izquierda=NIL;
        NIL->p=NIL;
        NIL->color=BLACK;
        raiz=NIL;
    }

    void mostrar() const
    {
        std::fstream archivo;
        archivo.open("arbol.dot",std::fstream::out);
        archivo<<"digraph G{"<<std::endl;
        archivo<<"\tgraph [ordering=\"out\"];"<<std::endl;
        if( estaVacio( ) )
            archivo << "Empty tree" << std::endl;
        else
        {
            mostrar(raiz,archivo);
        }
        archivo<<"}";
        archivo.close();
        system("dot -Tsvg arbol.dot -o ARBOL.png");
    }

    void insertar (Comparable item)
    {
        insertar(nuevo(item));
    }

    void borrar (Comparable item)
    {
        eliminar(nuevo(item));
    }

protected:

private:

    NodoRB<Comparable>* raiz;
    NodoRB<Comparable>* NIL;

    NodoRB<Comparable>* nuevo(Comparable d)
    {
        NodoRB<Comparable>* temp=new NodoRB<Comparable>;
        temp->dato=d;
        temp->derecha=NIL;
        temp->izquierda=NIL;
        temp->p=NIL;
        return temp;
    }

    NodoRB<Comparable>* buscar(NodoRB<Comparable>* x,Comparable d)
    {
        if(x==NIL || d=x.dato)
        {
            return x;
        }
        if(d<x.dato)
        {
            return buscar(x.izquierda,d);
        }
        else
        {
            return buscar(x.derecha,d);
        }
    }

    NodoRB<Comparable>* minimo(NodoRB<Comparable>* x)
    {
        while (x->izquierda!=NIL)
        {
            x=x->izquierda;
        }
        return x;
    }

    NodoRB<Comparable>* maximo(NodoRB<Comparable>* x)
    {
        while (x->derecha!=NIL)
        {
            x=x->derecha;
        }
        return x;
    }

    NodoRB<Comparable>* sucesor(NodoRB<Comparable>* x)
    {
        if(x->derecha!=NIL)
        {
            return minimo(x->derecha);
        }
        NodoRB<Comparable>* y;
        y=x->p;
        while(y!=NIL && x==y->derecha)
        {
            x=y;
            y=y->p;
        }
        return y;
    }

    NodoRB<Comparable>* predecesor(NodoRB<Comparable>* x)
    {
        if(x->izquierda!=NIL)
        {
            return minimo(x->izquierda);
        }
        NodoRB<Comparable>* y;
        y=x->p;
        while(y!=NIL && x==y->izquierda)
        {
            x=y;
            y=y->p;
        }
        return y;
    }

    void izqRotacion(NodoRB<Comparable>* x)
    {
        NodoRB<Comparable>* y;
        y=x->derecha;
        x->derecha=y->izquierda;//betha
        if(y->izquierda!=NIL)
            y->izquierda->p=x;
        y->p=x->p;
        if(x->p==NIL)
            raiz=y;
        else if(x==x->p->izquierda)
            x->p->izquierda=y;
        else
            x->p->derecha=y;
        y->izquierda=x;
        x->p=y;
    }

    void derRotacion(NodoRB<Comparable>* x)
    {
        NodoRB<Comparable>* y;
        y=x->izquierda;
        x->izquierda=y->derecha;
        if(y->derecha!=NIL)
            y->derecha->p=x;
        y->p=x->p;
        if(x->p==NIL)
            raiz=y;
        else if(x==x->p->izquierda)
            x->p->izquierda=y;
        else
            x->p->derecha=y;
        y->derecha=x;
        x->p=y;
    }



    void insertar(NodoRB<Comparable>* z)
    {
        NodoRB<Comparable>* y;
        NodoRB<Comparable>* x;

        y=NIL;
        x=raiz;
        while (x!=NIL)
        {
            y=x;
            if(z->dato<x->dato)
                x=x->izquierda;
            else
                x=x->derecha;
        }
        z->p=y;
        if(y==NIL)
            raiz=z;
        else if(z->dato<y->dato)
            y->izquierda=z;
        else
            y->derecha=z;
        z->derecha=NIL;
        z->izquierda=NIL;
        z->color=RED;
        arreglarIn(z);
    }

    void arreglarIn(NodoRB<Comparable>* z)
    {
        NodoRB<Comparable>* y;
        //NodoRB<Comparable>* x;
        while (z->p->color==RED)
        {
            if(z->p==z->p->p->izquierda)
            {
                y=z->p->p->derecha;
                if(y->color==RED)
                {
                    z->p->color=BLACK;
                    y->color=BLACK;
                    z->p->p->color=RED;
                    z=z->p->p;
                }
                else
                {
                    if(z==z->p->derecha)
                    {
                        z=z->p;
                        izqRotacion(z);
                    }
                    z->p->color=BLACK;
                    z->p->p->color=RED;
                    derRotacion(z->p->p);
                }

            }
            else
            {
                y=z->p->p->izquierda;
                if(y->color==RED)
                {
                    z->p->color=BLACK;
                    y->color=BLACK;
                    z->p->p->color=RED;
                    z=z->p->p;
                }
                else
                {
                    if(z==z->p->izquierda)
                    {
                        z=z->p;
                        derRotacion(z);
                    }
                    z->p->color=BLACK;
                    z->p->p->color=RED;
                    izqRotacion(z->p->p);
                }
            }
        }

        raiz->color=BLACK;

    }

    void transplante(NodoRB<Comparable>* u, NodoRB<Comparable>* v)
    {
        if(u->p==NIL)
            raiz=v;
        else if(u==u->p->izquierda)
            u->p->izquierda=v;
        else
            u->p->derecha=v;
        v->p=u->p;
    }

    void eliminar(NodoRB<Comparable>* z)
    {
        NodoRB<Comparable>* y;
        NodoRB<Comparable>* x;

        y=z;
        int colorY=y->color;
        if(z->izquierda==NIL)
        {
            x=z->derecha;
            transplante(z,z->derecha);
        }
        else if(z->derecha==NIL)
        {
            x=z->izquierda;
            transplante(z,z->izquierda);
        }
        else
        {
            y=minimo(z->derecha);
            colorY=y->color;
            x=y->derecha;
            if(y->p==z)
            {
                x->p=y;
            }
            else
            {
                transplante(y,y->derecha);
                y->derecha=z->derecha;
                y->derecha->p=y;
            }
            transplante(z,y);
            y->izquierda=z->izquierda;
            y->izquierda->p=y;
            y->color=z->color;
        }
        if(colorY==BLACK)
        {
            arreglarDel(x);
        }
    }
    void arreglarDel(NodoRB<Comparable>* x)
    {
        NodoRB<Comparable>* w;
        while (x!=raiz && x->color==BLACK)
        {
            if (x==x->p->izquierda)
            {
                w=x->p->derecha;
                if(w->color==RED)
                {
                    w->color=BLACK;
                    x->p->color=RED;
                    izqRotacion(x->p);
                    w=x->p->derecha;
                }
                if(w->izquierda->color==BLACK && w->derecha->color==BLACK)
                {
                    w->color=RED;
                    x=x->p;
                }
                else
                {
                    if(w->derecha->color==BLACK)
                    {
                        w->izquierda->color=BLACK;
                        w->color=RED;
                        derRotacion(w);
                        w=x->p->derecha;
                    }
                    w->color=x->p->color;
                    x->p->color=BLACK;
                    w->derecha->color=BLACK;
                    izqRotacion(x->p);
                    x=raiz;
                }
            }
            else
            {
                w=x->p->izquierda;
                if(w->color==RED)
                {
                    w->color=BLACK;
                    x->p->color=RED;
                    izqRotacion(x->p);
                    w=x->p->izquierda;
                }
                if(w->derecha->color==BLACK && w->izquierda->color==BLACK)
                {
                    w->color=RED;
                    x=x->p;
                }
                else
                {
                    if(w->izquierda->color==BLACK)
                    {
                        w->derecha->color=BLACK;
                        w->color=RED;
                        izqRotacion(w);
                        w=x->p->izquierda;
                    }
                    w->color=x->p->color;
                    x->p->color=BLACK;
                    w->izquierda->color=BLACK;
                    derRotacion(x->p);
                    x=raiz;
                }//end else
            }//end else
        }//end while
        x->color=BLACK;
    }//end function


    bool estaVacio()const
    {
        return raiz==nullptr;
    }


    void mostrar(NodoRB<Comparable> *t,std::fstream& archivo) const
    {
        if( t != NIL )
        {
            if(t->color==RED)
            {
                archivo<<t->dato<<"[style=filled, fillcolor=red];"<<std::endl;
            }
            else
            {
                archivo<<t->dato<<"[style=filled, fillcolor=grey26];"<<std::endl;
            }

            if(t->izquierda!=NIL)
            {
                archivo<<"\t"<< t->dato<<"->"<<t->izquierda->dato<<";"<<std::endl;
            }
            if(t->derecha!=NIL)
            {
                archivo<<"\t"<< t->dato<<"->"<<t->derecha->dato<<";"<<std::endl;
            }

            mostrar(t->izquierda,archivo);

            mostrar(t->derecha,archivo);
        }
    }

};

#endif // ARBOLRB2_H
