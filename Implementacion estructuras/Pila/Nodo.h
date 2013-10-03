#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo
{
    public:
        Nodo(T dato):m_dato(dato),m_prev(nullptr){}
        void set_prev(Nodo<T> *nodoP){m_prev=nodoP;}
        void set_dato(T dato){m_dato=dato;}
        Nodo<T> * get_prev(){return m_prev;}
        T get_dato(){return m_dato;}

    private:
        T m_dato;
        Nodo<T> * m_prev;

};
#endif // NODO_H
