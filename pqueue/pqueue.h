#pragma once


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
