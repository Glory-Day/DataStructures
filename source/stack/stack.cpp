#include <iostream>
#include <cstdlib>

#include "stack.hpp"

using namespace std;

/**
 * @return First stored data in `stack`
 */
template <typename T>
const T Stack<T>::Top() {
    T data;

    try {
        // Throw exception when accessing null pointer
        if (IsEmpty()) {
            throw out_of_range("Stack is empty");
        }

        data = *(_container + _index);
    }
    catch (out_of_range& exception) {
        cout << " - Exception : " << exception.what() << endl;
    }

    return data;
}

/**
 * @return Check stack is empty or not
 */
template <typename T>
const bool Stack<T>::IsEmpty() {
    return _index == -1;
}

/**
 * Push data in `stack`
 *
 * @param data : Data to push
 */
template <typename T>
void Stack<T>::Push(const T data) {
    if (IsEmpty()) {
        // Stack is not allocated memory
        _container = (T*)malloc(sizeof(T));

        // Store data and increase index
        *_container = data;
        _index++;
    }
    else {
        // Reallocate one more memory increase from the current allocated memory
        int size = (++_index) + 1;
        _container = (T*)realloc(_container, sizeof(T) * size);

        // Store data
        *(_container + _index) = data;
    }
}

/**
 * Pop data in `stack`
 */
template <typename T>
void Stack<T>::Pop() {
    try {
        // Throw exception when accessing null pointer
        if (IsEmpty()) {
            throw out_of_range("Stack is empty");
        }

        if (_index == 0) {
            // Returns allocated memory to prevent memory leakage
            free(_container);
        }
        else {
            // Reallocate one more memory decrease from the current allocated memory
            _container = (T*)realloc(_container, sizeof(T) * (_index - 1));
        }
    }
    catch (out_of_range& exception) {
        cout << " - Exception : " << exception.what() << endl;
    }
}