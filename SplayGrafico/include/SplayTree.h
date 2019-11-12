#ifndef SPLAYTREE_H
#define SPLAYTREE_H
#include <utility>
#include<fstream>

template <typename Comparable>
class SplayTree
{
    public:
        SplayTree()
        {
            nodoNULO=new NodoBinario;
            nodoNULO->izquierda=nodoNULO->derecha=nodoNULO;
            raiz=nodoNULO;
        }
        SplayTree(const SplayTree& rhs)
        {
            nodoNULO=new NodoBinario;
            nodoNULO->izquierda=nodoNULO->derecha=nodoNULO;
            raiz=clonar(rhs.raiz);
        }
        SplayTree(SplayTree&& rhs) : raiz{rhs.raiz},nodoNULO{rhs.nodoNULO}
        {
            rhs.raiz=nullptr;
            rhs.nodoNULL=nullptr;
        }

        ~SplayTree()
        {
            armarVacio();
            delete nodoNULO;
        }
        SplayTree& operator=(const SplayTree& rhs)
        {
            SplayTree copia=rhs;
            std::swap(*this,copia);
            return *this;
        }
        SplayTree& operator=(SplayTree&& rhs)
        {
            std::swap(raiz,rhs.raiz);
            std::swap(nodoNULO,rhs.nodoNULO);
            return *this;
        }
        const Comparable& buscarMin()
        {
            NodoBinario* ptr=raiz;
            while(ptr->izquierda!=nodoNULO)
            {
                ptr=ptr->izquierda;
            }
            splay(ptr->dato,raiz);
            return ptr->dato;
        }
        const Comparable& buscarMax()
        {
            NodoBinario* ptr=raiz;
            while(ptr->derecha!=nodoNULO)
            {
                ptr=ptr->derecha;
            }
            splay(ptr->dato,raiz);
            return ptr->dato;
        }
        bool contiene(const Comparable& x)
        {
            if(estaVacio())
                return false;
            splay(x,raiz);
            return raiz->dato==x;
        }
        bool estaVacio()const
        {
            return raiz==nodoNULO;
        }

        void mostrar()const
        {
            std::fstream archivo;
            archivo.open("arbol.dot",std::fstream::out);
            archivo<<"digraph G{"<<std::endl;
            archivo<<"\tgraph [ordering=\"out\"];"<<std::endl;
            if( estaVacio( ) )
                archivo << "Empty tree" << std::endl;
            else
            {
                int  contador=0;
                mostrar(raiz,archivo,contador);
            }
            archivo<<"}";
            archivo.close();
            system("dot -Tsvg arbol.dot -o ARBOL.png");
        }

        void armarVacio()
        {
            while(!estaVacio())
            {
                buscarMax();
                remover(raiz->dato);
            }
        }

        void insertar(const Comparable& x)
        {
            static NodoBinario *nuevo=nullptr;

            if(nuevo==nullptr)
            {
                nuevo=new NodoBinario;
            }
            nuevo->dato=x;

            if(raiz==nodoNULO)
            {
                nuevo->izquierda=nuevo->derecha=nodoNULO;
                raiz=nuevo;
            }
            else
            {
                splay(x,raiz);
                if(x<raiz->dato)
                {
                    nuevo->izquierda=raiz->izquierda;
                    nuevo->derecha=raiz;
                    raiz->izquierda=nodoNULO;
                    raiz=nuevo;
                }
                else if(raiz->dato<x)
                {
                    nuevo->derecha=raiz->derecha;
                    nuevo->izquierda=raiz;
                    raiz->derecha=nodoNULO;
                    raiz=nuevo;
                }
                else
                    return;

            }//end else
            nuevo=nullptr;
        }//end function
        void remover(const Comparable& x)
        {
            if(!contiene(x))
                return;
            NodoBinario *nuevoArbol;

            if(raiz->izquierda==nodoNULO)
                nuevoArbol=raiz->derecha;
            else
            {
                nuevoArbol=raiz->izquierda;
                splay(x,nuevoArbol);
                nuevoArbol->derecha=raiz->derecha;
            }
            delete raiz;
            raiz=nuevoArbol;
        }

