#include <iostream>
#include <binomialHeap.h>
#include <algorithm>
using namespace std;

int main()
{
    binomialHeap<int> heap;
    for(int i=0;i<100;i++)
        heap.insert(i);

    heap.print();
    heap.generarDot("new2");
    return 0;
}

