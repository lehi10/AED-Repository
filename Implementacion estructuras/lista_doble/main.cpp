#include <iostream>
#include <list>
#include "listd.h"
using namespace std;

int main()
{
    ListD<int> asd,asd1;
    asd>>0>>3>>4>>5;
    asd.print();

    asd1>>1>>2>>3>>4>>5>>6;
    asd1.print();

    auto lista=asd1+asd;
    lista->print();

    auto lista2=asd1-asd;
    lista2->print();
    return 0;
}

