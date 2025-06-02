
#include <iostream>
#include "NumberList.h"

int main() {
    
    NumberList list;
 
    list.Init();
    std::cout << "List initialized." << std::endl;

    list.Add(5);
    list.Add(3);
    list.Add(8);
    list.Add(1);
    list.Add(9);

    list.Print();

    list.Sort();
    std::cout << "List sorted." << std::endl;

    list.Print();

    list.Add(7); 
    list.Add(4); 
    list.Add(6);
    list.Add(2); 
    list.Add(10); 
    list.Add(11); 
    list.Print();

    return 0;
}
