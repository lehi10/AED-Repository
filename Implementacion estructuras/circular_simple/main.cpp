#include <iostream>
#include "listcs.h"

using namespace std;

int main()
{
    ListCS<int> asd;
    asd.Lpush_back(1);
    asd.Lpush_back(2);
    asd.Lpush_front(0);
    asd.print();

    return 0;
}

