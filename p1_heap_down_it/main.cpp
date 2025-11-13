#include <iostream>
#include <vector>
#include "../heap_procedural/heap.h"
#include "../utils/utils.h"

int main(void) {
    int size;
    std::cout << "Enter size: ";
    std::cin >> size;

    std::vector<int> vec;
    inputVec(vec, size);

    int startIdx;
    std::cout << "Enter index to apply heap down: ";
    std::cin >> startIdx;
    
    heapDown(vec, startIdx);
    std::cout << "Vector after heap down: " << std::endl;
    printVec(vec);
    return 0;
}
