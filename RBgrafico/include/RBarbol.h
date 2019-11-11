#ifndef RBARBOL_H
#define RBARBOL_H

template <typename Comparable>
class RBarbol
{
public:
    RBarbol()
    {

    }
    RBarbol(const RBarbol& rhs);
    RBarbol(RBarbol&& rhs);
    ~RBarbol();

    const Comparable& buscarMin()const;
    const Comparable& buscarMax()const;
    bool contiene(const Comparable& x)const;
    bool estaVacio()const;
    void mostrar()const;

    void inicializar()
    {
        inicializar(raiz);
    }
    void insertar(const Comparable& x);
    void remover(const Comparable& x);

    enum{RED, BLACK};

    RBarbol& operator=(const RBarbol& rhs);
    RBarbol& operator=(RBarbol&& rhs);

protected:

private:

    struct NodoRB
    {
        Comparable dato;
        NodoRB *izquierda;
        NodoRB *derecha;
        NodoRB *p;
        int color;

        NodoRB(const Comparable& dat=Comparable{},NodoRB* izq=NIL, NodoRB* der=NIL,int c=BLACK)
        :dato{dat},izquierda{izq},derecha{derecha},color{c}{}

        NodoRB(Comparable&& dat,NodoRB *izq=NIL,NodoRB *der=NIL,int c=BLACK)
        :dato{std::move(dat)},izquierda{izq},derecha{der},color{c}{}


    };


    NodoRB *raiz;
    NodoRB *NIL;
    //punteros de nodoRB
    //
    //
    //

    NodoRB* nuevoNodo(int dato)
    {
        NodoRB* nuevo=new NodoRB{dato};
        return nuevo;
    }

    buscar()
    {

    }



};

#endif // RBARBOL_H
