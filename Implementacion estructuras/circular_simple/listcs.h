#ifndef LISTCS_H
#define LISTCS_H
#include "Nodo.h"
#include <iostream>
using namespace std;


template <typename T>
class ListCS
{
    public:
        ListCS();
        void Lpush_back(T dato);
        void Lpush_front(T dato);
        void Lfind(T dato, Nodo<T> * &p);
        void print();
        void remove_front();
        void remove_back();
        void remove(T dato);
        bool find_rec(T dato, Nodo<T> *&p,int flag);
        void insert_rec(T dato);

        void clear();
    public:
        Nodo<T> * m_pbegin;
        Nodo<T> * m_plast;

};
template <typename T>
ListCS<T>::ListCS()
{
    m_pbegin=nullptr;
    m_plast=nullptr;
    return;
}

template <typename T>
void ListCS<T>::Lpush_back(T dato)
{
    if(m_plast)
    {
        Nodo<T> *nodo_ptr=new Nodo<T>(dato);
        m_plast->addSig(nodo_ptr);
        m_plast=nodo_ptr;
        m_plast->addSig(m_pbegin);
        return;
    }
    m_pbegin=new Nodo<T>(dato);
    m_plast=m_pbegin;
    m_plast->addSig(m_pbegin);
    return;
}

template <typename T>
void ListCS<T>::Lpush_front(T dato)
{
    if(m_pbegin)
    {
        Nodo<T> *ptr_nodo=new Nodo<T>(dato);
        ptr_nodo->addSig(m_pbegin);
        m_pbegin=ptr_nodo;

        m_plast->addSig(m_pbegin);
        return;
    }
    m_pbegin=new Nodo<T>(dato);
    m_plast=m_pbegin;
    m_plast->addSig(m_pbegin);
    return;
}

template <typename T>
void ListCS<T>::Lfind(T dato, Nodo<T> * &p)
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
void ListCS<T>::print()
{
    if(m_pbegin)
    {
        Nodo<T> *temp=m_pbegin;
        bool flag=true;
        while(flag==true)
        {
            if(temp==m_plast)
                flag=false;
            cout<< temp->m_dato<<" ";
            temp=temp->m_pSig;
        }
        cout<<endl<<"begin    :"<<m_pbegin->m_dato<<endl;
        cout<<"last     :"<<m_plast->m_dato<<endl;
        cout<<"next last:"<<m_plast->m_pSig->m_dato<<endl;
    }
}

template <typename T>
void  ListCS<T>::remove_front()
{

    if(m_pbegin==m_plast)
    {
        delete m_pbegin;
        m_pbegin=nullptr;
        m_plast=nullptr;
        return;
    }

    if(m_pbegin)
    {
        Nodo<T> *nodo_ptr=m_pbegin;
        m_pbegin=m_pbegin->m_pSig;
        delete nodo_ptr;
        m_plast->addSig(m_pbegin);
        return;
    }

}

template <typename T>
void  ListCS<T>::remove_back()
{
    if(m_pbegin==m_plast)
    {
        m_plast=nullptr;
        delete m_pbegin;
        m_pbegin=nullptr;
        return;
    }
    if(m_plast)
    {
        Nodo<T> *nodo_ptr=m_plast,
                *nodo_temp=m_pbegin;
        while(nodo_temp->m_pSig != m_plast)
        {
            nodo_temp=nodo_temp->m_pSig;
        }
        m_plast=nodo_temp;
        m_plast->addSig(m_pbegin);
        delete nodo_ptr;
        return;
    }
    return;
}


template <typename T>
void  ListCS<T>::remove(T dato)
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
            return;
        }
        int flag=true;
        while(flag==true)
        {
            if(temp->m_pSig && temp->m_pSig->m_dato == dato)
            {
                Nodo<T> *ptr_temp = temp->m_pSig;
                temp->addSig(temp->m_pSig->m_pSig);
                delete ptr_temp;
                return;
            }
            if(m_plast==temp)
                flag=false;
            temp=temp->m_pSig;
        }
        return;
    }
}

template<typename T>
void ListCS<T>::clear()
{
    while(m_pbegin)
        this->remove_front();
}

template<typename T>

bool ListCS<T>::find_rec(T dato, Nodo<T> *& ptr_nodo,int flag)
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
        find_rec(dato,ptr_nodo,flag);
    }
}



template<typename T>
void ListCS<T>::insert_rec(T dato)
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


#endif // LISTCS_H
