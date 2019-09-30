#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//UNO

template <typename Objeto>
void printLots(list<Objeto> L, list<int>P)
{
    typename list<int>::const_iterator pIterador;
        //para recorrer la lista P
    typename list<Objeto>::const_iterator lIterador;
        //para recorrer la lista L
    int inicio=0;
    lIterador=L.begin();
    for(pIterador=P.begin();pIterador!=P.end()&& lIterador!=L.end();pIterador++)
        //Recorre la lista hasta que una de ellas llegue al final
    {
        while(inicio<*pIterador && lIterador!=L.end())
        {
            //Busca la posicion
            inicio++;
            lIterador++;
        }
        if(lIterador!=L.end())
        {
            //salida del objeto
            std::cout<<*lIterador<<std::endl;
        }
    }
}

//DOS
//A

template<typename Object>
struct NodoTipo
{
    Object Dato;
    NodoTipo<Object>* siguiente;
};

template <typename Object>
void intercambio(NodoTipo<Object>* antes)
{
    //antes  se ubica detras de los nodos a intercambiar
    //se intercambia centro con despues
    NodoTipo<Object>* centro;
    NodoTipo<Object>* despues;

    centro=antes->siguiente;
    despues=centro->siguiente;

    centro->siguiente=despues->siguiente;
    antes->siguiente=despues;
    despues->siguiente=centro;
}

//B

template<typename Object>
struct NodoDTipo
{
    Object Dato;
    NodoDTipo<Object>* siguiente;
    NodoDTipo<Object>* anterior;
};

template <typename Object>
void intercambio(NodoDTipo<Object>* centro)
{
    //se intercambia centro con el despues
    NodoDTipo<Object>* antes;
    NodoDTipo<Object>* despues;

    //se asignan los punteros inicialmente
    antes=centro->anterior;
    despues=centro->siguiente;

    //se intercambian los enlaces
    centro->siguiente=despues->siguiente;
    antes->siguiente=despues;
    despues->siguiente=centro;
    centro->siguiente->anterior=centro;
    centro->anterior=despues;
    despues->anterior=antes;
}

//TRES

template <typename Iterador, typename Objeto>
Iterador find(Iterador inicio, Iterador fin, const Objeto& x)
{
    Iterador iter=inicio;
    while(iter!=end && *iter!=x)
    {
        iter++;
    }
    return iter;
}

//CUATRO

template <typename Objeto>
list<Objeto> intersection(const list<Objeto>& l1,const list<Objeto>& l2)
{
    list<Objeto> inter;
    typename list<Objeto>:: const_iterator iterL1=l1.begin();
    typename list<Objeto>:: const_iterator iterL2=l2.begin();

    while(iterL1!= l1.end() && iterL2 != l2.end())
    {
        if(*iterL1==*iterL2)
        {
            inter.push_back(*iterL1);
            iterL1++;
            iterL2++;
        }
        else if(*iterL1<*iterL2)
        {
            iterL1++;
        }
        else
        {
            iterL2++;
        }
        return inter;
    }
}

//CINCO

template <typename Objeto>
list<Objeto> unionlistas(const list<Objeto>& l1,const list<Objeto>& l2)
{
    list<Objeto> uni;
    typename list<Objeto>:: const_iterator iterL1=l1.begin();
    typename list<Objeto>:: const_iterator iterL2=l2.begin();

    while(iterL1!= l1.end() && iterL2 != l2.end())
    {
        if(*iterL1==*iterL2)
        {
            uni.push_back(*iterL1);
            iterL1++;
            iterL2++;
        }
        else if(*iterL1<*iterL2)
        {
            uni.push_back(*iterL1);
            iterL1++;
        }
        else
        {
            uni.push_back(*iterL2);
            iterL2++;
        }
        return uni;
    }
}

//SIETE

template <typename Objeto>
Objeto& operator[](int indice)
{
    if(indice>=0 && indice < size())
    {
        return objetos[indice];
    }
    else
    {
        std::cout<<"Indice fuera de rango.."<<std::endl;
    }
    return objetos[0];
}
template <typename Objeto>
const Objeto& operator[](int indice)const
{
    //objetos se considera el array en el que la clase vector
    //almacena los datos
    if(indice>=0 && indice < size())
    {
        return objetos[indice];
    }
    else
    {
        std::cout<<"Indice fuera de rango.."<<std::endl;
    }
    return objetos[0];

}

//OCHO
template <typename Objeto>
iterator insert(iterator pos,const Objeto& x)
{
    Objeto *iter=&objectos[0];
    Objeto *ArrayAnt=objetos;
    tamanio++;
    int i;
    if(capacidad<tamanio)
    {
        capacidad=tamanio;
    }
    objetos=new Objeto[capacidad];//aumenta el tamaño del array
    while(iter!= pos)
    {
        objetos[i]=ArrayAnt[i];
        iter+=sizeOf(Objeto);
        pos+=sizeOf(Objeto);
        i++;
    }
    objetos[pos]=x;
    for(int k=pos+1;k<tamanio;k++)
    {
        objetos[k]=ArrayAnt[k];
    }
    delete [] ArrayAnt;

    return& objetos[pos];
}

