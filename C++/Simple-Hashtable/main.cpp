#include <iostream>
#include <string>
#include "hashtable.h"

int main() 
{
    Hashtable ht;
    ht.insert("John");
    ht.insert("Stive");
    ht.insert("Sam");
    ht.insert("Harry");
    ht.insert("Egor");
    std::cout << "Hashtable contents:" << std::endl;
    ht.print();
    return 0;
}
