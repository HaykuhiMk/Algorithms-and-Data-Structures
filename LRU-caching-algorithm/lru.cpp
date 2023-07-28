#include "lru.h"

LRUCache::LRUCache(int cap) { capacity = cap; }

// Refers key x with in the LRU cache
void LRUCache::refer(int x)
{
	if (cache.find(x) == cache.end()) {
		if (recent.size() == capacity) {
			int last = recent.back();
			recent.pop_back();
			cache.erase(last);
		}
	}
	else {
		recent.erase(cache[x]);
	}
	recent.push_front(x);
	cache[x] = recent.begin();
}

// Function to display contents of cache
void LRUCache::display()
{
	for (auto it = recent.begin(); it != recent.end(); it++) {
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
}

