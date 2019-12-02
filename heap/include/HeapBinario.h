#ifndef HEAPBINARIO_H
#define HEAPBINARIO_H
#include <vector>
#include <fstream>


template <typename C>
class HeapBinario
{
    public:
        explicit HeapBinario(int capacidad =100):datos(capacidad+1),tamanio{0}
        {}

        explicit HeapBinario(const std::vector<C>& items)
        {
            for(int i=0;i<items.size();++i)
                datos[i+1]=items[i];
            construir();
        }

        bool estaVacio()const
        {
            return tamanio==0;
        }
        const C &buscarMin()const
        {
            if(!estaVacio())
                return datos[1];
        }

        void insertar(const C & x)
        {
            int actual=datos.size();
            if(tamanio==actual-1)
                datos.resize(actual*2);
            int ranura=++tamanio;
            C copia=x;
            datos[0]=std::move(copia);
            for(;x<datos[ranura/2];ranura/=2)
                datos[ranura]=std::move(datos[ranura/2]);
            datos[ranura]=std::move(datos[0]);
        }
        void insertar(C && x)
        {
            int actual=datos.size();
            if(tamanio==actual)
                datos.resize(actual*2);
            int ranura=++tamanio;

            for(;ranura>1 && x<datos[ranura/2];ranura/=2)
                datos[ranura]=std::move(datos[ranura/2]);
            datos[ranura]=std::move(x);

        }
        void quitarMin()
        {
            if(!estaVacio())
            {
                datos[1]=std::move(datos[tamanio--]);
                colar(1);
            }
        }
        void quitarMin(C & item)
        {
            if(!estaVacio())
            {
                item=std::move(datos[1]);
                datos[1]=std::move(datos[tamanio--]);
                colar(1);
            }
        }
        void armarVacio()
        {
            tamanio=0;
        }

        void mostrar()const
        {
            std::fstream archivo;
            archivo.open("arbol.dot",std::fstream::out);
            archivo<<"digraph G{"<<std::endl;
            archivo<<"\tgraph [ordering=\"out\"];"<<std::endl;
            if( estaVacio( ) )
                archivo << "Empty heap" << std::endl;
            else
            {
                mostrar(datos,archivo);
            }
            archivo<<"}";
            archivo.close();
            system("dot -Tsvg arbol.dot -o ARBOL.png");

            std::fstream archivo2;
            archivo2.open("vec.dot",std::fstream::out);
            archivo2<<"digraph ll{"<<std::endl;
            archivo2<<"\tnode [shape=record];"<<std::endl;

            if( estaVacio( ) )
                archivo << "Empty heap" << std::endl;


            if(!estaVacio())
            {
                archivo2<<"\tnodo6[style=filled, label=\"{{"<<datos[1];

                for(int i=2;i<=tamanio;i++)
                {
                    archivo2<<"|"<<datos[i];
                }
                archivo2<<"}|{1";
                for(int i=2;i<=tamanio;i++)
                {
                    archivo2<<"|"<<i;
                }
                archivo2<<"}}\"];"<<std::endl;
            }
            archivo2<<"}";
            archivo2.close();
            system("dot -Tsvg vec.dot -o vec.png");

        }
    protected:

    private:

        std::vector<C> datos;
        int tamanio;



        void construir()
        {
            for(int i=tamanio/2;i>0;--i)
                colar(i);
        }
        void colar(int ranura)
        {
            int hijo;
            C temp=std::move(datos[ranura]);

            for(;ranura*2 <= tamanio;ranura=hijo)
            {
                hijo=ranura*2;
                if(hijo!=tamanio && datos[hijo+1]<datos[hijo])
                    ++hijo;
                if(datos[hijo]<temp)
                    datos[ranura]=std::move(datos[hijo]);
                else
                    break;
            }
            datos[ranura]=std::move(temp);
        }

        void mostrar(std::vector<C> t,std::fstream& archivo)const
        {
            archivo<<datos[1]<<";"<<std::endl;
            for(int i=2;i<=tamanio;i++)
            {
                archivo<<datos[i/2]<<"->"<<datos[i]<<";"<<std::endl;
            }

        }
};

#endif // HEAPBINARIO_H
