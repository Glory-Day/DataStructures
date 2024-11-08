#include <iostream>
#include <cstdlib>

#include "queue.hpp"

/**
 * @return First stored data in `queue`
 */
template <typename T>
T Queue<T>::Front() {
    T data;

    try {
        // Throw exception when accessing null pointer
        if (IsEmpty()) {
            throw std::out_of_range("Queue is empty");
        }

        data = _queue[_head + 1];
    }
    catch (std::out_of_range& exception) {
        std::cout << " - Exception : " << exception.what() << std::endl;
    }

    return data;
}

/**
 * @return Check queue is empty or not
 */
template <typename T>
bool Queue<T>::IsEmpty() {
    return _head == _tail;
}

/**
 * Push data in `queue`
 *
 * @param data : Data to push
 */
template <typename T>
void Queue<T>::Enqueue(T data) {
    try {
        // Throw exception when accessing null pointer
        if (_tail == _size - 1) {
            throw std::out_of_range("Queue is full");
        }

        // Store data
        _queue[++_tail] = data;
    }
    catch (std::out_of_range& exception) {
        std::cout << " - Exception : " << exception.what() << std::endl;
    }
}

/**
 * Pop data in `queue`
 */
template <typename T>
void Queue<T>::Dequeue() {
    try {
        // Throw exception when accessing null pointer
        if (IsEmpty()) {
            throw std::out_of_range("Queue is empty");
        }

        // Increase index of head
        _head++;
    }
    catch (std::out_of_range& exception) {
        std::cout << " - Exception : " << exception.what() << std::endl;
    }
}