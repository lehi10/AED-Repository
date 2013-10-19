#include <iostream>
#include "binaryHeap.h"
#include <math.h>
using namespace std;

int main()
{
    binaryHeap<int> heaps;
    cout<<pow(2,12)<<endl;
    for(int i=0;i<100;i++)
       heaps.insert(i);
    heaps.printIn(heaps.root);
    heaps.generarDot("new2");
    return 0;
}

