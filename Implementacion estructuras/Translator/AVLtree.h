#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <math.h>

template <typename T>
class AVLnodo
{
    public:
            AVLnodo(T dato):m_dato(dato),altura(0){hijos[0]=nullptr;hijos[1]=nullptr;}
            T m_dato;
            AVLnodo *hijo_d;
            AVLnodo *hijo_i;
            AVLnodo *hijos[2]={hijo_i,hijo_d};
            int altura;
};


using namespace std;
template <typename T>
class AVLtree
{
    public:
            AVLnodo<T> *m_head;

            AVLtree():m_head(nullptr){}
            bool find(T d,AVLnodo<T> ** &p );
            bool add(T dato);
            AVLtree<T> &  operator <<(T dato);
            void printIn(AVLnodo<T> * nodo);
            void printPos(AVLnodo<T> * nodo);
            void printPre(AVLnodo<T> * nodo);
            void insert(AVLnodo<T> *nodo,T dato);
            void insert(T dato);
            void print();

            int nivel_nodo(T dato);
            int altura_arbol();
            int altura_arbol(AVLnodo<T> *nodo);
            T hermano(T dato);
            AVLnodo<T> *padre_n(T dato);
            T padre(T dato);
            T abuelo(T dato);

            void cant_nodos(AVLnodo<T> * nodo,int &cant);
            int cant_nodos();
            void cant_hojas(AVLnodo<T> * nodo,int &cant);
            int cant_hojas();
            T max();
            T min();
            void siguiente(AVLnodo<T> *nodo,T dato,int &flag);
            T siguiente2(T dato);
            AVLtree<T> * siguiete(AVLnodo<T> *nodo,T dato);
            T siguiente(T dato);
            T anterior(T dato);
            AVLtree<T> * inserseccion_t(AVLtree<T> *tree);
            void insertR(AVLtree<T> *& tree,AVLnodo<T> *nodo);
            void insertL(AVLtree<T> *&tree,AVLtree<T> *tree_index, AVLnodo<T> *nodo);
            AVLtree<T> * union_t(AVLtree<T> *tree);

            AVLnodo<T> * new_nodo (T dato, AVLnodo<T> * nodo_i, AVLnodo<T> * nodo_d);
            void Rsimple(AVLnodo<T> ** nodo,bool nodo_i );
            void actualizar_altura(AVLnodo<T> *nodo);
            int altura_avl(AVLnodo<T> *nodo);
            void Rdoble(AVLnodo<T> ** nodo,bool nodo_i);
            void balanceo(AVLnodo<T> ** nodo);
            void insertar_avl(AVLnodo<T> **t,T dato);
            void insertar_avl(T dato);
};

#endif // AVLTREE_H
template <typename T >
void AVLtree<T>::insert(AVLnodo<T> *temp,T dato)
{
    T temp_d=temp->m_dato;
    if(temp_d < dato)
    {
        if(temp->hijos[1])
            return insert(temp->hijos[1],dato);
        AVLnodo<T> *new_nodo=new AVLnodo<T>(dato);
        temp->hijos[1]=new_nodo;
        return;
    }
    if(temp_d > dato)
    {
        if(temp->hijos[0])
            return insert(temp->hijos[0],dato);
        AVLnodo<T> *new_nodo=new AVLnodo<T>(dato);
        temp->hijos[0]=new_nodo;
        return;
    }
}

template <typename T>
void AVLtree<T>::insert(T dato)
{
    if(m_head)
    {
        insert(m_head,dato);
        return;
    }
    m_head = new AVLnodo<T>(dato);
}

template <typename T>
bool AVLtree<T>::find(T d,AVLnodo<T> ** &p )
{
    p  =& m_head;
    while(*p)
    {
        if((*p)->m_dato== d)
            return true;
        p=&(*p)->hijos[(*p)->m_dato < d];
    }
    return false;
}

