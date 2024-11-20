#include <iostream>

#include "circular_queue.hpp"

using namespace std;

template<typename T>
void CircularQueue<T>::reserve(int capacity)
{
    T* container = new T[capacity];
    for (int i = 0; i < _size; i++)
    {
        container[i] = _container[(_front + i + 1) % _capacity];
    }

    _capacity = capacity;
    
    _front = -1;
    _back = _size - 1;

    _container = container;
}

/**
 * @return First stored data in `Circular Queue`
 */
template<typename T>
T CircularQueue<T>::front()
{
    // Throw exception when accessing null pointer
    if (empty())
    {
        throw out_of_range("QUEUE IS EMPTY");
    }

    return _container[(_front + 1) % _capacity];
}

/**
 * @return Check circular queue is empty or not
 */
template<typename T>
bool CircularQueue<T>::empty()
{
    return _size == 0;
}

/**
 * Push data in `Circular Queue`
 * 
 * @param data : Data to push
 */
template<typename T>
void CircularQueue<T>::enqueue(T data)
{
    if (_size == _capacity)
    {
        reserve(_capacity * 2);
    }

    _back = (_back + 1) % _capacity;
    _container[_back] = data;

    _size++;
}

/**
 * Pop data in `Circular Queue`
 */
template<typename T>
void CircularQueue<T>::dequeue()
{
    // Throw exception when accessing null pointer
    if (empty())
    {
        throw out_of_range("QUEUE IS EMPTY");
    }

    _front = (_front + 1) % _capacity;
    _size--;

    if (_size == 0)
    {
        _front = _back = -1;

        return;       
    }

    if (_size == _capacity / 2)
    {
        reserve(_capacity / 2);
    }
}