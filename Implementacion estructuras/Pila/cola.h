#ifndef COLA_H
#define COLA_H
#include "Nodo.h"

template <typename T>
class cola
{
    public:
        cola():m_last(nullptr){}
        void push_back(T dato);
        void pop();
        bool is_empty();
        void print();
    private:
        Nodo<T> * m_last;

};

#endif // COLA_H
template <typename T>
void cola<T>::push_back(T dato)
{
    Nodo<T> *nodo_new= new Nodo<T>(dato);
    if(m_last)
        nodo_new->set_prev(m_last);
    m_last=nodo_new;
}

template <typename T>
void cola<T>::pop()
{

    if(m_last)
    {
        if(!m_last->get_prev())
        {
            delete m_last;
            m_last=nullptr;
            return;
        }

        Nodo<T> *it=m_last;
        while(it->get_prev()->get_prev())
            it=it->get_prev();
        delete it->get_prev();
        it->set_prev(nullptr);
        return;
    }
}

template <typename T>
bool cola<T>::is_empty()
{
    return m_last==nullptr;
}

template <typename T>
void cola<T>::print()
{
    if(m_last)
    {
        Nodo<T> *it=m_last;
        while(it)
        {
            cout<< it->get_dato()<<" ";
            it=it->get_prev();
        }
    }
    cout<<endl;

}
