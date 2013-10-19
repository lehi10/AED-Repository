#ifndef NODOHEAP_H
#define NODOHEAP_H

template <typename T>

class nodoHeap
{
public:
    nodoHeap(T _dato_):m_dato (_dato_),m_padre(nullptr){hijos[0] =nullptr; hijos[1]=nullptr;}
    bool nodo_incompleto(){ return  ! hijos[0] or ! hijos[1] ?true:false;}
    bool es_hijo_der()
    {
        if(this->m_padre)
            if(this->m_padre->hijos[1] == this)
                return true;
        return false;
    }


    T m_dato;
    nodoHeap<T>  * m_padre;
    nodoHeap *hijos[2]={m_hijo_iz,m_hijo_de};
    bool complete;
private:

    nodoHeap<T>  * m_hijo_de;
    nodoHeap<T>  * m_hijo_iz;




 };


#endif // NODOHEAP_H
