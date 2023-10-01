#include <iostream>
#include <string>

int maxConsecutiveElements(const std::string);

int main() {
    std::string word = "heellowooorldd";
    std::cout << "Maximum Consecutive Elements count is equal of " 
                << maxConsecutiveElements(word) << std::endl;
    return 0;
}

int maxConsecutiveElements(const std::string word) {
    int maxCount = 1;
    int currCount = 1;
    for (int i = 0; i < word.size() - 1; ++i) {
        if (word[i] == word[i + 1]) {
            ++currCount; 
            maxCount = (currCount > maxCount) ? currCount : maxCount;
        }
        else {
            currCount = 1;
        }
    }
    return maxCount;
}