template <typename T>
bool AVLtree<T>::add(T dato)
{
    AVLnodo<T> **p;
    if(find (dato,p))
        return false;
    *p=new AVLnodo<T>(dato);

    return true;
}

template <typename T>
AVLtree<T> & AVLtree<T>:: operator <<(T dato)
{
    insertar_avl(dato);
    return *this;
}

template <typename T>
void AVLtree<T>::printIn(AVLnodo<T> * nodo)
{
    if(!nodo) return;
    printIn(nodo->hijos[0]);
    cout<<nodo->m_dato<<" ";
    printIn(nodo->hijos[1]);
}

template <typename T>
void AVLtree<T>::printPos(AVLnodo<T> * nodo)
{
    if(!nodo) return;
    printPos(nodo->hijos[0]);
    printPos(nodo->hijos[1]);
    cout<<nodo->m_dato<<" ";
}

template <typename T>
void AVLtree<T>::printPre(AVLnodo<T> * nodo)
{
    if(!nodo)
        return;

    cout<<"node"<<nodo->m_dato<< "[label =  \" <f0> | <f1>" << nodo->m_dato<<"| <f2>\"  ]; "<<endl;
    if(nodo->hijos[0])
        cout<<"\"node"<<nodo->m_dato<< "\":"<<"f0 ->  \"node"<<nodo->hijos[0]->m_dato<< "\":f1;"<<endl;
    if(nodo->hijos[1])
        cout<<"\"node"<<nodo->m_dato<< "\":"<<"f2 -> \"node"<<nodo->hijos[1]->m_dato<< "\":f1;"<<endl;
    printPre(nodo->hijos[0]);
    printPre(nodo->hijos[1]);

}

template<typename T>
int AVLtree<T>::nivel_nodo(T dato)
{
    int cont=0;
    AVLnodo<T> * temp=m_head;
    while(temp)
    {
        cont++;
        if(dato == temp->m_dato)
            return cont;
        temp=temp->hijos[temp->m_dato < dato];
    }
    return cont;
}

template<typename T>
int AVLtree<T>::altura_arbol(AVLnodo<T> *nodo)
{
    if(nodo == nullptr)
        return 0;
    return altura_arbol(nodo->hijos[0]) > altura_arbol(nodo->hijos[1])? altura_arbol(nodo->hijos[0]) +1 : altura_arbol(nodo->hijos[1])+1 ;
}

template<typename T>
int AVLtree<T>::altura_arbol()
{
    return altura_arbol(m_head);
}

template<typename T>
T AVLtree<T>::hermano(T dato)
{
    AVLnodo<T> *ptr_padre=padre_n(dato);
    if(ptr_padre)
    {
        if(dato > ptr_padre->m_dato)
            return ptr_padre->hijos[0]?ptr_padre->hijos[0]->m_dato:0;
        return ptr_padre->hijos[1]?ptr_padre->hijos[1]->m_dato:0;
    }
    return 0;
}



template<typename T>
AVLnodo<T> * AVLtree<T>::padre_n(T dato)
{
    AVLnodo<T> *temp=m_head;
    while(temp->hijos[0] || temp->hijos[1])
    {
        if(temp->hijos[0])
            if(temp->hijos[0]->m_dato==dato) return temp;
        if(temp->hijos[1])
            if(temp->hijos[1]->m_dato==dato) return temp;
        temp=temp->hijos[temp->m_dato < dato];
    }
    return nullptr;
}


template<typename T>
T AVLtree<T>::padre(T dato)
{
    AVLnodo<T> *ptr_padre=padre_n(dato);
    return ptr_padre ? ptr_padre->m_dato : 0;
}

template<typename T>
T AVLtree<T>::abuelo(T dato)
{
    return padre(padre(dato));
}

