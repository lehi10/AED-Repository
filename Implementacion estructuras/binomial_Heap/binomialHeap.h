#ifndef BINOMIALHEAP_H
#define BINOMIALHEAP_H
#include <list>
#include <iostream>
#include "nodoB.h"
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

template <typename T>
class binomialHeap
{
public:
    binomialHeap(){}
    void insert(T dato);
    void unionB (nodoB<T> * & it_1,nodoB<T> * & it_2);
    void print();
    void tree_dot(nodoB<T> *ptr_nodo,FILE * pfile);
    void generarDot(string nameFile);
    list<nodoB<T> *>  lista_nodos;

};


#endif // BINOMIALHEAP_H


template<typename T>
void binomialHeap<T>::insert(T dato)
{
    nodoB<T> *new_nodo=new nodoB<T>(dato);

    lista_nodos.push_front(new_nodo);
    new_nodo->m_grado++;
    if(lista_nodos.size()==1)   return ;

    auto  it_1=lista_nodos.begin();
    auto  it_2=lista_nodos.begin();
    it_2 ++;

    while(  (*it_1)->m_grado == (*it_2)->m_grado  )
    {
        unionB( *it_1,  *it_2);

        it_1=lista_nodos.begin();
        it_2=lista_nodos.begin();
        it_2 ++;
    }
}

template <typename T>
void binomialHeap<T>:: unionB(nodoB<T> * & it_1,nodoB<T> * & it_2)
{
    if(it_1->m_dato <  it_2->m_dato ) // poner igual ( <= )
    {
        nodoB<T> *temp=it_1;
        it_1=it_2;
        it_2=temp;
    }
    if(it_2->ptr_hijo)
        it_1->ptr_hermano=it_2->ptr_hijo;
    it_1->ptr_padre=it_2;
    it_2->ptr_hijo=it_1;
    it_2->m_grado++;
    lista_nodos.pop_front();
}

template <typename T>
void binomialHeap<T>:: print()
{

    for_each(lista_nodos.begin(),lista_nodos.end(),[this](nodoB<T> * ptr_nodo)
    {
        nodoB<T> *temp=ptr_nodo;
        cout<<temp->m_dato<< " : ";
        while(temp->ptr_hijo)
        {
            temp=temp->ptr_hijo;
            cout<<temp->m_dato<< "  ";
        }
        cout<<endl;
    });
}

template <typename T>
void binomialHeap<T>:: tree_dot(nodoB<T> *ptr_nodo,FILE * pfile)
{
    string temp_str;
    temp_str.append(to_string(ptr_nodo->ptr_padre->m_dato)).append(" -> ").append(to_string(ptr_nodo->m_dato)).append("; \n");
    fputs(temp_str.c_str(),pfile);

    if(ptr_nodo->ptr_hermano )
        tree_dot(ptr_nodo->ptr_hermano,pfile);

    if(ptr_nodo->ptr_hijo)
        tree_dot (ptr_nodo->ptr_hijo,pfile);
}

template <typename T>
void binomialHeap<T>::generarDot(string nameFile)
{
    FILE *pfile;
    string dir;
    dir.append("/home/d/").append(nameFile).append(".dot");

    pfile=fopen(dir.c_str(),"w");
    fputs("digraph tree { \n",pfile);

    for_each(lista_nodos.begin(),lista_nodos.end(),[this,&pfile](nodoB<T> *ptr_nodo)
    {
        string var_1;
        var_1.append(to_string(ptr_nodo->m_dato));
/*
         if(ptr_nodo->ptr_hijo)
           var_1.append("->").append(to_string(ptr_nodo->ptr_hijo->m_dato));
*/
         var_1.append(" ; \n ");
        fputs(var_1.c_str(),pfile);

        if(ptr_nodo->ptr_hijo)
                tree_dot(ptr_nodo->ptr_hijo,pfile);

    });

    fputs(" \n } ",pfile);
    fclose(pfile);
    cout<<dir<<endl;
}
