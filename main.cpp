#include <iostream>
#include "ZipIterator.h"
#include <vector>
#include <set>

void same_number() {
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = {6, 7, 8, 9, 10};

    std::cout << "Vectors with same number of elements:" << std::endl;
    zip_iterator<std::vector<int>::iterator, std::vector<int>::iterator> zip(v1, v2);
    while (!zip.any(std::make_pair(v1.end(), v2.end()))) {
        std::cout << "(" << zip->first << " " << zip->second << ")" << std::endl;
        zip++;
    }
}

void different_number() {
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<std::string> v2 = {"F", "E", "D"};
    std::cout << "Vectors with different number of elements:" << std::endl;
    zip_iterator<std::vector<int>::iterator, std::vector<std::string>::iterator> zip(v1, v2);
    while (!zip.any(std::make_pair(v1.end(), v2.end()))) {
        std::cout << "(" << zip->first << " " << zip->second << ")" << std::endl;
        zip++;
    }
}

int main() {
    same_number();
    different_number();
    return 0;
}
