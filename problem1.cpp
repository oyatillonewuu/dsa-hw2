#include <iostream>
#include <vector>
#include "heap_procedural/heap.h"
#include "utils/utils.h"

int main(void) {
    int size;
    std::cin >> size;

    std::vector<int> vec;
    inputVec(vec, size);

    int startIdx;
    std::cin >> startIdx;
    
    heapDown(vec, startIdx);
    printVec(vec);
    return 0;
}
