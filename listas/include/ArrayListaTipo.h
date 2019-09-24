#ifndef ARRAYLISTATIPO_H
#define ARRAYLISTATIPO_H
#include <iostream>
#include <cassert>


template <class T>
class ArrayListaTipo
{
    public:
        const ArrayListaTipo<T>& operator=(const ArrayListaTipo<T>& otra);
            //sobrecarga operador de asignacion
        bool estaVacia()const;
            //determina si la lista esta vacia
            //postcondition: Retorna TRUE si la lista esta vacia y FALSE en los
            //demas casos
        bool estaLLena()const;
            //determina si la lista esta llena
            //postcondition: Retorna TRUE si la lista esta llena y FALSE en los demmas casos
        int longitudLista()const;
            //Retorna el numero de elementos de la lista
            //postcondition: Retorna el valor de longitud
        int capacidadLista()const;
            //Retorna el tamaño de la lista
            //postcondition: Retrona el valor de capMaxima
        void mostrar()const;
            //Funcion de dalida de los elementos de la lista
            //Postcondition: Elementos de la lista se emiten por la salida estandar
        bool estaEnPosicion(int posicion, const T& item)const;
            //Funcion que determina si item es el mismo qeu el item de la lista[pos]
            //postcondition: Retorna TRUE si lista[posicion] es igual que item,
            //en otros casos FALSE
        void insertarEn(int posicion, const T& item);
            //Funcion que inserta un elemento en la lista en la posicion indicada
            //postcondition: comenzando en la ubicacion los elementos son desplazados
            //hacia la derecha, lista[posicion]=item y longitud++, si la lista esta llena
            //se muestra un mensaje
        void insertarFinal(const T& item);
            //Funcion que inserta un elemento en el final de la lista
            //postcondition: lista[longitud]=item y longitud++, si la lista esta llena
            //se muestra un mensaje
        void eliminarDe(int posicion);
            //Remueve el elemento indicado por posicion
            //postcondition: el elemento de la lista[posicion] es removido y la longitud se disminuye en 1
            //si la ubicacion esta fuera de rango se muestra un mensaje
        void recuperarDe(int posicion, T& retItem)const;
            //Recupera el elemento de la lista de la posicion indicada
            //postcondition: retItem==lista[posicion]
            //si la ubicacion esta fuera de rango se muestra un mensaje
        void remplazarEn(int posicion, const T& item);
            //Remplaza los elementos de la lista en la posicion indicada,
            //el item que remplazara se especifica por el parametro "item"
            //postcondition: lista[posicion]=item
            //si la ubicacion esta fuera de rango se muestra un mensaje
        void limpiarLista();
            //Remueve todos los elementos de la lista
            //despues de todas las operaciones longitud=0
            //postcondition:longitud=0
        int busquedaSecuencial(const T& item)const;
            //Busca un item en la lista secuencialmente
            //postcondition: Si el item es encontrado retorna el valor de indice
            //del array, en otros casos retorna -1

        void insertar(const T& item);
            //Funcion que inserta el elemento indicado por "item" al final de la lista
            //sin embargo, primero busca en la lista si el item ya existe
            //postcondition: lista[longitud]=item y longitud++, si el item ya existe
            //o la lista esta llena, se muestra el mensaje apropiado
        void remover(const T& item);
            //Funcion que remueve un elemendo de la lista, el parametro "item" indica el item
            //a remover
            //postcondition: Si el item esta en la lista se remueve y se diminuye en 1 la longitud
        ArrayListaTipo(int tam=100);
            //constructor
            //crea un vector de tamaño indicado por "tam", por defecto tam=100
            //postcondition: lista apunta a la matriz creada y longitud =0,
            //camMaxima=tam;
        ArrayListaTipo(const ArrayListaTipo<T>& otra);
            //constructor copia
        ~ArrayListaTipo();
            //destructor



    protected:
        T *lista; //matriz que almacenara los elementos
        int longitud;
        int capMaxima;

    private:
};

template <class T>
bool ArrayListaTipo<T>::estaVacia()const
{
    return (longitud==0);
}//end estaVacia

template <class T>
bool ArrayListaTipo<T>::estaLLena() const
{
    return (longitud=capMaxima);
}//end estaLLena

template <class T>
int ArrayListaTipo<T>::longitudLista()const
{
    return longitud;
}//end longitudLista

template <class T>
int ArrayListaTipo<T>::capacidadLista()const
{
    return  capMaxima;
}//end capacidadLista

template <class T>
void ArrayListaTipo<T>::mostrar()const
{
    for(int i=0;i<longitud;i++)
    {
        std::cout<<lista[i]<<" ";
    }
    std::cout<<std::endl;
}//end mostrar

template <class T>
bool ArrayListaTipo<T>::estaEnPosicion(int posicion, const T& item)const
{
    return(lista[posicion]==item);
}//end estaEnPosicion

