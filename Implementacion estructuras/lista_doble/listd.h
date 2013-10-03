#ifndef LISTD_H
#define LISTD_H
#include "nodod.h"
#include <iostream>

using namespace std;
template<typename T>
class ListD
{
    public:
        ListD():m_begin(nullptr),m_last(nullptr){}
        void LremoveFront();
        void LremoveBack();
        void Lremove(T dato);
        //-----------------
        void Linsert(T dato);
        void LaddRSort(T dato);
        T Lmax();
        int Lcount(T dato);
        int Lsize();
        ListD<T>* Linter(ListD<T>* lista);
        ListD<T>* Ljoin(ListD<T>* lista);
        //-----------
        void print();

        //-----------------------------------

        void Lreverse();            // !
        void killme();              // !
        void LpushFront(T dato);    // !
        void LpushBack(T dato);     // !
        bool  LfindR(T dato);       // !

        ListD<T>* operator +(ListD<T> & lista);
        ListD<T>*operator -(ListD<T> & lista);
        //friend ostream  & operator <<(ostream & os);
        ListD<T> & operator >>(T d);
        void sort();
        T & operator[] (int p);

        T & find(T dato);
        T & find_r(T dato);
        void index(string file);


    private:

        bool LfindRSort(nodoD<T> *&nodo,T dato);
        bool  LfindR(nodoD<T> *&nodo,T dato);
        nodoD<T> *m_begin;
        nodoD<T> *m_last;
        int m_size;
};

#endif // LISTD_H
template<typename T>
void ListD<T>::killme()
{
    if(m_begin)
        m_begin->killme();
    m_begin=nullptr;
    m_last=nullptr;
    delete this;
}


template<typename T>
void ListD<T>::LpushFront(T dato)
{
    if(m_begin)
    {
       nodoD<T> *ptrNew=new nodoD<T>(dato);
       m_begin->set_Nprev(ptrNew);
       ptrNew->set_Nnext(m_begin);
       m_begin=ptrNew;
       return;
    }
    nodoD<T> *ptrNew=new nodoD<T>(dato);
    m_begin=ptrNew;
    m_last=ptrNew;
}


template<typename T>
void ListD<T>::print()
{
    if(m_begin)
    {
        nodoD<T> *it=m_begin;
        while(it)
        {
            cout<<it->getDato()<<" ";
            it=it->get_Nnext();
        }
        cout<<endl;
        cout <<this-> m_begin->getDato()<< endl;
        cout<<this->m_last->getDato()<<endl;
    }
}
template <typename T>
void ListD<T>::LpushBack(T dato)
{
    if(m_begin)
    {
        nodoD<T> *ptr_new=new nodoD<T>(dato);
        m_last->set_Nnext(ptr_new);
        ptr_new->set_Nprev(m_last);
        m_last=ptr_new;
        return;
    }
    nodoD<T> *ptrNew=new nodoD<T>(dato);
    m_begin=ptrNew;
    m_last=ptrNew;
}

template <typename T>
void ListD<T>::LremoveFront()
{
    if(m_begin != m_last)
    {
        m_begin= m_begin->get_Nnext();
        delete m_begin->get_Nprev();
        m_begin->set_Nprev(nullptr);
        return;
    }
    if(m_begin == m_last)
    {
        delete m_last;
        m_begin=nullptr;
        m_last=nullptr;
        return;
    }
}

template <typename T>
void ListD<T>::LremoveBack()
{
    if(m_begin != m_last)
    {
        m_last=m_last->get_Nprev();
        delete m_last->get_Nnext();
        m_last->set_Nnext(nullptr);
    }
    if(m_begin == m_last)
    {
        delete m_last;
        m_begin=nullptr;
        m_last=nullptr;
        return;
    }
}

template<typename T>
void ListD<T>:: Lremove(T dato)
{
    if(m_begin->getDato()==dato)
    {
        this->LremoveFront();
        return;
    }
    if(m_last->getDato() ==dato)
    {
        this->LremoveBack();
        return;
    }
    if(m_begin)
    {
        nodoD<T> *it=m_begin;
        while(it)
        {
            if(dato == it->getDato())
            {
                it->get_Nprev()->set_Nnext(it->get_Nnext());
                it->get_Nnext()->set_Nprev(it->get_Nprev());
                delete it;
                return;
            }
            it=it->get_Nnext();
        }
    }
}


template <typename T>
void ListD<T>::Linsert(T dato)
{
    if(m_begin)
    {
        if(dato <= m_begin->getDato())
        {
            this->LpushFront(dato);
            return;
        }
        nodoD<T> *it=m_begin;
        while(it)
        {
            if(dato <= it->getDato())
            {
                nodoD<T> *ptr_new=new nodoD<T>(dato);
                ptr_new->set_NP(it,it->get_Nprev());
                it->get_Nprev()->set_Nnext(ptr_new);
                it->set_Nprev(ptr_new);
                return;
            }
            it=it->get_Nnext();
        }
    }
    this->LpushBack(dato);
}


