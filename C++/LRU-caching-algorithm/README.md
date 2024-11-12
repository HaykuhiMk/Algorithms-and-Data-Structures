# LRU Caching Algorithm
This repository contains the implementation of the Least Recently Used (LRU) Caching Algorithm in C++. The LRU caching algorithm is a popular cache 
replacement policy that removes the least recently used item from the cache when the cache reaches its maximum capacity and a new item needs to be inserted.

## Introduction
The LRU Caching Algorithm is designed to improve the efficiency of a cache by keeping the most recently accessed items at the front and evicting the least 
recently used items when the cache becomes full. It uses a combination of a doubly linked list and an unordered map to achieve constant-time insertion,
deletion, and lookup operations.

