#include <iostream>
#include "class_list.h"
using namespace std;

typedef class_list<int> my_list;

int main()
{
    my_list List;
    for(int i=1;i<=10;i++)
        List.Lpush_back(i);

    List.remove(5);
    List.print();
    List.insert_rec(-123);
    List.print();

     return 0;
}
