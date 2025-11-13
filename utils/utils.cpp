#include <iostream>
#include <vector>
#include "utils.h"


void inputVec(std::vector<int>& vec, int size) {
    for (int i = 0; i < size; i++) {
        int inp;
        std::cin >> inp;
        vec.push_back(inp);
    }
}

void printVec(const std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
