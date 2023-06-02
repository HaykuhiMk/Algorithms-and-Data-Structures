#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "text.h"

void reader(Text t, const std::string& a, const std::string& b)
{
    t.readFile("1.txt");
    
    t.readFile("2.txt");
}

int main()
{
    // Text text;
    // text.readFile("1.txt");
    // std::cout << std::endl;
    // text.readFile("2.txt");
    // std::string searchWord;
    // std::cout << "Enter a word to search: ";
    // std::cin >> searchWord;
    // text.searchWord(searchWord);
    // return 0;

    Text text;
    reader(text, "1.txt", "2.txt");
    // text.readFile("2.txt");

    // text.print();
    // text.readFile("1.txt");
    // text.searchWord("computer");
    // text.searchWord("World");
    // text.searchWord("OpenAI");
    
    return 0;
}

