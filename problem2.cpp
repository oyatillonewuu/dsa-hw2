#include <iostream>
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

    void buildMinHeap(const int* src, int n);
    void heapify();
    void heapDown(int idx);
    int extractMin();
    void deleteNode(int value);

    int peek();
    bool empty() const;
    int parentIdx(int idx);
    int leftChildIdx(int idx);
    int rightChildIdx(int idx);
};

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
