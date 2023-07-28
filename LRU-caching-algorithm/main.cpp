#include <iostream>
#include "lru.h"

int main()
{
	LRUCache cache(4);
	cache.refer(1);
	cache.refer(2);
	cache.refer(3);
	cache.refer(1);
	cache.refer(4);
	cache.refer(5);
	cache.display();
	return 0;
}

