#ifndef TEXT_H
#define TEXT_H
#include <unordered_map>
#include "word.h"

class Text
{
public:
    void addWord(const std::string& word, const std::string& fileName);
    void readFile(const std::string&);
    std::string cleanWord(const std::string&);
    std::string toLow(const std::string& word); 
    std::string toUpp(const std::string& word); 
    bool checkDir(const std::string&, const std::string&);
    void searchWord(const std::string& word);
    void print();

private:
    std::unordered_map<std::string, Word> mWords;

};

#endif  //TEXT_H