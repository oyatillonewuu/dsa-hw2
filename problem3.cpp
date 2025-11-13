#include <iostream>
#include <stdexcept>
#include "pqueue/pqueue.h"
using namespace std;

int main(void) {
    int cap;
    cin >> cap;
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
