#include <iostream>
#include <cstdlib>

#include "stack.hpp"

using namespace std;

template<typename T>
int Stack<T>::size() const
{
    return _index + 1;
}

template<typename T>
void Stack<T>::reserve(int capacity)
{
    T* container = new T[capacity];
    
    memcpy(container, _container, sizeof(T) * size());

    _container = container;
    _capacity = capacity;
}

/**
 * @return First stored data in `stack`
 */
template<typename T>
T& Stack<T>::top() const
{
    // Throw exception when accessing null pointer
    if (empty() == true) {
        throw out_of_range("STACK IS EMPTY");
    }

    return *(_container + _index);
}

/**
 * @return Check stack is empty or not
 */
template<typename T>
bool Stack<T>::empty() const
{
    return _index == -1;
}

/**
 * Push data in `stack`
 *
 * @param data : Data to push
 */
template<typename T>
void Stack<T>::push(const T& data)
{
    if (size() == _capacity)
    {
        reserve(_capacity * 2);
    }

    *(_container + ++_index) = data;
}

/**
 * Pop data in `stack`
 */
template<typename T>
void Stack<T>::pop()
{
    // Throw exception when accessing null pointer
    if (empty() == true)
    {
        throw out_of_range("STACK IS EMPTY");
    }

    _index--;

    if (size() == _capacity / 2)
    {
        reserve(_capacity / 2);
    }    
}