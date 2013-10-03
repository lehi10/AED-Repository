#ifndef LIST_CIRDO_H
#define LIST_CIRDO_H
#include "nodoc.h"
#include <iostream>
using namespace std;


template <typename T>
class list_cirdo
{
    public:
        list_cirdo():m_begin(nullptr),m_last(nullptr){}

        void print();
        void printC();

        void pushfrom (T dato);
        void pushback (T dato);
        void removefrom ();
        void removeback ();
        void remove (T dato);
        void add_recursive(T dato);
        bool find_recursive(nodoc<T> *& nodo ,T dato,bool &flag);
        T max();
        void reverse();
        int contar_lista();
        int contar_some(T dato);
        list_cirdo<T> *interseccion(list_cirdo<T> * lista);
        list_cirdo<T> *unionL (list_cirdo<T> * lista);

private:
    nodoc <T> * m_begin;
    nodoc <T> * m_last;

};

#endif // LIST_CIRDO_H


template <typename T>
void list_cirdo<T>::print()
{
    if(m_begin)
    {
        int flag=true;
        nodoc<T> *it=m_begin;
        while(flag == true )
        {
            if(it==m_last)
                flag=false;
            cout<<it->getDato()<<" ";
            it=it->get_Next();
        }
        cout<<endl;
        cout <<this-> m_begin->getDato()<< endl;
        cout<<this->m_last->getDato()<<endl;
    }
}

template <typename T>
void list_cirdo<T>::printC()
{
    if(m_begin)
    {
        nodoc<T> *it=m_begin;
        while(it)
        {
            cout<<it->getDato()<<" ";
            it=it->get_Next();

        }
    }

}


template <typename T>
void list_cirdo<T>::pushfrom(T dato)
{
    if(m_begin)
    {
        nodoc <T> *Newptr = new nodoc <T> (dato);
        Newptr -> set_next(m_begin);
        Newptr->set_prev(m_last);
        m_begin -> set_prev(Newptr);
        m_last->set_next(Newptr);
        m_begin=Newptr;

        return;
     }
     nodoc<T> *Newptr= new nodoc<T>(dato);
     m_last=Newptr;
     m_begin=Newptr;
     Newptr->set_next(Newptr);
     Newptr->set_prev(Newptr);

}

template <typename T>
void list_cirdo<T>::pushback(T dato)
{
    if(m_begin)
    {
        nodoc <T> *Newptr = new nodoc <T> (dato);
        Newptr -> set_next(m_begin);
        Newptr->set_prev(m_last);
        m_begin -> set_prev(Newptr);
        m_last->set_next(Newptr);
        m_last=Newptr;
        return;
  }
    nodoc<T> *Newptr= new nodoc<T>(dato);
    m_last=Newptr;
    m_begin=Newptr;
    Newptr->set_next(Newptr);
    Newptr->set_prev(Newptr);
}

template <typename T>

void list_cirdo<T>::removefrom()
{
    if(m_begin != m_last)
    {
        m_begin= m_begin->get_Next();
        delete m_begin->get_Prev();
        m_last->set_next(m_begin);
        m_begin->set_prev(m_last);
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
void list_cirdo<T>::removeback()
{
    if(m_begin != m_last)
    {
        m_last= m_last->get_Prev();
        delete m_begin->get_Prev();
        m_last->set_next(m_begin);
        m_begin->set_prev(m_last);
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

void list_cirdo<T>::remove(T dato)
{
    if(m_begin)
    {
        if(m_begin->getDato()==dato)
        {

            this->removefrom();
            return;
        }
        if(m_last->getDato()==dato)
        {
            this->removeback();
            return;
        }
        int flag=true;
        nodoc<T> *it=m_begin;

        while(flag == true )
        {
            if(it==m_last)
                flag=false;
            if(dato == it->getDato())
            {
                it->get_Prev()->set_next(it->get_Next());
                it->get_Next()->set_prev(it->get_Prev());
                delete it;
                return;
            }
            it=it->get_Next();
        }
    }
}
template<typename T>
void list_cirdo<T>::add_recursive(T dato)
{
    if(m_begin)
    {
        if(dato<= m_begin->getDato())
        {
            this->pushfrom(dato);
        }
        nodoc<T> *it=m_begin;
        bool flag=true;
        if(find_recursive(it,dato,flag)+1 )
        {
            if(flag==false)
            {
                this->pushback(dato);
                return;
            }
            nodoc<T> *ptr_new=new nodoc<T>(dato);
            ptr_new->set_NP(it->get_Prev(),it);
            it->set_prev(ptr_new);
            ptr_new->get_Prev()->set_next(ptr_new);
            return;
        }

    }
}

template <typename T>
bool list_cirdo<T>::find_recursive(nodoc<T> *&nodo,T dato,bool &flag)
{
    if (flag==false)
        return false;
    if(nodo->getDato()==dato)
        return true;
    if(nodo->getDato() > dato)
        return false;
    if(nodo == m_last)
        flag=false;
    nodo=nodo->get_Next();
    return find_recursive(nodo,dato,flag);
}

template <typename T>
T list_cirdo<T>::max()
{
    if(m_begin)
    {
        T temp=m_begin->getDato();
        int flag=true;
        nodoc<T> *it=m_begin;
        while(flag == true )
        {
            if(it->getDato() > temp)
                temp=it->getDato();
            if(it==m_last)
                flag=false;
            it=it->get_Next();
        }
        return temp;
    }
    return NULL;
}
template <typename T>
int list_cirdo<T>::contar_lista()
{
     int cont=0;
     if(m_begin)
     {
         int flag=true;
         nodoc<T> *it=m_begin;
         while(flag == true )
         {
             cont++;
             if(it==m_last)
                 flag=false;
             it=it->get_Next();
         }

     }
     return cont;
}

template <typename T>
int list_cirdo<T>::contar_some(T dato)
{
    int cont=0;
    if(m_begin)
    {
        int flag=true;
        nodoc<T> *it=m_begin;
        while(flag == true )
        {
            if(it->getDato()==dato)
                cont++;
            if(it==m_last)
                flag=false;
        it=it->get_Next();
        }
    }
    return cont;
}


template <typename T>
list_cirdo<T> * list_cirdo<T>::interseccion(list_cirdo<T> *lista)
{

}

template <typename T>
list_cirdo<T> * list_cirdo<T>:: unionL (list_cirdo<T> * lista)
{

    list_cirdo<T> *new_list=new list_cirdo<T>;
    if(m_begin)
    {
        nodoc<T> *it=m_begin;
        int flag=true;
        while(flag==true)
        {
            if(this->m_last)
                flag=false;
            new_list->pushback(it->getDato());
            it=it->get_Next();
        }
    }
    /*
    if(lista->m_begin)
    {
        nodoc<T> *it=lista->m_begin;
        nodoc<T> *it2;
        int flag=true;
        while(flag==true)
        {
            if(lista->m_last)
                flag=false;
            int flag1=true;
            if(! new_list->find_recursive(it2,it->getDato(),flag1))
                new_list->pushback(it->getDato());
            it=it->get_Next();
        }
    }
    return new_list;
    */
    ostream
}


template<typename T>
void list_cirdo<T>:: reverse()
{
    if(m_begin != m_last)
    {
        nodoc<T> *it1=m_begin,
                 *it2=m_last;

        for(int i=0; i < this->contar_lista()/2;i++)
        {
            T temp=it1->getDato();
            it1->setDato(it2->getDato());
            it2->setDato(temp);
            it1=it1->get_Next();
            it2=it2->get_Prev();
        }

    }
}
