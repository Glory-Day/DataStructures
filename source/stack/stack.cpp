#include <iostream>
#include <cstdlib>

#include "stack.hpp"

using namespace std;

template<typename T>
int Stack<T>::size() const {
    return _index + 1;
}

template<typename T>
void Stack<T>::reserve(const int capacity) {
    T* caches = new T[capacity];
    
    memcpy(caches, _container, sizeof(T) * size());

    _container = caches;
    _capacity = capacity;
}

/**
 * @return First stored data in `stack`
 */
template <typename T>
T& Stack<T>::top() const {
    // Throw exception when accessing null pointer
    if (empty()) {
        throw out_of_range("STACK IS EMPTY");
    }

    return *(_container + _index);
}

/**
 * @return Check stack is empty or not
 */
template <typename T>
bool Stack<T>::empty() const {
    return _index == -1;
}

/**
 * Push data in `stack`
 *
 * @param data : Data to push
 */
template <typename T>
void Stack<T>::push(const T& value) {
    reserve(_index + 1);

    *(_container + ++_index) = value;
}

/**
 * Pop data in `stack`
 */
template <typename T>
void Stack<T>::pop() {
    // Throw exception when accessing null pointer
    if (empty()) {
        throw out_of_range("STACK IS EMPTY");
    }

    _index--;    
}