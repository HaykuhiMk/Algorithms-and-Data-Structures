#ifndef LFU_H
#define LFU_H

#include <iostream>
#include <unordered_map>
#include <list>

class LFUCache 
{

public:
    LFUCache(int cap);
    int get(int key);
    void put(int key);
    void printCache();

private:
    void updateFrequency(int key);
    void evictLFU();

private:
    int capacity;
    int minFrequency;
    //Key-value and frequency map
    std::unordered_map<int, int> cache;  
    //Frequency and linked list of keys    
    std::unordered_map<int, std::list<int>> frequency;       

};

#endif  //LFU_H