template<typename T>
void AVLtree<T>::cant_nodos(AVLnodo<T> * nodo,int & cant)
{
    if(nodo)
    {
        cant++;
        if(nodo->hijos[0]==nullptr && nodo->hijos[1]==nullptr)
            return;
        this->cant_nodos(nodo->hijos[0],cant);
        this->cant_nodos(nodo->hijos[1],cant);
    }
}

template<typename T>
int AVLtree<T>::cant_nodos()
{
    int a=0;
    cant_nodos(m_head,a);
    return a;
}

template<typename T>
void AVLtree<T>::cant_hojas(AVLnodo<T> * nodo,int & cant)
{
   if(nodo)
    {
        if(nodo->hijos[0]==nullptr && nodo->hijos[1]==nullptr)
        {
            cant++;
            return;
        }
        this->cant_hojas(nodo->hijos[0],cant);
        this->cant_hojas(nodo->hijos[1],cant);
    }
}


template<typename T>
int AVLtree<T>::cant_hojas()
{
    int a=0;
    cant_hojas(m_head,a);
    return a;
}

template<typename T>
T AVLtree<T>::max()
{
    if(m_head)
    {
        AVLnodo<T> *temp=m_head;
        while(temp->hijos[1])
            temp=temp->hijos[1];
        return temp->m_dato;
    }
    return 0;
}

template<typename T>
T AVLtree<T>::min()
{
    if(m_head)
    {
        AVLnodo<T> *temp=m_head;
        while(temp->hijos[0])
            temp=temp->hijos[0];
        return temp->m_dato;
    }
    return 0;
}

template<typename T>
void AVLtree<T>::siguiente(AVLnodo<T> * nodo, T dato, int & flag)
{
    if(!nodo)
        return ;
    siguiente(nodo->hijos[0],dato,flag);
    if(flag == 1)
        throw nodo;
    if(nodo->m_dato == dato)
        flag++;
    siguiente(nodo->hijos[1],dato,flag);
}

template<typename T>
T AVLtree<T>::siguiente(T dato)
{
    AVLnodo<T> **nodo= & m_head;
    if(find(dato, nodo))
    {
        if((*nodo)->hijos[1])
        {
            AVLnodo<T> *temp=(*nodo)->hijos[1];
            while(temp->hijos[0])
                temp=temp->hijos[0];
            return temp->m_dato;
        }
        if(max()==dato) return 0;
        while(dato >= (*nodo)->m_dato)
            *nodo=padre_n((*nodo)->m_dato);
        return (*nodo)->m_dato;
    }
    return 0;
}

// tambien funcicnoa

template<typename T>
T AVLtree<T>::siguiente2(T dato)
{
    int flag=0;
    try
    {
        siguiente(m_head,dato,flag);
    }
    catch(AVLnodo<T> *nodo)
    {
        return nodo->m_dato;
    }
    return 0;
}


template<typename T>
T AVLtree<T>::anterior(T dato)
{
    AVLnodo<T> **nodo= & m_head;
    if(find(dato, nodo))
    {
        if((*nodo)->hijos[0])
        {
            AVLnodo<T> *temp=(*nodo)->hijos[0];
            while(temp->hijos[1])
                temp=temp->hijos[1];
            return temp->m_dato;
        }
        if(min()==dato)
            return 0;
        while(dato <= (*nodo)->m_dato)
        {
            *nodo= this->padre_n((*nodo)->m_dato);
        }
        return (*nodo)->m_dato;
    }
    return 0;
}

template<typename T>
void AVLtree<T>::insertR(AVLtree<T> *&tree, AVLnodo<T> *nodo)
{
    if(!nodo)
        return;
    (*tree) << nodo->m_dato;
    insertR(tree,nodo->hijos[0]);
    insertR(tree,nodo->hijos[1]);
}

template<typename T>
void AVLtree<T>::insertL(AVLtree<T> *&tree,AVLtree<T> *tree_index, AVLnodo<T> *nodo)
{
    if(!nodo)
        return;
    AVLnodo<T> **ptr_nodo;
    if(tree_index->find(nodo->m_dato,ptr_nodo))
        (*tree) << nodo->m_dato;
    insertL(tree,this,nodo->hijos[0]);
    insertL(tree,this,nodo->hijos[1]);
}


