#include <iostream>
#include <algorithm>

#include "minimum_heap.hpp"

/**
 * @param index Index number of node
 * @return Get index number of parent node
 */
template <typename T>
int MinimumHeap<T>::GetParentIndex(int index) {
    return (index - 1) / 2;
}

/**
 * @param index Index number of node
 * @return Get index number of left child node
 */
template <typename T>
int MinimumHeap<T>::GetLeftChildIndex(int index) {
    return index * 2 + 1;
}

/**
 * @param index Index number of node
 * @return Get index number of right child node
 */
template <typename T>
int MinimumHeap<T>::GetRightChildIndex(int index) {
    return index * 2 + 2;
}

/**
 * heapify a subtree with the root at given index
 * 
 * @param index Index number of node
 */
template <typename T>
void MinimumHeap<T>::Heapify(int index) {
    int leftChildIndex = GetLeftChildIndex(index);
    int rightChildIndex = GetRightChildIndex(index);

    int updatedIndex = index;
    if (leftChildIndex < _size && _head[leftChildIndex] < _head[updatedIndex]) {
        updatedIndex = leftChildIndex;
    }
    if (rightChildIndex < _size && _head[rightChildIndex] < _head[updatedIndex]) {
        updatedIndex = rightChildIndex;
    }

    if (updatedIndex != index) {
        std::swap(_head[index], _head[updatedIndex]);
        Heapify(updatedIndex);
    }
}

/**
 * @return Get data from `Minimum Heap`
 */
template <typename T>
T MinimumHeap<T>::Top() {
    try {
        if (_size <= 0) {
            throw std::out_of_range("Minimum heap is empty");
        }

        return _head[0];
    }
    catch (std::out_of_range& exception) {
        std::cout << " - Exception : " << exception.what() << std::endl;
    }

    return -1;
}

/**
 * Inserts a new data in `Minimum Heap`
 * 
 * @param data New data
 */
template <typename T>
void MinimumHeap<T>::Insert(T data) {
    try {
        if (_size == _capacity) {
            throw std::out_of_range("Minimize heap is full");
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
 * Remove data from `Minimum Heap`
 */
template <typename T>
void MinimumHeap<T>::Extract() {
    try {
        if (_size <= 0) {
            throw std::out_of_range("Minimum heap is empty");
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