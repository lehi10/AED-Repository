#ifndef NODOB_H
#define NODOB_H

template<typename T>
class nodoB
{
public:
    nodoB();
    nodoB(T dato):m_dato(dato),ptr_hermano(nullptr),ptr_padre(nullptr),ptr_hijo(nullptr),m_grado(0){}

//private:
    nodoB<T> *ptr_padre;
    nodoB<T> *ptr_hijo;
    nodoB<T> *ptr_hermano;

    T m_dato;
    int m_grado;

};

#endif // NODOB_H
