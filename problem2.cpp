#include <iostream>
#include <vector>
#include "heap_oop/min_heap/heap.h"
#include "utils/utils.h"

void heapSort(std::vector<int>& dest, const std::vector<int>& src) {
    Heap hp = Heap(src.size());
    hp.buildMinHeap(src.data(), src.size());

    while (!hp.empty()) {
        dest.push_back(hp.extractMin());
    }
}

int main(void) {
    int size;
    std::cin >> size;

    std::vector<int> src;
    inputVec(src, size);

    std::vector<int> sortedVec;
    heapSort(sortedVec, src);

    printVec(sortedVec);
    
    return 0;
}
