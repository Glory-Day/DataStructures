#include <iostream>

#include "maximum_heap.hpp"
#include "tree\binary_heap\maximum_heap\maximum_heap.cpp"

int main() {
    MaximumHeap<int> heap = MaximumHeap<int>(10);

    bool isLoop = true;
    while (isLoop) {
        std::cout << "Data structure - Maximum Heap(ADT)" << std::endl;
        std::cout << "(1). Insert data" << std::endl;
        std::cout << "(2). Extract data" << std::endl;
        std::cout << "(3). Get data from maximum heap" << std::endl;
        std::cout << " - Input" << std::endl;

        int index;
        std::cin >> index;

        int data;
        switch (index) {
            case 1:
                std::cout << " - Input" << std::endl;
                std::cin >> data;
                heap.Insert(data);
                break;
            case 2:
                heap.Extract();
                break;
            case 3:
                std::cout << " - Output" << std::endl;
                std::cout << heap.Top() << std::endl;
                break;
            default:
                isLoop = false;
                break;
        }

        std::cout << std::endl;
    }
}