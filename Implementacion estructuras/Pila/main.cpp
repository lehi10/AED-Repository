#include <iostream>
#include "pila.h"
#include "cola.h"
using namespace std;

int main()
{

    cola<int> col;

    cout<<col.is_empty()<<endl;
    for(int i=10;i>0;i--)
        col.push_back(8);
    col.print();
    cout<<endl;

        col.pop();
      col.print();
        cout<<endl;


    return 0;
}
