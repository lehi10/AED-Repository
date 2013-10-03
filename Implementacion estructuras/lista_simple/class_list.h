#ifndef CLASS_LIST_H
#define CLASS_LIST_H
#include "Nodo.h"
#include <iostream>
using namespace std;
#include <list>


template <typename T>
class class_list
{
    public:
        class_list();
        void Lpush_back(T dato);
        void Lpush_front(T dato);
        void Lfind(T dato, Nodo<T> ** &p);
        void print();
        void remove_front();
        void remove_back();
        void remove(T dato);
        bool find_rec(T dato, Nodo<T> *&p);
        void insert_rec(T dato);

        void clear();
    public:
        Nodo<T> * m_pbegin;
        Nodo<T> * m_plast;
        Nodo<T> * m_end;
};
template <typename T>
class_list<T>::class_list()
{
    m_pbegin=nullptr;
    m_plast=nullptr;
    m_end=nullptr;
    return;
}

template <typename T>
void class_list<T>::Lpush_back(T dato)
{
    if(m_plast)
    {
        Nodo<T> *nodo_ptr=new Nodo<T>(dato);
        m_plast->addSig(nodo_ptr);
        m_plast=nodo_ptr;
        return;
    }
    m_pbegin=new Nodo<T>(dato);
    m_plast=m_pbegin;

    return;
}

template <typename T>
void class_list<T>::Lpush_front(T dato)
{
    if(m_pbegin)
    {
        Nodo<T> *ptr_nodo=new Nodo<T>(dato);
        ptr_nodo->addSig(m_pbegin);
        m_pbegin=ptr_nodo;
        m_end=m_plast->m_pSig;
        return;
    }
    m_pbegin=new Nodo<T>(dato);
    m_plast=m_pbegin;
    m_end=m_plast->m_pSig;
    return;
}

template <typename T>
void class_list<T>::Lfind(T dato, Nodo<T> ** &p)
{
    // para listas ordenadas
    p=m_pbegin;
    while(*p)
    {
        if((*p)->m_dato == dato)
            return true;
        if((*p)->m_dato > dato)
            return false;
        p=&((*p)->m_pSig);
    }
    return false;
}

template <typename T>
void class_list<T>::print()
{
    Nodo<T> *temp=m_pbegin;
    while(temp != m_end)
    {
        cout<< temp->m_dato <<endl;
        temp=temp->m_pSig;
    }
}

template <typename T>
void  class_list<T>::remove_front()
{
    if(m_pbegin->m_pSig == m_end)
    {
        m_end=nullptr;
        m_pbegin=nullptr;
        m_plast=nullptr;
        delete m_pbegin;
    }
    if(m_pbegin)
    {
        Nodo<T> *nodo_ptr=m_pbegin;
        m_pbegin=m_pbegin->m_pSig;
        delete nodo_ptr;
        return;
    }
    return;
}

template <typename T>
void  class_list<T>::remove_back()
{
    if(m_plast)
    {
        Nodo<T> *nodo_ptr=m_plast,
                *nodo_temp=m_pbegin;
        while(nodo_temp->m_pSig != m_plast)
        {
            nodo_temp=nodo_temp->m_pSig;
        }
        m_plast=nodo_temp;
        m_plast->addSig(nullptr);
        m_end=m_plast->m_pSig;
        delete nodo_ptr;
        return;
    }
    return;
}


template <typename T>
void  class_list<T>::remove(T dato)
{
    if(m_pbegin)
    {
        Nodo<T> *temp=m_pbegin ;
        if(temp->m_dato==dato)
        {
            this->remove_front();
            return;
        }
        if(m_plast->m_dato==dato)
        {
            this->remove_back();
        }
        while(temp != m_end)
        {
            if(temp->m_pSig && temp->m_pSig->m_dato == dato)
            {
                Nodo<T> *ptr_temp = temp->m_pSig;

                temp->addSig(temp->m_pSig->m_pSig);
                delete ptr_temp;
                return;
            }
            temp=temp->m_pSig;
        }
        return;
    }
}

template<typename T>
void class_list<T>::clear()
{
    while(m_pbegin)
        this->remove_front();
}


template<typename T>
bool class_list<T>::find_rec(T dato, Nodo<T> *& ptr_nodo)
{
    if(ptr_nodo->m_pSig)
    {
        if(dato < ptr_nodo->m_dato)
        {
            throw bad_alloc();
            return true;
        }
        if(dato==ptr_nodo->m_pSig->m_dato)
            return true;
        if(dato< ptr_nodo->m_pSig->m_dato)
            return false;
        if(ptr_nodo->m_pSig)
        {
            ptr_nodo=ptr_nodo->m_pSig;
            find_rec(dato,ptr_nodo);
        }
    }
}

template<typename T>
void class_list<T>::insert_rec(T dato)
{
    if(m_pbegin)
    {
        Nodo<T> *temp=m_pbegin;
        try
        {
            if(find_rec(dato,temp)or true)
            {
                Nodo<T> *ptr_nodo=new Nodo<T>(dato);
                ptr_nodo->addSig(temp->m_pSig);
                temp->addSig(ptr_nodo);
            }
        }
        catch(bad_alloc)
        {
            this->Lpush_front(dato);
            return;
        }
    }

}


#endif // CLAS_LIST_H
