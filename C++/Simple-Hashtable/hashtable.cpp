#include <iostream>
#include <string>
#include "hashtable.h"

int Hashtable::hash(const std::string& name)
{
    int sum = 0;
    for (int i = 0; i < name.length(); ++i)
    {
        sum += int(name[i]);
    }
    return sum;
}

void Hashtable::insert(const std::string& name)
{
    int ind = hash(name);
    if (ind >= mData.size())
    {
        mData.resize(ind + 1);
    }
    this->mData[ind] = name;
}

void Hashtable::print() 
{
    for (const std::string& item : mData) 
    {
        if (!item.empty()) 
        {
            std::cout << item << std::endl;
        }
    }
}
