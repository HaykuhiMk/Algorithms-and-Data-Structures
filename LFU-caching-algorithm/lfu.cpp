#include "lfu.h"

LFUCache::LFUCache(int cap) 
{
    this->capacity = cap;
    this->minFrequency = 0;
}

// Get the value of a key from the cache
int LFUCache::get(int key) 
{
    if (cache.find(key) != cache.end()) {
        updateFrequency(key);
        return cache[key];
    }
    return -1; 
}

// Put a key-value pair into the cache
void LFUCache::put(int key) 
{
    if (capacity == 0) return;
    if (cache.find(key) != cache.end()) {
        cache[key] = 1;
        updateFrequency(key);
    } 
    else {
        if (cache.size() >= capacity) {
            evictLFU(); // Evict the least frequently used item if the cache is full
        }
        cache[key] = 1;
        frequency[1].push_front(key);
        minFrequency = 1;
    }
}

// Print the elements in the cache (for debugging purposes)
void LFUCache::printCache() 
{
    for (const auto& keyValuePair : cache) {
        std::cout << "Key: " << keyValuePair.first << ", Value: " << keyValuePair.second << std::endl;
    }
}

// Update the frequency of a key and reorganize the frequency
void LFUCache::updateFrequency(int key) 
{
    int currFrequency = cache[key];
    frequency[currFrequency].remove(key);
    if (frequency[currFrequency].empty() && currFrequency == minFrequency) {
        minFrequency++;
    }
    cache[key]++;
    frequency[cache[key]].push_front(key);
}

// Evict the least frequently used item from the cache
void LFUCache::evictLFU() 
{
    std::list<int>& frequencyList = frequency[minFrequency];
    int keyToRemove = frequencyList.back();
    cache.erase(keyToRemove);
    frequencyList.pop_back();
}
