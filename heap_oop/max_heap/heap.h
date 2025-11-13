#pragma once
#include <vector>

class Heap {
private:
    int* m_arr {nullptr};
    int m_size = 0;
    int m_cap;
    bool sizeSafe(int n);
    void accessValid();
    void copyArr(const int* src, int n);
public:
    Heap(int cap = 10);
    ~Heap();

    void buildMaxHeap(const int* src, int n);
    void heapify();
    void heapUp(int idx);
    int extractMax();
    void deleteNode(int value);

    int peek();
    bool empty() const;
    int parentIdx(int idx);
    int leftChildIdx(int idx);
    int rightChildIdx(int idx);
};
