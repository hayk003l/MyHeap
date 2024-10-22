#ifndef __HEAP__
#define __HEAP__

#include <vector>
#include <stdexcept>
#include <iostream>

class Heap {
private:
    std::vector<int> vec;
    void heapify(int i);
public:
    Heap() = default; 
    ~Heap() = default;

    void insert(const int& elem);
    int getMax();
    void deleteKey(int i);
    void increaseKey(int i, const int& newValue);
    void printHeap() const;
    int extractMax();

};

#endif // __HEAP__