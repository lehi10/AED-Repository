#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;

template <typename T>
class nodoD
{
    private:
        T m_dato;
        nodoD<T> * m_Nnext;
        nodoD<T> * m_Nprev;
    public:
        nodoD(T dato):m_dato(dato),m_Nnext(nullptr),m_Nprev(nullptr){}
        void set_Nnext(nodoD<T> *nodo){m_Nnext=nodo;}
        void set_Nprev(nodoD<T> *nodo){m_Nprev=nodo;}
        void set_NP (nodoD<T> *nodoN,nodoD<T> *nodoP){m_Nprev=nodoP;m_Nnext=nodoN;}
        void set_dat(T dato){m_dato=dato;}
        T getDato(){return m_dato;}

        nodoD<T> * get_Nprev(){return m_Nprev;}
        nodoD<T> * get_Nnext(){return m_Nnext;}

        friend ostream & operator << (ostream & os, nodoD<T> & nodo)
        {
            os<<nodo.m_dato<<" "<<endl;
            return;
        }
        void killme(){if(m_Nnext) delete m_Nnext; delete this;}
};




#endif // NODO_H
