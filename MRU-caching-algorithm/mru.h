#ifndef MRU_H
#define MRU_H

#include <iostream>
#include <list>
#include <unordered_map>

class MRUCache 
{
public:
	MRUCache(int);
	int get(int);
	void put(int, int);
	void display();

private:
	// store keys of cache
	std::list<int> recent;
	// store references of key in cache
	std::unordered_map<int, std::list<int>::iterator> cache;
    // maximum capacity of cache
	int capacity; 

};

#endif  //MRU_H