#ifndef NODOC_H
#define NODOC_H

template <typename T>

class nodoc
{
    private:
       T m_dato;
       nodoc<T> *m_Pnext;
       nodoc<T> *m_Prev;

    public:
        nodoc(T dato):m_dato(dato),m_Pnext(nullptr),m_Prev(nullptr){}
        void set_next(nodoc<T> *nodo){m_Pnext = nodo;}
        void set_prev(nodoc<T> *nodo){m_Prev = nodo;}
        void set_NP (nodoc<T> *nodoP,nodoc<T> *nodoN){m_Prev=nodoP;m_Pnext=nodoN;}
        T getDato(){return m_dato;}
        void setDato(T dato){m_dato=dato;}
        nodoc<T> * get_Prev(){return m_Prev;}
        nodoc<T> * get_Next(){return m_Pnext;}
};

#endif // NODOC_H