template <class T>
void ArrayListaTipo<T>::insertarEn(int posicion, const T& item)
{
    if(posicion<0 || posicion>=capMaxima)
    {
        std::cerr<<"La posicion esta fuera del rango"<<std::endl;
    }
    else
    {
        if(longitud>=capMaxima)
        {
            std::cerr<<"La lista esta llena"<<std::endl;
        }
        else
        {
            for(int i=longitud;i>posicion;i--)
            {
                lista[i]=lista[i-1];
            }
            lista[posicion]=item;
            longitud++;
        }//end else
    }//end else
}//end insertarEn

template <class T>
void ArrayListaTipo<T>::insertarFinal(const T& item)
{
    if(longitud>=capMaxima)
    {
        std::cerr<<"La lista esta llena"<<std::endl;
    }
    else
    {
        lista[longitud]=item;
        longitud++;
    }
}//end insertarFinal

template <class T>
void ArrayListaTipo<T>::eliminarDe(int posicion)
{
    if(posicion<0 || posicion>=capMaxima)
    {
        std::cerr<<"La posicion esta fuera del rango"<<std::endl;
    }
    else
    {
        for(int i=posicion;i<longitud-1;i++)
        {
            lista[i]=lista[i+1];
        }
        longitud--;
    }
}//end eliminarDe

template <class T>
void ArrayListaTipo<T>::recuperarDe(int posicion, T& retItem)const
{
    if(posicion<0 || posicion>=capMaxima)
    {
        std::cerr<<"La posicion esta fuera del rango"<<std::endl;
    }
    else
    {
        retItem=lista[posicion];
    }
}//end recuperarDe

template <class T>
void ArrayListaTipo<T>::remplazarEn(int posicion, const T& item)
{
    if(posicion<0 || posicion>=capMaxima)
    {
        std::cerr<<"La posicion esta fuera del rango"<<std::endl;
    }
    else
    {
        lista[posicion]=item;
    }
}//end remplazarEn

template <class T>
void ArrayListaTipo<T>::limpiarLista()
{
    longitud=0;
}//end limpiarLista

template <class T>
ArrayListaTipo<T>::ArrayListaTipo(int tam)
{
    if(tam<0)
    {
        std::cerr<<"La lista necesita un numero positivo "
                <<"por defecto se usara tam 100"<<std::endl;
        capMaxima=100;
    }
    else
    {
        capMaxima=tam;
    }

    longitud=0;
    lista=new T[capMaxima];
    assert (lista!=NULL);
    //ctor
}

template <class T>
ArrayListaTipo<T>::~ArrayListaTipo()
{
    delete [] lista;
    //dtor
}

template <class T>
ArrayListaTipo<T>::ArrayListaTipo(const ArrayListaTipo<T>& otra)
{
    capMaxima=otra.capMaxima;
    longitud=otra.longitud;
    lista=new T[capMaxima];
    assert(lista!=NULL);
    for(int i=0;i<longitud;i++)
    {
        lista[i]=otra.lista[i];
    }
    //copy ctor
}

template <class T>
const ArrayListaTipo<T>& ArrayListaTipo<T>::operator=(const ArrayListaTipo<T>& otra)
{
    if (this != &otra)
    {
        delete [] lista;
        capMaxima=otra.capMaxima;
        longitud=otra.longitud;

        lista=new T[capMaxima];
        assert(lista!=NULL);
        for(int i=0;i<longitud;i++)
        {
            lista[i]=otra.lista[i];
        }
    } //end if
    return *this;
}//end operator=


template <class T>
int ArrayListaTipo<T>::busquedaSecuencial(const T& item)const
{
    int pos;
    bool busqueda=false;
    for (pos=0;pos<longitud;pos++)
    {
        if(lista[pos]==item)
        {
            busqueda=true;
            break;
        }
    }
    if(busqueda)
    {
        return pos;
    }
    else
    {
        return -1;
    }
}//end buusquedaSecuencial

template <class T>
void ArrayListaTipo<T>::insertar(const T& item)
{
    int pos;
    if(longitud==0)
    {
        lista[longitud++]=item;
    }
    else if(longitud==capMaxima)
    {
        std::cerr<<"La lista esta llena..."<<std::endl;
    }
    else
    {
        pos=busquedaSecuencial(item);
        if(pos==-1)
        {
            lista[longitud++]=item;
        }
        else
        {
            std::cerr<<"El elemento ya esta en la lista pe"<<std::endl;
        }
    }
}//end insert

template <class T>
void ArrayListaTipo<T>::remover(const T& item)
{
    int pos;
    if(longitud==0)
    {
        std::cerr<<"La lista esta vacia..."<<std::endl;
    }
    else
    {
        pos=busquedaSecuencial(item);
        if(pos!=-1)
        {
            eliminarDe(pos);
        }
        else
        {
            std::cerr<<"El elemento no esta en la lista pe"<<std::endl;
        }
    }
}



#endif // ARRAYLISTATIPO_H