template<typename T>
bool ListD<T>:: LfindR(nodoD<T> *&nodo,T dato)
{
    if(nodo)
    {
        if(nodo->getDato()==dato)
            return true;
        nodo=nodo->get_Nnext();
        return  LfindR(nodo,dato);
    }
    return false;
}

template<typename T>
bool ListD<T>::LfindR(T dato)
{
    if(m_begin)
    {
        nodoD<T> *it=m_begin;
        return LfindR(it,dato);
    }
    return false;
}

template<typename T>
bool ListD<T>:: LfindRSort(nodoD<T> *&nodo,T dato)
{
    if(nodo)
    {
        if(dato < nodo->getDato())
            return false;
        if(nodo->getDato()==dato)
            return true;
        else
        {
            nodo=nodo->get_Nnext();
            return  LfindRSort(nodo,dato);
        }
    }
    return false;
}

template <typename T>
void ListD<T>::LaddRSort (T dato)
{
    if(m_begin)
    {
        if(m_begin->getDato()>=dato)
        {
            this->LpushFront(dato);
            return;
        }
        nodoD<T> *it=m_begin;
        if(LfindRSort(it,dato)+1 and it)
        {
            nodoD<T> *ptr_new=new nodoD<T>(dato);
            ptr_new->set_Nnext(it);
            ptr_new->set_Nprev(it->get_Nprev());
            it->get_Nprev()->set_Nnext(ptr_new);
            it->set_Nprev(ptr_new);
            return;
        }
        else
            this->LpushBack(dato);
    }
    return;
}

template<typename T>
T ListD<T>:: Lmax()
{
    if(m_begin)
    {
        T dato_temp=m_begin->getDato();
        nodoD<T> *it=m_begin;
        while(it)
        {
            if(it->getDato()>dato_temp)
                dato_temp=it->getDato();
            it=it->get_Nnext();
        }
        return dato_temp;
    }
    return NULL;
}


template<typename T>
int ListD<T>:: Lcount(T dato)
{
    int count=0;
    if(m_begin)
    {
        nodoD<T> *it=m_begin;
        while(it)
        {
            if(dato == it->getDato())
                count++;
            it=it->get_Nnext();
        }
    }
    return count;
}


template<typename T>
int ListD<T>:: Lsize()
{
    int count=0;
    if(m_begin)
    {
        nodoD<T> *it=m_begin;
        while(it)
        {
            count++;
            it=it->get_Nnext();
        }
    }
    return count;
}


template<typename T>
ListD<T>* ListD<T>:: Linter(ListD <T>* lista)
{

    ListD<T> *new_list=new ListD<T>;
    if(m_begin)
    {
        nodoD<T> *it=m_begin;
        while(it)
        {
            if(! new_list->LfindR(it->getDato()) && lista->LfindR(it->getDato()))
                new_list->LpushBack(it->getDato());
            it=it->get_Nnext();
        }
    }
    return new_list;
}

template<typename T>
ListD<T>* ListD<T>:: Ljoin(ListD<T>* lista)
{
    ListD<T> *new_list=new ListD<T>;
    if(m_begin)
    {
        nodoD<T> *it=m_begin;
        while(it)
        {
            new_list->LpushBack(it->getDato());
            it=it->get_Nnext();
        }
    }
    if(lista->m_begin)
    {
        nodoD<T> *it=lista->m_begin;
        while(it)
        {
            if(! new_list->LfindR(it->getDato()))
                new_list->LpushBack(it->getDato());
            it=it->get_Nnext();
        }
    }
    return new_list;
}

template<typename T>
void ListD<T>:: Lreverse()
{
    if(m_begin->get_Nnext())
    {
        nodoD<T> *it1=m_begin,
                 *it2=m_last;

        for(int i=0; i < this->Lsize()/2;i++)
        {
            T temp=it1->getDato();
            it1->set_dat(it2->getDato());
            it2->set_dat(temp);
            it1=it1->get_Nnext();
            it2=it2->get_Nprev();
        }

    }
}


template <typename T>
ListD<T> * ListD<T>::operator +(ListD<T> & lista)
{
    ListD<T> * new_list=new ListD<T>;
    if(m_begin)
    {
        nodoD<T> *it=m_begin;
        while(it)
        {
            if(! new_list->LfindR(it->getDato()))
                new_list->LpushBack(it->getDato());
            it=it->get_Nnext();
        }
    }
    if(lista.m_begin)
    {
        nodoD<T> *it=lista.m_begin;
        while(it)
        {
            if(! new_list->LfindR(it->getDato()))
                new_list->LpushBack(it->getDato());
            it=it->get_Nnext();
        }
    }
    return new_list;

}
template <typename T>
ListD<T> *ListD<T>::operator -(ListD<T> & lista)
{
    ListD<T> * new_list=new ListD<T>;
    if(m_begin)
    {
        nodoD<T> *it=m_begin;
        while(it)
        {

            if(! new_list->LfindR(it->getDato()) && lista.LfindR(it->getDato()))
                new_list->LpushBack(it->getDato());
            it=it->get_Nnext();
        }
    }
    return new_list;
}
template<typename T>
ListD<T> & ListD<T>::operator >>(T d)
{
        this->LpushBack(d);
    return *this;
}

