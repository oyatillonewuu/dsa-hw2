#include <iostream>
#include <stdexcept>
#include "heap.h"

Heap::Heap(int cap)
    : m_cap{ cap }
{
    m_arr = new int[cap];
}

Heap::~Heap() {
    delete[] m_arr;
}

int Heap::parentIdx(int idx) {
    return (idx - 1) / 2;
}

int Heap::leftChildIdx(int idx) {
    return idx * 2 + 1;
}

int Heap::rightChildIdx(int idx) {
    return idx * 2 + 2;
}

bool Heap::sizeSafe(int n) {
    return n <= m_cap;
}

void Heap::accessValid() {
    if (empty()) {
        throw std::runtime_error("Access MinHeap: illegal access to empty heap!");
    }
}

void Heap::copyArr(const int* src, int n) {
    for (int i = 0; i < n; i++) {
        m_arr[i] = src[i];
    }
    m_size = n;
}

void Heap::buildMinHeap(const int* src, int n) {
    if (!sizeSafe(n)) {
        throw std::runtime_error("Build MinHeap: bad size!");
    }
    copyArr(src, n);
    heapify();
}

void Heap::heapify() {
    int lastIdx = m_size - 1;
    int startFrom = parentIdx(lastIdx);
    for (int i = startFrom; i >= 0; i--) {
        heapDown(i);
    }
}

void Heap::heapDown(int idx) {
    while (true) {
        int smallest = idx;
        int right = rightChildIdx(idx);
        int left = leftChildIdx(idx);
        
        if (left < m_size && m_arr[left] < m_arr[idx]) {
            smallest = left;
        }
        if (right < m_size && m_arr[right] < m_arr[smallest]) {
            smallest = right;
        }

        if (smallest != idx) {
            int tmp = m_arr[idx];
            m_arr[idx] = m_arr[smallest];
            m_arr[smallest] = tmp;
            idx = smallest;
        } else {
            break;
        }
    }
}

int Heap::extractMin() {
    accessValid();
    int value = peek();
    deleteNode(value);
    return value;
}

void Heap::deleteNode(int value) {
    accessValid();
    int i = 0;
    for (int i = 0; i < m_size; i++) {
        if (m_arr[i] == value) break;
    }

    if (i == m_size) {
        throw std::runtime_error("Heap access: non-existent value!");
    }

    // If there is only one node left, exit
    if (i + 1 == m_size) {
        m_size--;
        return;
    }
    // Swap with the last node and delete the last node
    int tmp = m_arr[m_size - 1];
    m_arr[m_size - 1] = m_arr[i];
    m_arr[i] = tmp;
    m_size--;

    heapify();
}

int Heap::peek() {
    accessValid();
    return m_arr[0];
}

bool Heap::empty() const {
    return m_size == 0;
}

