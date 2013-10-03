#ifndef PILA_H
#define PILA_H
#include "Nodo.h"
#include <iostream>
using namespace std;

template <typename T>
class Pila
{


    public:
        Pila():m_tope(nullptr){}
        void push_back(T dato);
        void pop_back();
        T top();
        bool is_empty();
        void print();

    private:
        Nodo<T> * m_tope;
};

#endif // PILA_H


template<typename T>
void Pila<T>::push_back(T dato)
{
    Nodo<T> *nodo_new= new Nodo<T>(dato);
    if(m_tope)
        nodo_new->set_prev(m_tope);
    m_tope=nodo_new;
}

template<typename T>
void Pila<T>::pop_back()
{
    if(m_tope)
    {
        Nodo<T> *temp=m_tope->get_prev();
        delete m_tope;
        m_tope=temp;
    }
}


template<typename T>
T Pila<T>::top()
{
    if(m_tope)
        return m_tope->get_dato();
    throw 1;
}


template <typename T>
bool Pila<T>::is_empty()
{
    if(m_tope)
        return false;
    return true;
}

template <typename T>
void Pila<T>::print()
{
    if(m_tope)
    {
        Nodo<T> *it=m_tope;
        while(it)
        {
            cout<< it->get_dato()<<" ";
            it=it->get_prev();
        }
    }

}
