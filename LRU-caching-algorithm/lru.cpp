// We can use stl container list as a double
// ended queue to store the cache keys, with
// the descending time of reference from front
// to back and a set container to check presence
// of a key. But to fetch the address of the key
// in the list using find(), it takes O(N) time.
// This can be optimized by storing a reference
//	 (iterator) to each key in a hash map.
#include "lru.h"

LRUCache::LRUCache(int n) { capacity = n; }

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

