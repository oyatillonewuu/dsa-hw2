#pragma once
#include <vector>

int parentIdx(int idx);
int leftChildIdx(int idx);
int rightChildIdx(int idx);
// Function to transform a vector to array-heap
void minHeapify(std::vector<int>& vec);
// Function to heapdown from idx
void heapDown(std::vector<int>& vec, int idx);
