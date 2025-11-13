#include <iostream>
#include "heap.h"

int parentIdx(int idx) {
    return (idx - 1) / 2;
}

int leftChildIdx(int idx) {
    return idx * 2 + 1;
}

int rightChildIdx(int idx) {
    return idx * 2 + 2;
}

void minHeapify(std::vector<int>& vec) {
    int lastIdx = vec.size() - 1;
    int startFrom = parentIdx(lastIdx);

    for (int i = startFrom; i >= 0; i--) {
        heapDown(vec, i);
    }
}
/*
void heapDown(std::vector<int>& vec, int idx) {
    int smallest = idx;
    int right = rightChildIdx(idx);
    int left = leftChildIdx(idx);
    
    if (left < vec.size() && vec[left] < vec[idx]) {
        smallest = left;
    }
    if (right < vec.size() && vec[right] < vec[smallest]) {
        smallest = right;
    }

    if (smallest != idx) {
        int tmp = vec[idx];
        vec[idx] = vec[smallest];
        vec[smallest] = tmp;
        heapDown(vec, smallest);
    }
}
*/
void heapDown(std::vector<int>& vec, int idx) {
    while (true) {
        int smallest = idx;
        int right = rightChildIdx(idx);
        int left = leftChildIdx(idx);
        
        if (left < vec.size() && vec[left] < vec[idx]) {
            smallest = left;
        }
        if (right < vec.size() && vec[right] < vec[smallest]) {
            smallest = right;
        }

        if (smallest != idx) {
            int tmp = vec[idx];
            vec[idx] = vec[smallest];
            vec[smallest] = tmp;
            idx = smallest;
        } else {
            break;
        }
    }
}
