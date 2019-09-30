#ifndef ARBOLBINBUS_H
#define ARBOLBINBUS_H
#include <iostream>
#include <ostream>
#include <functional>


template <typename Objeto, typename Comparador=std::less<Objeto>>
class ArbolBinBus
{
    public:
        ArbolBinBus()//constructor por defecto
        {
            raiz=nullptr;
        }
        ArbolBinBus(const ArbolBinBus& rhs):raiz{nullptr}//constructor copia para lvalues
        {
            raiz=clonar(rhs.raiz);
        }
        ArbolBinBus(ArbolBinBus && rhs)//constructor move para rvalues
        {

        }
        ~ArbolBinBus()//destructor
        {
            prepararVacio();
        }

        const Objeto& buscarMinimo()const;
        const Objeto& buscarMaximo()const;
        bool contiene(const Objeto& x)const
        {
            return contiene(x,raiz);
        }
        bool estaVacio()const;
        void mostrarArbol(std::ostream& salida=std::cout)const;

        void prepararVacio()
        {

        }
        void insertar(const Objeto& x)
        {
            insertar(x,raiz);
        }
        void insertar(Objeto&& x)
        {
            insertar(std::move(x),raiz);
        }
        void remover(const Objeto& x)
        {
            remover(x,raiz);
        }


        ArbolBinBus& operator=(const ArbolBinBus& rhs);
        ArbolBinBus& operator=(ArbolBinBus&& rhs);

    protected:

    private:

        struct NodoBinario
        {
            Objeto dato;
            NodoBinario *izquierda;
            NodoBinario *derecha;

            NodoBinario(const Objeto& elemento, NodoBinario* subIzquierdo, NodoBinario* subDerecho)
            {
                dato=elemento;
                izquierda=subIzquierdo;
                derecha=subDerecho;
            }
            NodoBinario(Objeto&& elemento, NodoBinario* subIzquierdo, NodoBinario* subDerecho)
            {
                dato=std::move(elemento);
                izquierda=subIzquierdo;
                derecha=subDerecho;
            }

        };

        NodoBinario* raiz;
        Comparador esMenosQue;

        void insertar(const Objeto& x, NodoBinario*& t)
        {
            if(t==nullptr)
            {
                t=new NodoBinario{x,nullptr,nullptr};
            }
            else if(x < t->dato)
            {
                insertar(x,t->izquierda);
            }
            else if(x > t->dato)
            {
                insertar(x,t->derecha);
            }
            else
                ;//si llega aqui significa que el dato ya existe en el arbol
        }
        void insertar(Objeto&& x, NodoBinario*& t)
        {
            if(t==nullptr)
            {
                t=new NodoBinario{std::move(x),nullptr,nullptr};
            }
            else if(x < t->dato)
            {
                insertar(std::move(x),t->izquierda);
            }
            else if(x > t->dato)
            {
                insertar(std::move(x),t->derecha);
            }
            else
                ;//si llega aqui significa que el dato ya existe en el arbol
        }
        void remover(const Objeto& x, NodoBinario*& t)
        {
            if(t==nullptr)
            {
                return ; //Recorrio hasta aqui por la wea, ya que no encontro nada
            }
            else if(x < t->dato)
            {
                remover(x,t->izquierda);
            }
            else if(x > t->dato)
            {
                remover(x,t->derecha);
            }
            else if(t->izquierda!=nullptr && t->derecha!=nullptr)
            {
                t->dato=buscarMinimo(t->derecha)->dato;
                remover(t->dato,t->derecha);
            }
            else
            {
                NodoBinario* antiguo=t;
                t=(t->izquierda != nullptr)? t->izquierda:t->derecha;
                delete antiguo;
            }
        }
        NodoBinario* buscarMinimo(NodoBinario* t)const
        {
            if(t==nullptr)
            {
                return nullptr;
            }
            if(t->izquierda==nullptr)
            {
                return t;
            }
            return buscarMinimo(t->izquierda);
        }
        NodoBinario* buscarMaximo(NodoBinario* t)const
        {
            if(t!=nullptr)
            {
                while(t->derecha!=nullptr)
                {
                    t=t->derecha;
                }
            }//end if
            return t;
        }

        bool contiene(const Objeto& x,NodoBinario* t)const
        {
            if(t==nullptr)
            {
                return false;
            }
            else if(esMenosQue(x,t->dato))
            {
                return contiene(x,t->izquierda);
            }
            else if(esMenosQue(t->dato,x))
            {
                return contiene(x,t->derecha);
            }
            else
            {
                return false;
            }
        }
        void prepararVacio(NodoBinario*& t)
        {
            if(t!=nullptr)
            {
                prepararVacio(t->izquierda);
                prepararVacio(t->derecha);
                delete t;
            }
            t=nullptr;
        }
        void mostrarArbol(NodoBinario* t, std::ostream& salida)const;
        NodoBinario* clonar(NodoBinario* t)const
        {
            if(t==nullptr)
            {
                return nullptr;
            }
            else
            {
                return new NodoBinario{t->dato,clonar(t->izquierda),clonar(t->derecha)};
            }
        }
};






#endif // ARBOLBINBUS_H
