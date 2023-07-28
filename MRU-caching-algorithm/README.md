# MRU Caching Algorithm
This repository contains an implementation of the Most Recently Used (MRU) caching algorithm in C++. The MRU caching algorithm keeps track of the most recently 
accessed items and removes the most recently used item when the cache is full and a new item needs to be added.

## How the MRU Caching Algorithm Works
The MRU caching algorithm operates on the principle that the most recently accessed items are likely to be accessed again soon. It maintains a cache with a 
fixed capacity, and when a new item is accessed or added, it is moved to the front of the cache (i.e., it becomes the most recently used item). When the cache is 
full and a new item needs to be added, the least recently used item is removed from the cache.