//NUEVE

//Pues esas funciones requieren aveces redimencionar el vector, en ese caso los
//iteradores de la matriz anterior se pierden validez en la nueva.

//DIEZ

//A

template <typename Objeto>
class const_iterator
{
    public:
        const Objeto& operator*()const
        {
            return recuperar();
        }

        const_iterator& operator++()
        {
            actual++;
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator anterior=*this;
            ++(*this);
            return anterior;
        }
        bool operator==(const const_iterator& rhs) const
        {
            return actual==rhs.actual;
        }
        bool operator!=(const const_iterator& rhs) const
        {
            return !(*this==rhs);
        }
    protected:
        Objeto *actual;
        const vector<Objeto> * elVector;

        Objeto& recuperar()const
        {
            afirmarEsValido();
            return *actual;
        }

        const_iterator(const vector<Objeto>& vect, Objeto *p)
        {
            elVector=&vect;
            actual=p;
        }

        void afirmarEsValido()const
        {
            if(elVector==NULL || actual==NULL)
            {
                throw IteratorOutOfBoundsException();
            }
        }
        friend class Vector<Objeto>;
};

//B

template <typename Objeto>
class iterator : const_iterator
{
    public:
        Objeto& operator*()
        {
            return recuperar();
        }

        const Objeto& operator*()const
        {
            return const_iterator::operator*();
        }

        const_iterator& operator++()
        {
            actual++;
            return *this;
        }

        const_iterator operator++(int)
        {
            iterator anterior=*this;
            ++(*this);
            return anterior;
        }

    protected:

        iterator(const Vector<Objeto>& vect, Objeto *p)
        {
            const_iterator(vect,p);
        }
        friend class Vector<Objeto>;
};

//C

iterator begin()
{
    return iterator(*this, &objetos[0]);
}
const_iterator begin() const
{
    return const_iterator(*this, &objetos[0]);
}
iterator end()
{
    return iterator(*this,&objetos[size()]);
}
const_iterator end() const
{
    return const_iterator(*this,&objetos[size()]);
}

//ONCE

template <typename Objeto>
struct Nodo
{
    Objeto dato;
    Nodo* siguiente;
    Nodo(const Objeto& d=Objeto(),Nodo *n=nullptr)
    {
        dato=d;
        siguiente=n;
    }
};

template <typename Objeto>
class ListaSimple
{
    public:
        ListaSimple()
        {
            inicializar();
        }
        ~ListaSimple()
        {
            limpiarLista(cabeza);
        }

        ListaSimple(const ListaSimple& rhs)
        {
            limpiarLista(cabeza);
            inicializar();
            *this=rhs;
        }
        bool agregar(Objeto x)
        {
            if(contiene(x))
            {
                return false;
            }
            else
            {
                Nodo<Objeto>* ptr=new Nodo<Objeto>(x);
                ptr->siguiente=cabeza->siguiente;
                cabeza->siguiente=ptr;
                longitud++;
            }
            return true;
        }
        bool remover(Objeto x)
        {
            if(!contiene(x))
            {
                return false;
            }
            else
            {
                Nodo<Objeto>* ptr=cabeza->siguiente;
                Nodo<Objeto>* anterior;
                while(ptr->dato!=x)
                {
                    anterior=ptr;
                    ptr=ptr->siguiente;
                }
                anterior->siguiente=ptr->siguiente;
                delete ptr;
                longitud--;
            }
            return true;
        }
        int tamanio()
        {
            return longitud;
        }
        void mostrar()
        {
            Nodo<Objeto> *ptr=cabeza->siguiente;
            while(ptr!=nullptr)
            {
                std::cout<<ptr->dato<<" ";
                ptr=ptr->siguiente;
            }
            std::cout<<std::endl;
        }
        bool contiene(const Objeto& x)
        {
            Nodo<Objeto>* ptr=cabeza->siguiente;
            while(ptr!=nullptr)
            {
                if(x==ptr->dato)
                {
                    return true;
                }
                else
                {
                    ptr=ptr->siguiente;
                }
            }
            return false;
        }
        void inicializar()
        {
            longitud=0;
            cabeza=new Nodo<Objeto>;
            cabeza->siguiente=nullptr;
        }
        void limpiarLista(Nodo<Objeto>* h)
        {
            Nodo<Objeto>* ptr=h;
            Nodo<Objeto>*sigPtr;
            while(ptr!=nullptr)
            {
                sigPtr=ptr->siguiente;
                delete ptr;
                ptr=sigPtr;
            }
        }
    private:
        Nodo<Objeto>* cabeza;
        int longitud;
};

//DOCE


template <typename Objeto>
class ListaSimpleO
{
    public:
        ListaSimpleO()
        {
            inicializar();
        }
        ~ListaSimpleO()
        {
            limpiarLista(cabeza);
        }

