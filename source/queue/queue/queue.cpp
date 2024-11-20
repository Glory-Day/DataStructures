#include <iostream>
#include <cstdlib>

#include "queue.hpp"

using namespace std;

/**
 * Push data in `queue`
 *
 * @param data : Data to push
 */
template<typename T>
void Queue<T>::enqueue(T data)
{
    Node<T>* node = new Node(data);

    if (empty())
    {
        _begin = _end = node;
    }
    else
    {
        _end->set_next_node(node);
        _end = _end->get_next_node();
    }

    _size++;
}

/**
 * Pop data in `queue`
 */
template<typename T>
void Queue<T>::dequeue()
{
    // Throw exception when accessing null pointer
    if (empty())
    {
        throw out_of_range("QUEUE IS EMPTY");
    }

    if (_size == 1)
    {
        delete _begin;

        _begin = _end = nullptr;
    }
    else
    {
        Node<T>* next = _begin->get_next_node();

        delete _begin;

        _begin = next;
    }

    _size--;
}

/**
 * @return First stored data in `queue`
 */
template<typename T>
T Queue<T>::front()
{
    // Throw exception when accessing null pointer
    if (empty())
    {
        throw out_of_range("QUEUE IS EMPTY");
    }

    return _begin->get_data();
}

/**
 * @return Check queue is empty or not
 */
template<typename T>
bool Queue<T>::empty()
{
    return _begin == nullptr && _end == nullptr;
}