    protected:

    private:

    struct NodoBinario
    {
        Comparable dato;
        NodoBinario* izquierda;
        NodoBinario* derecha;

        NodoBinario() : izquierda{nullptr},derecha{nullptr}{}
        NodoBinario(const Comparable & dat,NodoBinario* izq,NodoBinario* der)
            :dato{dat},izquierda{izq},derecha{der}{}

    };
    NodoBinario *raiz;
    NodoBinario *nodoNULO;

    void reclamarMemoria(NodoBinario* t)
    {
        if(t!=t->izquierda)
        {
            reclamarMemoria(t->izquierda);
            reclamarMemoria(t->derecha);
            delete t;
        }
    }
    void mostrar(NodoBinario *t,std::fstream& archivo,int &cont)const
    {
        if( t != nodoNULO )
        {
            archivo<<t->dato<<";"<<std::endl;
            if(t->izquierda!=nodoNULO)
            {
                archivo<<"\t"<< t->dato<<"->"<<t->izquierda->dato<<";"<<std::endl;
            }
            if(t->derecha!=nodoNULO)
            {
                archivo<<"\t"<< t->dato<<"->"<<t->derecha->dato<<";"<<std::endl;
            }

            if(t->izquierda==nodoNULO)
            {
                archivo<<"null"<<cont<<"[style=dashed][color=black][label=\"\"];"<<std::endl;
                archivo<<"\t"<< t->dato<<"->"<<"null"<<cont<<";"<<std::endl;
                cont++;
            }
            if(t->derecha==nodoNULO)
            {
                archivo<<"null"<<cont<<"[style=dashed][color=black][label=\"\"];"<<std::endl;
                archivo<<"\t"<< t->dato<<"->"<<"null"<<cont<<";"<<std::endl;
                cont++;
            }


            mostrar(t->izquierda,archivo,cont);

            mostrar(t->derecha,archivo,cont);
        }

    }

    NodoBinario* clonar(NodoBinario* t)const
    {
        if(t==t->izquierda)
            return nodoNULO;
        else
            return new NodoBinario{t->dato,clonar(t->izquierda),clonar(t->derecha)};
    }

    void izqRotacion(NodoBinario*& k2)
    {
        NodoBinario* k1=k2->izquierda;
        k2->izquierda=k1->derecha;
        k1->derecha=k2;
        k2=k1;
    }

    void derRotacion(NodoBinario*& k1)
    {
        NodoBinario*k2=k1->derecha;
        k1->derecha=k2->izquierda;
        k2->izquierda=k1;
        k1=k2;
    }
    void splay(const Comparable & x,NodoBinario*& t)
    {
        NodoBinario * izqArbolMax, * derArbolMin;
        static NodoBinario cabeza;

        cabeza.izquierda=cabeza.derecha=nodoNULO;
        izqArbolMax=derArbolMin=&cabeza;

        nodoNULO->dato=x;

        for(; ;)
        {
            if(x<t->dato)
            {
                if(x< t->izquierda->dato)
                    izqRotacion(t);
                if(t->izquierda==nodoNULO)
                    break;
                derArbolMin->izquierda=t;
                derArbolMin=t;
                t=t->izquierda;
            }
            else if(t->dato < x)
            {
                if(t->derecha->dato < x)
                {
                    derRotacion(t);
                }
                if(t->derecha==nodoNULO)
                    break;
                izqArbolMax->derecha=t;
                izqArbolMax=t;
                t=t->derecha;

            }
            else
                break;

        }//end for

        izqArbolMax->derecha=t->izquierda;
        derArbolMin->izquierda=t->derecha;
        t->izquierda=cabeza.derecha;
        t->derecha=cabeza.izquierda;
    }
};

#endif // SPLAYTREE_H
