#include <iostream>
#include <stdexcept>
#include "pqueue.h"

MaxPQueue::MaxPQueue(int cap)
    : m_cap{ cap }
{
    m_arr = new int[cap];
}

MaxPQueue::~MaxPQueue() {
    delete[] m_arr;
}

void MaxPQueue::validate_overflow() {
    if (m_size + 1 > m_cap) {
        throw std::runtime_error(
            "Overflow error: priority queue is full."
        );
    }
}

void MaxPQueue::insert(int value) {
    validate_overflow();
    m_arr[m_size++] = value;
} 

int MaxPQueue::get_max() const {
    if (empty()) {
        // The problem set shows "EMPTY" printed when get_max
        // is called on empty queue. Can't mix it 
        throw std::runtime_error("Priority queue access invalid: queue empty.");
    }
    return m_arr[get_max_id()];
}

int MaxPQueue::get_max_id() const {
    if (empty()) {
        throw std::runtime_error("Internal error: access to empty container.");
    }
    int max_id = 0;
    for (int i = 1; i < m_size; i++) {
        if (m_arr[max_id] < m_arr[i]) {
            max_id = i;
        }
    }
    return max_id;
}

int MaxPQueue::extract_max() {
    int max_id = get_max_id();
    int value = m_arr[max_id];
    m_arr[max_id] = m_arr[m_size - 1];
    m_size--;
    return value;
}

int MaxPQueue::size() const {
    return m_size;
}

bool MaxPQueue::empty() const {
    return m_size == 0;
}
