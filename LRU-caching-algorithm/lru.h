#ifndef LRU_H
#define LRU_H

#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache 
{
public:
	LRUCache(int);
	void refer(int);
	void display();

private:
	// store keys of cache
	std::list<int> recent;
	// store references of key in cache
	std::unordered_map<int, std::list<int>::iterator> cache;
    // maximum capacity of cache
	int capacity; 

};

#endif  //LRU_H