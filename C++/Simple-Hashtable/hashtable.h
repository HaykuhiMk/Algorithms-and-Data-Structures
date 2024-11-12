#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <string>

class Hashtable
{
public:
    int hash(const std::string&);
    void insert(const std::string&);
    void print();

private:
    std::vector<std::string> mData; 
};

#endif  //HASHTABLE_H
