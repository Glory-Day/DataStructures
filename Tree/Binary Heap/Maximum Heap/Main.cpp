#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class MaximumHeap {
private:
    T* _head;      // Pointer to array of elements in maximum heap
    int _capacity; // Maximum possible size of heap
    int _size;     // Current number of elements in heap

    int getParentIndex(int);
    int getLeftChildIndex(int);
    int getRightChildIndex(int);

    void heapify(int);

public:
    /**
     * Default maximum heap constructor
     * @param capacity : Maximum possible size of maximum heap
     */
    explicit MaximumHeap(int capacity) : _head{new T[capacity]}, _capacity{capacity}, _size{0} {}

    T top();
    void insert(T value);
    void extract();
};

/**
 * Get index of parent of node at index
 * @tparam T : Data type
 * @param index : Index of node
 * @return Index of parent of node
 */
template <typename T>
int MaximumHeap<T>::getParentIndex(int index) {
    return (index - 1) / 2;
}

/**
 * Get index of left child of node at index
 * @tparam T : Data type
 * @param index : Index of node
 * @return Index of left child of node
 */
template <typename T>
int MaximumHeap<T>::getLeftChildIndex(int index) {
    return index * 2 + 1;
}

/**
 * Get index of right child of node at index
 * @tparam T : Data type
 * @param index : Index of node
 * @return Index of right child of node
 */
template <typename T>
int MaximumHeap<T>::getRightChildIndex(int index) {
    return index * 2 + 2;
}

/**
 * Heapify a subtree with the root at given index
 * @tparam T : Data type
 * @param index : Index of node
 */
template <typename T>
void MaximumHeap<T>::heapify(int index) {
     int leftChildIndex = getLeftChildIndex(index);
     int rightChildIndex = getRightChildIndex(index);

     int updatedIndex = index;
     if (leftChildIndex < _size && _head[updatedIndex] < _head[leftChildIndex]) {
         updatedIndex = leftChildIndex;
     }
     if (rightChildIndex < _size && _head[updatedIndex] < _head[rightChildIndex]) {
         updatedIndex = rightChildIndex;
     }

     if (updatedIndex != index) {
         swap(_head[index], _head[updatedIndex]);
         heapify(updatedIndex);
     }
}

/**
 * Get maximum element from maximum heap
 * @tparam T : Data type
 * @return Maximum element from maximum heap
 */
template <typename T>
T MaximumHeap<T>::top() {
    try {
        if (_size <= 0) {
            throw out_of_range("Maximum heap is empty.");
        }

        return _head[0];
    }
    catch (out_of_range& exception) {
        cout << " - Exception" << endl;
        cout << exception.what() << endl;
    }

    return -1;
}

/**
 * Inserts a new value in maximum heap
 * @tparam T : Data type
 * @param value : New value
 */
template <typename T>
void MaximumHeap<T>::insert(T value) {
    try {
        if (_size == _capacity) {
            throw out_of_range("Maximize heap is full.");
        }

        int index = ++_size - 1;
        _head[index] = value;

        while (index != 0 && _head[getParentIndex(index)] > _head[index]) {
            swap(_head[index], _head[getParentIndex(index)]);
            index = getParentIndex(index);
        }
    }
    catch (out_of_range& exception) {
        cout << " - Exception" << endl;
        cout << exception.what() << endl;
    }
}

/**
 * Remove maximum element from maximum heap
 * @tparam T : Data type
 */
template <typename T>
void MaximumHeap<T>::extract() {
    try {
        if (_size <= 0) {
            throw out_of_range("Maximum heap is empty.");
        }

        if (_size == 1) {
            _size--;
            return;
        }

        _head[0] = _head[_size - 1];
        _size--;
        heapify(0);
    }
    catch (out_of_range& exception) {
        cout << " - Exception" << endl;
        cout << exception.what() << endl;
    }
}

int main() {
    MaximumHeap<int> heap = MaximumHeap<int>(10);

    bool isLoop = true;
    while (isLoop) {
        cout << "Data structure - Binary Heap(ADT)" << endl;
        cout << "(1). insert()" << endl;
        cout << "(2). extract()" << endl;
        cout << "(3). top()" << endl;
        cout << " - Input" << endl;

        int index;
        cin >> index;

        int data;
        switch (index) {
            case 1:
                cout << " - Input" << endl;
                cin >> data;
                heap.insert(data);
                break;
            case 2:
                heap.extract();
                break;
            case 3:
                cout << " - Output" << endl;
                cout << heap.top() << endl;
                break;
            default:
                isLoop = false;
                break;
        }

        cout << endl;
    }
}