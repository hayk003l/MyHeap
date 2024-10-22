#include <iostream>
#include "heap.hpp"


int main() {
    Heap hp;

    hp.insert(45);
    hp.insert(43);
    hp.insert(23);
    hp.insert(7);
    hp.insert(5);
    hp.insert(11);
    hp.insert(9);

    hp.increaseKey(4, 47);

    hp.printHeap();

    return 0;
}