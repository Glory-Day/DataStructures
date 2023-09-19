#include <iostream>
#include <algorithm>

template <typename T>
class MaximumHeap {
private:
    T*  _head;     // Head of elements
    int _capacity; // Maximum possible size
    int _size;     // Current index number of elements

    void Heapify(int);

    int GetParentIndex(int);
    int GetLeftChildIndex(int);
    int GetRightChildIndex(int);

public:
    /**
     * `Maximum Heap` default constructor
     * 
     * @param capacity Maximum possible size
     */
    explicit MaximumHeap(int capacity) : _head{new T[capacity]}, _capacity{capacity}, _size{0} {}

    T Top();
    void Insert(T);
    void Extract();
};

/**
 * @param index Index number of node
 * @return Get index number of parent node
 */
template <typename T>
int MaximumHeap<T>::GetParentIndex(int index) {
    return (index - 1) / 2;
}

/**
 * @param index Index number of node
 * @return Get index number of left child node
 */
template <typename T>
int MaximumHeap<T>::GetLeftChildIndex(int index) {
    return index * 2 + 1;
}

/**
 * @param index Index number of node
 * @return Get index number of right child node
 */
template <typename T>
int MaximumHeap<T>::GetRightChildIndex(int index) {
    return index * 2 + 2;
}

/**
 * Heapify a subtree with the root at given index number
 * 
 * @param index Index number of node
 */
template <typename T>
void MaximumHeap<T>::Heapify(int index) {
    int leftChildIndex = GetLeftChildIndex(index);
    int rightChildIndex = GetRightChildIndex(index);

    int updatedIndex = index;
    if (leftChildIndex < _size && _head[updatedIndex] < _head[leftChildIndex]) {
        updatedIndex = leftChildIndex;
    }
    if (rightChildIndex < _size && _head[updatedIndex] < _head[rightChildIndex]) {
        updatedIndex = rightChildIndex;
    }

    if (updatedIndex != index) {
        std::swap(_head[index], _head[updatedIndex]);
        Heapify(updatedIndex);
    }
}

/**
 * @return Get data from `Maximum Heap`
 */
template <typename T>
T MaximumHeap<T>::Top() {
    try {
        if (_size <= 0) {
            throw std::out_of_range("Maximum heap is empty.");
        }

        return _head[0];
    }
    catch (std::out_of_range& exception) {
        std::cout << " - Exception : " << exception.what() << std::endl;
    }

    return -1;
}

/**
 * Inserts a new data in `Maximum Heap`
 * 
 * @param data : New data
 */
template <typename T>
void MaximumHeap<T>::Insert(T data) {
    try {
        if (_size == _capacity) {
            throw std::out_of_range("Maximize heap is full.");
        }

        int index = ++_size - 1;
        _head[index] = data;

        while (index != 0 && _head[GetParentIndex(index)] > _head[index]) {
            std::swap(_head[index], _head[GetParentIndex(index)]);
            index = GetParentIndex(index);
        }
    }
    catch (std::out_of_range& exception) {
        std::cout << " - Exception : " << exception.what() << std::endl;
    }
}

/**
 * Remove data from `Maximum Heap`
 */
template <typename T>
void MaximumHeap<T>::Extract() {
    try {
        if (_size <= 0) {
            throw std::out_of_range("Maximum heap is empty.");
        }

        if (_size == 1) {
            _size--;
            return;
        }

        _head[0] = _head[_size - 1];
        _size--;
        Heapify(0);
    }
    catch (std::out_of_range& exception) {
        std::cout << " - Exception : " << exception.what() << std::endl;
    }
}