template<typename T>
AVLtree<T> * AVLtree<T>::inserseccion_t(AVLtree<T> *tree)
{
    AVLtree<T> *new_tree=new AVLtree<T>;
    insertL(new_tree,this,tree->m_head);
    return new_tree;
}

template<typename T>
AVLtree<T> * AVLtree<T>::union_t(AVLtree<T> *tree)
{
    AVLtree<T> *new_tree=new AVLtree<T>;

    insertR(new_tree,tree->m_head);
    insertR(new_tree,this->m_head);
    return new_tree;
}

//                   Funciones Arbol AVL
//--------------------------------------------------


template<typename T>
AVLnodo<T> * AVLtree<T>::new_nodo (T dato, AVLnodo<T> * nodo_izq, AVLnodo<T> * nodo_der)
{
    AVLnodo<T> * ptr_new_nodo = new AVLnodo<T>(dato);
    ptr_new_nodo->hijos[0]=nodo_izq;
    ptr_new_nodo->hijos[1]=nodo_der;
    return ptr_new_nodo;
}

template<typename T>
int AVLtree<T>::altura_avl(AVLnodo<T> *nodo)
{
    return nodo ? nodo->altura : -1 ;
}

template<typename T>
void AVLtree<T>::actualizar_altura(AVLnodo<T> *nodo)
{
    if(nodo)
        nodo->altura = altura_avl(nodo->hijos[0]) >altura_avl(nodo->hijos[1]) ? altura_avl(nodo->hijos[0])+1 : altura_avl(nodo->hijos[1])+1;
}

template<typename T>
void AVLtree<T>::Rsimple(AVLnodo<T> ** nodo,bool nodo_i )
{
    AVLnodo<T> *temp;
    temp=(*nodo)->hijos[! nodo_i];
    (*nodo)->hijos[! nodo_i]=temp->hijos[nodo_i];
    temp->hijos[nodo_i]=*nodo;
    actualizar_altura(*nodo);
    actualizar_altura(temp);
    *nodo=temp;
}

template <typename T>
void AVLtree<T>::Rdoble(AVLnodo<T> ** nodo,bool nodo_i)
{
    Rsimple(&(*nodo)->hijos[!nodo_i] , !nodo_i);
    Rsimple(nodo,nodo_i);
}

template <typename T>
void AVLtree<T>::balanceo(AVLnodo<T> **nodo)
{
    if(nodo)
    {
        if(altura_avl((*nodo)->hijos[0])  -  altura_avl((*nodo)->hijos[1]) == 2)
        {
            if(altura_avl((*nodo)->hijos[0]->hijos[0]) >= altura_avl((*nodo)->hijos[0]->hijos[1]))
                Rsimple(nodo,true);
            else
                Rdoble(nodo,true);
        }
        else
        if(altura_avl((*nodo)->hijos[1]) - altura_avl((*nodo)->hijos[0])==2)
        {
            if(altura_avl((*nodo)->hijos[1]->hijos[0]) <= altura_avl((*nodo)->hijos[1]->hijos[1]))
                Rsimple(nodo,false);
            else
                Rdoble(nodo,false);
        }
    }
}

template<typename T>
void AVLtree<T>::insertar_avl(AVLnodo<T> **nodo,T dato)
{
    if (! (*nodo))
        *nodo = new AVLnodo<T>(dato);
    else
    {
        insertar_avl(&(*nodo)->hijos[dato > (*nodo)->m_dato],dato);
        balanceo (nodo);
        actualizar_altura (*nodo);
    }
}


template<typename T>
void AVLtree<T>::insertar_avl(T dato)
{
    insertar_avl(&m_head,dato);
}
