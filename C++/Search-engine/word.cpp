#include <iostream>
#include <algorithm>
#include "word.h"

Word::Word(const std::string& data, const std::string& file)
{
    this->mData = data;
    this->mFileNames.push_back(file);
}
const std::string& Word::getData() const
{
    return mData;
}

void Word::setData(const std::string& data)
{  
    mData = data;
}

const std::vector<std::string>& Word::getFileNames() const
{
    return mFileNames;
}

void Word::addFileName(const std::string& file)
{
    if (std::find(mFileNames.begin(), mFileNames.end(), file) == mFileNames.end()) 
    {
        mFileNames.push_back(file);
    }
}

