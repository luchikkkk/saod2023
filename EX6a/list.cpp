#include "Str.h"
#include <iostream>

int main() {
    Str s("Hello world!");
    int index = s.find("world", 5);
    if (index != -1) {
        std::cout << "Substring found at index " << index << std::endl;
    }
    else {
        std::cout << "Substring not found" << std::endl;
    }
}
