#include <iostream>
#include "mru.h"

int main() 
{
    MRUCache cache(3); 
    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);
    cache.put(4, 40);
    cache.put(5, 50);
    cache.display();
    return 0;
}
