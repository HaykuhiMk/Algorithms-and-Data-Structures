#include "mru.h"

MRUCache::MRUCache(int cap) : capacity(cap) {}

int MRUCache::get(int key) 
{
    if (cache.find(key) != cache.end()) {
        int value = *cache[key];
        recent.erase(cache[key]);
        recent.push_front(key);
        cache[key] = recent.begin();
        return value;
        }
        return -1; 
}

void MRUCache::put(int key, int value) 
{
    if (cache.find(key) != cache.end()) {
            recent.erase(cache[key]);
        }
        else {
            // If the cache is full, remove the MRU element
            if (cache.size() >= capacity) {
                int mruKey = recent.back();
                recent.pop_back();
                cache.erase(mruKey);
            }
        }
        // Update the cache with the new key and value
        recent.push_front(key);
        cache[key] = recent.begin();
}

void MRUCache::display() 
{
    for (int key : recent) {
        std::cout << key << " ";
    }
    std::cout << std::endl;
}

