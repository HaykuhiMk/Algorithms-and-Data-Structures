#include <iostream>
#include "lfu.h"

int main() 
{
    LFUCache cache(4);
    cache.put(1);
    cache.put(2);
    cache.put(3);
    cache.put(4);
    int key1 = 2;
    int key2 = 5;
    int currFrequency1 = cache.get(key1); 
    int currFrequency2 = cache.get(key2);
    std::cout << "Current Frequency for key " << key1 << ": " << currFrequency1 << std::endl;
    std::cout << "Current Frequency for key " << key2 << ": " << currFrequency2 << std::endl;
    cache.printCache();
    cache.put(5);
    cache.put(6);
    int key3 = 6;
    int key4 = 2;
    int currFrequency3 = cache.get(key3);
    int currFrequency4 = cache.get(key4);
    std::cout << "Current Frequency for key " << key3 << ": " << currFrequency3 << std::endl;
    std::cout << "Current Frequency for key " << key4 << ": " << currFrequency4 << std::endl;
    std::cout << "Cache contents after operations:" << std::endl;
    cache.printCache();
    return 0;
}
