#ifndef LISTD_H
#define LISTD_H
#include "nodo.h"
#include <thread>
#include <fstream>
#include <cctype>

using namespace std;


struct Reg
{
    string index_w;
    int pos_i;
    int pos_f;
};


template<typename T>
class ListD
{
    public:

        ListD():m_begin(nullptr),m_last(nullptr){}
        int Lsize();                // !
        void print();               // !
        void killme();              // !
        void LpushFront(T dato);    // !
        void LpushBack(T dato);     // !
        bool LfindR(T dato);        // !
        bool Lfind(T dato);         // !
        void reverse();             // !
        void sort();                // !
        ListD<T>* operator +(ListD<T> & lista); // !
        ListD<T>*operator -(ListD<T> & lista);  // !
        ListD<T> & operator >>(T d);  // !
        T operator[] (int p);

// funciones para el registro
        Reg *add_def(string file,string word,string def);
        string index(string file,int ini);
//---------------------------------
        friend ostream  & operator <<(ostream & os,ListD<T> & A)
        {
            nodoD<T>  * p = A.m_begin;
            for( ; p;p=p->get_Nnext() )
                os<<*p<<endl;
            return os;
        }

   // private:

        bool LfindRSort(nodoD<T> *&nodo,T dato);
        bool  LfindR(nodoD<T> *&nodo,T dato);
        nodoD<T> *m_begin;
        nodoD<T> *m_last;
        int m_size;
};
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

template <typename T>
T  ListD<T>::operator[] (int p)
{
    if(m_begin && p <= this->Lsize())
    {
        nodoD<T> *it=m_begin;
        for(int i=0;i<p;i++)
            it=it->get_Nnext();
        return it->getDato();
    }
    return 0;
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

template<typename T>
void ListD<T>::sort()
{
    for(int i=0;i<this->Lsize();i++)
    {
        nodoD<T> *it=m_begin;
        while(it->get_Nnext())
        {
            if(it->getDato() > it->get_Nnext()->getDato())
            {
                T temp= it->getDato();
                it->set_dat(it->get_Nnext()->getDato());
                it->get_Nnext()->set_dat(temp);
            }
            it=it->get_Nnext();
        }
    }
}

template <typename T>
bool ListD<T>::Lfind(T dato)
{
    if(m_begin)
    {
        nodoD<T>*it1=m_begin,
                *it2=m_last;

        while(it2->get_Nnext()!= it1)
        {
            if(it1->getDato()==dato or it2->getDato()==dato)
                return true;
            it1=it1->get_Nnext();
            it2=it2->get_Nprev();
        }
    }
    return false;
}

template<typename T>
void ListD<T>::reverse()
{
    if(m_begin->get_Nnext())
    {
        nodoD<T>*it1=m_begin,
                *it2=m_last;

        for(int i=0;i<Lsize()/2;i++)
        {
            T temp=it1->getDato();
            it1->set_dat(it2->getDato());
            it2->set_dat(temp);

            it1=it1->get_Nnext();
            it2=it2->get_Nprev();
        }
    }
}

template <typename T >
string ListD<T>::index(string file,int ini)
{
    FILE * pFile;
    char my_string[100];
    pFile = fopen ( file.c_str() , "rb" );
    /*
    for(int i=0;!feof(pFile);i+=37)
    {
        fseek ( pFile ,i,0 );
        fgets(my_string,37,pFile);
        cout<<my_string<<endl;
    }*/

    fseek ( pFile ,ini,0 );
    fgets(my_string,100,pFile);
    fclose ( pFile );
    return my_string;
}


template <typename T>
Reg * ListD<T>::add_def(string file,string word,string def)
{
    FILE * pFile,*loadFile;
    long size;
    pFile = fopen ( file.c_str() , "a+" );
    loadFile= fopen("load.txt","a+");
    fseek (pFile, 0, SEEK_END);
    size=ftell (pFile);
    fputs((word+" :"+def).append("\n").c_str(),pFile);

    fputs((to_string(size)+ " "+word.append("\n")).c_str(),loadFile);

    Reg *new_reg=new Reg;
    new_reg->pos_i=size;
    new_reg->index_w=word;
    fclose(loadFile);
    fclose ( pFile );
    return new_reg;
}

#endif // LISTD_H
