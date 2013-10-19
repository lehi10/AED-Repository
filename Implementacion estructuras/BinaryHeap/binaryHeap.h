#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include "nodoHeap.h"
#include <iostream>
#include <cstdio>

using namespace std;

template <typename T>
class binaryHeap
{
public:
// Miembros dato :
    nodoHeap<T> * root;
    nodoHeap<T>* INS;
// funciones
    binaryHeap():root(nullptr),INS(nullptr){}
    void insert(T dato);
    void actualizar_INS();
    void dot_File(nodoHeap<T>* nodo,FILE *pfile);
    void  generarDot(string nameFile);
    void printIn(nodoHeap<T> * nodo);
    T get_raiz(){return root->m_dato;}
};

#endif // BINARYHEAP_H
template <typename T>
void binaryHeap<T>::actualizar_INS()
{
    while(INS->es_hijo_der())
        INS=INS->m_padre;
    if(INS ==root)
    {
        while(INS->hijos[0])
            INS=INS->hijos[0];
        return;
    }
    INS=INS->m_padre;
    INS=INS->hijos[1];
    while(INS->hijos[0])
        INS=INS->hijos[0];

}


template<typename T>
void  binaryHeap<T>::insert(T dato)
{
    if(! root)
    {
        root=new nodoHeap<T>(dato);
        INS=root;
        return;
    }
    if(INS->nodo_incompleto() )
    {
         nodoHeap<T> * nuevo_nodo=new nodoHeap<T>(dato);
         nuevo_nodo->m_padre=INS;
        INS->hijos[bool(INS->hijos[0])]=nuevo_nodo;
        nodoHeap<T> * temp=nuevo_nodo;
        while(temp ->m_padre && temp->m_padre->m_dato > temp->m_dato)
        {
            T dato_temp=temp->m_padre->m_dato;
            temp->m_padre->m_dato=temp->m_dato;
            temp->m_dato=dato_temp;
            temp=temp->m_padre;
        }
        if(INS->hijos[1])
            actualizar_INS();
    }

}


template <typename T>
void binaryHeap<T>::printIn(nodoHeap<T> * nodo)
{
    if(!nodo) return;
    printIn(nodo->hijos[0]);
    printIn(nodo->hijos[1]);
}


template <typename T>
void binaryHeap<T>::dot_File(nodoHeap<T>* nodo,FILE *pfile)
{
    if(!nodo)  return;

    string var_1,var_2,var_3;
    var_1.append("node").append(to_string(nodo->m_dato)).append( "[label =  \"<f0> | <f1>").append(to_string( nodo->m_dato)).append("| <f2>\"  ];  \n");
    fputs(var_1.c_str(),pfile);
    if(nodo->hijos[0])
    {
        var_2.append("\"node").append(to_string(nodo->m_dato)).append("\": f0 -> \"node").append(to_string(nodo->hijos[0]->m_dato)).append( "\":f1; \n");
        fputs(var_2.c_str(),pfile);
    }
    if(nodo->hijos[1])
    {
        var_3.append("\"node").append(to_string(nodo->m_dato)).append("\": f2 -> \"node").append(to_string(nodo->hijos[1]->m_dato)).append( "\":f1; \n");
        fputs(var_3.c_str(),pfile);
    }
    dot_File(nodo->hijos[0],pfile);
    dot_File(nodo->hijos[1],pfile);
}


template <typename T>
void binaryHeap<T>:: generarDot(string nameFile)
{

    FILE *pfile;
    string dir;
    dir.append("/home/d/").append(nameFile).append(".dot");
    pfile=fopen(dir.c_str(),"w");
    fputs("digraph tree { \n",pfile);
    fputs("node [shape =record , height =.1]; \n",pfile);
    dot_File(root ,pfile);
    fputs(" \n } ",pfile);
    fclose(pfile);
    cout<<dir<<endl;
}
