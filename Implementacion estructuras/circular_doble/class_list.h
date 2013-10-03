#ifndef CLASS_LIST_H
#define CLASS_LIST_H
#include "Nodo.h"
#include <iostream>
using namespace std;
#include <list>

typedef size_t t_size;
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
        bool find_rec(T dato);
        void insert_rec(T dato);
        T Lmax();
        t_size Lsize();
        t_size Lcont(T dato);
        class_list<T> * Lintr(class_list<T> * fr_list );
        class_list<T> * Ljoin(class_list<T> * fr_list );
        void reverse();
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
        cout<< temp->m_dato <<" ";
        temp=temp->m_pSig;
    }
    cout<<endl;
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
template<typename T>
T class_list<T>::Lmax()
{
    if(m_pbegin)
    {
        T comp=m_pbegin->m_dato;
        Nodo<T> *it=m_pbegin->m_pSig;
        while(it != m_end)
        {
            if(it->m_dato > comp)
                comp=it->m_dato;
            it=it->m_pSig;
        }
        return comp;
    }
    return NULL;
}

template<typename T>
t_size class_list<T>::Lsize()
{
    if(m_pbegin)
    {
        t_size cont=1;
        Nodo<T> *it=m_pbegin->m_pSig;
        while(it != m_end)
        {
            cont++;
            it=it->m_pSig;
        }
        return cont;
    }
    return 0;
}


template<typename T>
t_size class_list<T>::Lcont(T dato)
{
    if(m_pbegin)
    {
        t_size cont=0;
        Nodo<T> *it=m_pbegin;
        while(it != m_end)
        {
            if(dato == it->m_dato)
                cont++;
            it=it->m_pSig;
        }
        return cont;
    }
    return 0;
}



template<typename T>
bool class_list<T>::find_rec(T dato)
{
    Nodo<T> *it= m_pbegin;
    while(it != m_end)
    {
        if(it->m_dato == dato)
            return true;
        it=it->m_pSig;
    }
    return false;
}


template<typename T>
class_list<T> * class_list<T>::Lintr(class_list<T> * fr_list )
{
    class_list<T> *new_list=new class_list<T>;
    if(fr_list->Lsize() && this->Lsize())
    {
        Nodo<T> *it=fr_list->m_pbegin;
        while(it)
        {
            T temp_dato=it->m_dato;
            if(this->find_rec(temp_dato) && !new_list->find_rec(temp_dato) )
            {
                new_list->Lpush_back(temp_dato);
            }
            it=it->m_pSig;
        }
    }
    return new_list;
}

template<typename T>
class_list<T> * class_list<T>::Ljoin(class_list<T> * list_x )
{
    class_list<T> *new_list=new class_list<T>;
    Nodo<T> *it_frs= this->m_pbegin;
    Nodo<T> *it_scd= list_x->m_pbegin;
    for(int i=0;i< this->Lsize();i++)
    {
        new_list->Lpush_back(it_frs->m_dato);
        it_frs=it_frs->m_pSig;
    }
    for(int i=0;i< list_x->Lsize();i++)
    {
        new_list->Lpush_back(it_scd->m_dato);
        it_scd=it_scd->m_pSig;
    }
    Nodo<T> *it_new=new_list->m_pbegin;

    while(it_new)
    {
        t_size cont=new_list->Lcont(it_new->m_dato);
        if( cont > 1)
            for(int i=1;i<cont;i++)
                new_list->remove(it_new->m_dato);
        it_new=it_new->m_pSig;
    }
    return new_list;
}

template<typename T>
void class_list<T>::reverse()
{
    if(m_pbegin)
    {
        Nodo<T> *it=m_pbegin;
        for(int i=1;i<this->Lsize();i++)
        {
            T temp_dato=it->m_pSig->m_dato;
            this->remove(temp_dato);
            this->Lpush_front(temp_dato);
        }
    }
}

#endif // CLAS_LIST_H
