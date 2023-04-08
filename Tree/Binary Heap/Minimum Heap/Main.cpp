#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class MinimumHeap {
private:
    T* _head;      // Pointer to array of elements in minimum heap
    int _capacity; // Maximum possible size of heap
    int _size;     // Current number of elements in heap

    int getParentIndex(int);
    int getLeftChildIndex(int);
    int getRightChildIndex(int);

    void heapify(int);

public:
    /**
     * Default minimum heap constructor
     * @param capacity : Maximum possible size of minimum heap
     */
    explicit MinimumHeap(int capacity) : _head{new T[capacity]}, _capacity{capacity}, _size{0} {}

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
int MinimumHeap<T>::getParentIndex(int index) {
    return (index - 1) / 2;
}

/**
 * Get index of left child of node at index
 * @tparam T : Data type
 * @param index : Index of node
 * @return Index of left child of node
 */
template <typename T>
int MinimumHeap<T>::getLeftChildIndex(int index) {
    return index * 2 + 1;
}

/**
 * Get index of right child of node at index
 * @tparam T : Data type
 * @param index : Index of node
 * @return Index of right child of node
 */
template <typename T>
int MinimumHeap<T>::getRightChildIndex(int index) {
    return index * 2 + 2;
}

/**
 * heapify a subtree with the root at given index
 * @tparam T : Data type
 * @param index : Index of node
 */
template <typename T>
void MinimumHeap<T>::heapify(int index) {
     int leftChildIndex = getLeftChildIndex(index);
     int rightChildIndex = getRightChildIndex(index);

     int updatedIndex = index;
     if (leftChildIndex < _size && _head[leftChildIndex] < _head[updatedIndex]) {
         updatedIndex = leftChildIndex;
     }
     if (rightChildIndex < _size && _head[rightChildIndex] < _head[updatedIndex]) {
         updatedIndex = rightChildIndex;
     }

     if (updatedIndex != index) {
         swap(_head[index], _head[updatedIndex]);
         heapify(updatedIndex);
     }
}

/**
 * Get minimum element from minimum heap
 * @tparam T : Data type
 * @return Minimum element from minimum heap
 */
template <typename T>
T MinimumHeap<T>::top() {
    if (_size <= 0) {
        throw out_of_range("Minimum heap is empty.");
    }

    return _head[0];
}

/**
 * Inserts a new value in minimum heap
 * @tparam T : Data type
 * @param value : New value
 */
template <typename T>
void MinimumHeap<T>::insert(T value) {
    if (_size == _capacity) {
        throw out_of_range("Minimize heap is full.");
    }

    int index = ++_size - 1;
    _head[index] = value;

    while (index != 0 && _head[getParentIndex(index)] > _head[index]) {
        swap(_head[index], _head[getParentIndex(index)]);
        index = getParentIndex(index);
    }
}

/**
 * Remove minimum element from minimum heap
 * @tparam T : Data type
 */
template <typename T>
void MinimumHeap<T>::extract() {
    if (_size <= 0) {
        throw out_of_range("Minimum heap is empty.");
    }

    if (_size == 1) {
        _size--;
        return;
    }

    _head[0] = _head[_size - 1];
    _size--;
    heapify(0);
}

int main() {
    MinimumHeap<int> heap = MinimumHeap<int>(10);

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