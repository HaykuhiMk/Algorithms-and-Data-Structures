#include <iostream>
#include <fstream>
#include <sstream>
#include "text.h"

// const std::vector<Word*>& Text::getWord() const
// {
//     return mWords;
// }

void Text::print()
{
    for (const auto& pair : this->mWords) 
    {
        std::cout << pair.second.getData() << std::endl;
    }
}
void Text::addWord(const std::string& word, const std::string& fileName)
{
    std::string clnWord = cleanWord(word);
    auto it = mWords.find(clnWord);
    if (it != mWords.end())
    {
        it->second.addFileName(fileName);
    }
    else
    {
        mWords.emplace(clnWord, Word(clnWord, fileName));
    }
}

std::string Text::toLow(const std::string& word) 
{
    std::string tmp = word;
    for (char& ch : tmp) 
    {
        if (ch >= 'A' && ch <= 'Z') 
        {
            ch = ch + 32;
        }
    }
    return tmp;
}

bool Text::checkDir(const std::string& word, const std::string& file)
{
    std::ifstream dirFile(file);
    if (!dirFile.is_open()) 
    {
        std::cerr << "Failed to open the dictionary file." << std::endl;
        return false;
    }
    std::string dWord;
    while (dirFile >> dWord) 
    {
        if (dWord == word) 
        {
            dirFile.close();
            return true;
        }
    }
    dirFile.close();
    return false;
}

std::string Text::toUpp(const std::string& word) 
{
    std::string tmp = word;
    for (char& ch : tmp) 
    {
        if (ch >= 'a' && ch <= 'z') 
        {
            ch = ch - 32;
        }
    }
    return tmp;
}


std::string Text::cleanWord(const std::string& word)
{
    std::string clnWord;
    for (char ch : word) 
    {
       if (std::isalpha(ch)) 
        {
            clnWord += ch;
        }
    }
    return toLow(clnWord);
}

void Text::readFile(const std::string& fileName)
{
    int fI = std::stoi(fileName.substr(0, fileName.find('.')));

    std::ifstream inFile(fileName);
    if (!inFile) 
    {
        std::cerr << "Failed to open the input file." << std::endl;
        return;
    }
    std::string word;
    while (inFile >> word) 
    {
        std::string clnWord = cleanWord(word);
        if (clnWord.empty())
        {
            continue;
        }
        if (checkDir(clnWord, "words_alpha.txt"))
        {
            auto it = mWords.find(clnWord);
            if (it != mWords.end())
            {
                it->second.addFileName(fileName);
            }
            else
            {
                mWords.emplace(clnWord, Word(clnWord, fileName));
            }
        }
    }

    inFile.close();
    std::ofstream outFile("db.txt", std::ios::app);
    if (!outFile) 
    {
        std::cerr << "Failed to open the output file." << std::endl;
        return;
    }
    for (const auto& entry : mWords) 
    {
        const Word& word = entry.second;
        const std::vector<std::string>& fileNamesStr = word.getFileNames();
        outFile << word.getData() << ": ";
        for (const std::string& fileNameStr : fileNamesStr)
        {
            int fileName = std::stoi(fileNameStr);
            outFile << fileName << " ";
        }
        outFile << std::endl;
    }
    outFile.close();
    std::cout << "Words saved to db.txt." << std::endl;
}


void Text::searchWord(const std::string& word)
{
    std::ifstream inFile("db.txt");
    if (!inFile)
    {
        std::cerr << "Failed to open the db.txt file." << std::endl;
        return;
    }
    std::string line;
    std::vector<std::string> fileNames;

    while (std::getline(inFile, line))
    {
        std::string dbWord = line.substr(0, line.find(":"));
        if (dbWord == word) {
            std::cout << "Files that contain the word '" << word << "':" << std::endl;
            std::string fileNames = line.substr(line.find(":") + 1);
            std::replace(fileNames.begin(), fileNames.end(), ',', ' ');
            std::cout << fileNames << std::endl;
            return;
        }
    }
    std::cout << "The word '" << word << "' was not found in the database." << std::endl;
}