        ListaSimpleO(const ListaSimpleO& rhs)
        {
            limpiarLista(cabeza);
            inicializar();
            *this=rhs;
        }
        bool agregar(Objeto x)
        {
            if(contiene(x))
            {
                return false;
            }
            else
            {
                Nodo<Objeto>* ptr=cabeza->siguiente;
                Nodo<Objeto>* anterior=cabeza;
                while(ptr && ptr->dato < x)
                {
                    anterior=ptr;
                    ptr=ptr->siguiente;
                }
                anterior->siguiente=new Nodo<Objeto>(x);
                anterior->siguiente->siguiente=ptr;
                longitud++;
            }
            return true;
        }
        bool remover(Objeto x)
        {
            if(!contiene(x))
            {
                return false;
            }
            else
            {
                Nodo<Objeto>* ptr=cabeza->siguiente;
                Nodo<Objeto>* anterior;
                while(ptr->dato!=x)
                {
                    anterior=ptr;
                    ptr=ptr->siguiente;
                }
                anterior->siguiente=ptr->siguiente;
                delete ptr;
                longitud--;
            }
            return true;
        }
        int tamanio()
        {
            return longitud;
        }
        void mostrar()
        {
            Nodo<Objeto> *ptr=cabeza->siguiente;
            while(ptr!=nullptr)
            {
                std::cout<<ptr->dato<<" ";
                ptr=ptr->siguiente;
            }
            std::cout<<std::endl;
        }
        bool contiene(const Objeto& x)
        {
            Nodo<Objeto>* ptr=cabeza->siguiente;
            while(ptr!=nullptr&& ptr->dato<=x)
            {
                if(x==ptr->dato)
                {
                    return true;
                }
                else
                {
                    ptr=ptr->siguiente;
                }
            }
            return false;
        }
        void inicializar()
        {
            longitud=0;
            cabeza=new Nodo<Objeto>;
            cabeza->siguiente=nullptr;
        }
        void limpiarLista(Nodo<Objeto>* h)
        {
            Nodo<Objeto>* ptr=h;
            Nodo<Objeto>*sigPtr;
            while(ptr!=nullptr)
            {
                sigPtr=ptr->siguiente;
                delete ptr;
                ptr=sigPtr;
            }
        }
    private:
        Nodo<Objeto>* cabeza;
        int longitud;
};

//TRECE

const_iterator& operator--()
{
    actual=actual->anterior;
    return *this;
}
const_iterator operator--(int)
{
    const_iterator ant=*this;
    --(*this);
    return ant;
}

//CATORCE

const_iterator & operator+(int k)
{
    const_iterator avance=*this;
    for(int i=0;i<k;i++)
    {
        avance.actual=avance.actual->siguiente;
    }
    return avance;
}

//QUINCE

void splice(iterator itr, list<Objeto>& lst)
{
    itr.assertIsValid();

    if(itr.laLista!=this)
    {
        throw IteratorMismatchException ();
    }
    Nodo *p =iter.actual;
    longitud+=lst.size();
    p->anterior->siguiente=lst.cabeza->siguiente;
    lst.cabeza->siguiente->anterior=p->anterior;
    lst.cola->anterior->siguiente=p;
    p->anterior=lst->cola->anterior;
    lst.inicializar();
}

//DIESISEIS

const_reverse_iterator rbegin()const
{
    return const_reverse_iterator itr(cola);
}
const_reverse_iterator rend()const
{
    return const_reverse_iterator itr(cabeza);
}

reverse_iterator rbegin()const
{
    return const_reverse_iterator itr(cola);
}
reverse_iterator rend()const
{
    return const_reverse_iterator itr(cabeza);
}


//DIESIOCHO

//Se usa un Nodo con un dato miembro que indica verdadero o falso
//el metodo borrado cambiaria estos datos
//y los iteradores lo verificarian

//DIESINUEVE

//Se necesita el puntero para evitar que la insercion al final sea O(n)
//y se necesita un puntero a l cabeza para insertar nodos antes de la cabeza

//VEINTE

//La principal desventaja es la memoria mal utilizada, lo bueno es que funcionaria como
//papelera de reciclaje y el borrado seria mas rapido

//VENTIUNO

bool verificarPascal(std::string lexema)
{
    std::stack<string> pila;
    for(int i=0;i<lexema.size();i++)
    {
        switch(i)
        {
            case "(":
                if()
                {

                }
                else
                {

                }
        }
    }
}

int main()
{
    //UNO
    /*
    list<string> listaL;
    listaL.push_front("a");
    listaL.push_front("b");
    listaL.push_front("c");
    listaL.push_front("d");
    listaL.push_front("3");


    list<int> listaP;
    listaP.push_back(0);
    listaP.push_back(1);
    listaP.push_back(4);
    listaP.push_back(5);
    printLots(listaL,listaP);
    */

    //DOS

    cout << "Hello world!" << endl;
    return 0;
}
