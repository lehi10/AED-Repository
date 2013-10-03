#include <iostream>
#include <list>
#include "list_cirdo.h"
using namespace std;

int main()
{
    list_cirdo<int> lista,lista1;
    lista1.pushback(1);
    lista1.pushback(2);
    lista1.pushback(4);
    lista1.pushback(5);
    lista1.pushback(7);

    lista1.print();
    cout<<"------------"<<endl;
    lista.pushback(1);
    lista.add_recursive(2);
    lista.add_recursive(4);
    lista.add_recursive(9);
    lista.add_recursive(45);
    lista.add_recursive(76);
    lista.add_recursive(87);
    lista.print();

    cout<<"------------"<<endl;
    lista.unionL(&lista1);
    lista.print();

    return 0;
}

