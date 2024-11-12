#include <iostream>

void writeArrayBackward(const char* str, int first, int last);

int main()
{
    const int size = 6;
    const char str[size] = "asdfg";
    std::cout << "Output data: " << std::endl;
    writeArrayBackward(str, 0, size - 1);
    std::cout << std::endl;
}

void writeArrayBackward(const char* str, int first, int last)
{
    if (last >= first)
    {
        std::cout << str[last];
        writeArrayBackward(str, first, last - 1);
    }
}