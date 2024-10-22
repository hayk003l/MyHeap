#include "heap.hpp"

void Heap::heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int size = vec.size();

    if (left < size && vec[left] > vec[i]) {
        largest = left;
    } 

    if (right < size && vec[right] > vec[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(vec[i], vec[largest]);
        heapify(largest);
    }
}

void Heap::insert(const int& elem) {
    vec.push_back(elem);
    int i = vec.size() - 1;

    while (i != 0 && vec[(i - 1) / 2] < vec[i]) {
        std::swap(vec[i], vec[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int Heap::extractMax() {
    if (vec.size() <= 0) {
        throw std::underflow_error("Heap underflow");
    }

    if (vec.size() == 1) {
        int root = vec[0];
        vec.pop_back();
        return root;
    }

    int root = vec[0];
    vec[0] = vec.back();
    vec.pop_back();
    heapify(0);

    return root;
}

int Heap::getMax() {
    if (vec.size() <= 0) {
        throw std::underflow_error("Heap underflow");
    }

    return vec[0];
}

void Heap::deleteKey(int i) {
    if (i >= vec.size()) {
        throw std::out_of_range("Out of Heap size");
    }

    vec[i] = vec.back();
    vec.pop_back();
    heapify(i);
}

void Heap::increaseKey(int i, const int& newValue) {
    if (i >= vec.size() || vec[i] >= newValue) {
        throw std::out_of_range("Invalid index or the new value is not greater");
    }

    vec[i] = newValue;
    while (i != 0 && vec[(i - 1) / 2] < vec[i]) {
        std::swap(vec[i], vec[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    
}

void Heap::printHeap() const {
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
}