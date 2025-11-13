#include <iostream>
#include <stdexcept>

class MaxPQueue {
private:
    int* m_arr {nullptr}; // the problem requirements are VERY confusing
    int m_cap;
    int m_size {0};
    void validate_overflow();
    int get_max_id() const;
public:
    MaxPQueue(int cap = 10);
    ~MaxPQueue();
    void insert(int);
    int get_max() const;
    int extract_max();
    int size() const;
    bool empty() const;
};

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

int main(void) {
    int cap;
    std::cin >> cap;
    MaxPQueue pq(cap);
    pq.insert(5);
    pq.insert(2);
    std::cout << pq.get_max() << std::endl;

    pq.insert(7);
    std::cout << pq.size() << std::endl;

    std::cout << pq.extract_max() << std::endl;
    std::cout << pq.extract_max() << std::endl;

    std::cout << pq.extract_max() << std::endl;

    /*
     * The problem set shows that the program should
     * print "EMPTY" when get_max is called on an
     * empty queue.
     *
     * However, I disagree with this behavior
     * for these reasons:
     *  1. Function return type mismatch 
     *     (it has to return only integer).
     *  2. Function behavior inconsistency.
     *  3. The container does not have to go SILENT. The client
     *     code must ensure and know that exceptions occur.
     *     Otherwise, a flowed code/bugs can go silent.
     * */

    try {
        std::cout << pq.get_max() << std::endl;
    } catch (std::runtime_error e) {
        std::cout << "EMPTY" << std::endl;
    }
    return 0;
}
