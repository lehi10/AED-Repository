#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;

template <typename T>
class Nodo
{
    public:
        Nodo(){m_dato=NULL,m_pSig=nullptr;}
        Nodo(T dato){ m_dato = dato; m_pSig=nullptr;}
        void addSig(Nodo<T> *nodo){m_pSig=nodo;}
 //  private:
        T m_dato;
        Nodo<T> * m_pSig;
};


#endif // NODO_H
