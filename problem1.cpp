#include <iostream>
#include <vector>


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


int parentIdx(int idx);
int leftChildIdx(int idx);
int rightChildIdx(int idx);
// Function to transform a vector to array-heap
void minHeapify(std::vector<int>& vec);
// Function to heapdown from idx
void heapDown(std::vector<int>& vec, int idx);


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
