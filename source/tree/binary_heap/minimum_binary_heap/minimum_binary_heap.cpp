#include <iostream>
#include <algorithm>

#include "minimum_binary_heap.hpp"

using namespace std;

template<typename T>
void MinimumBinaryHeap<T>::reserve(int capacity)
{
    _capacity = capacity;

    T* root = new T[capacity];
    for (int i = 0; i < _size; i++)
    {
        root[i] = _root[i];
    }

    delete[] _root;

    _root = root;
}

template<typename T>
void MinimumBinaryHeap<T>::push_back(T data)
{
    if (_size == _capacity)
    {
        reserve(_capacity * 2);
    }

    _root[_size++] = data;
}

template<typename T>
void MinimumBinaryHeap<T>::pop_back()
{
    if (_size == 0)
    {
        throw new out_of_range("HEAP IS EMPTY");
    }

    _size--;
    
    if (_size == _capacity / 2)
    {
        reserve(_capacity / 2);
    }
}

/**
 * @param index Index number of node
 * @return Get index number of parent node
 */
template <typename T>
int MinimumBinaryHeap<T>::get_parent_index(int index)
{
    return (index - 1) / 2;
}

/**
 * @param index Index number of node
 * @return Get index number of left child node
 */
template <typename T>
int MinimumBinaryHeap<T>::get_left_child_index(int index)
{
    return index * 2 + 1;
}

/**
 * @param index Index number of node
 * @return Get index number of right child node
 */
template <typename T>
int MinimumBinaryHeap<T>::get_right_child_index(int index)
{
    return index * 2 + 2;
}

/**
 * heapify a subtree with the root at given index
 * 
 * @param index Index number of node
 */
template <typename T>
void MinimumBinaryHeap<T>::heapify(int index)
{
    while (get_left_child_index(index) < _size - 1)
    {
        int left_child_index = get_left_child_index(index);
        int right_child_index = get_right_child_index(index);

        int updated_index = get_left_child_index(index);
        if (right_child_index < _size && _root[left_child_index] > _root[right_child_index])
        {
            updated_index = right_child_index;
        }

        if (_root[updated_index] > _root[index] || _root[updated_index] == _root[index])
        {
            break;
        }
        else
        {
            swap(_root[index], _root[updated_index]);

            index = updated_index;
        }
    }
}

/**
 * @return Get data from `Minimum Heap`
 */
template <typename T>
T MinimumBinaryHeap<T>::top()
{
    if (_size == 0)
    {
        throw out_of_range("HEAP IS EMPTY");
    }

    return _root[0];
}

/**
 * Inserts a new data in `Minimum Heap`
 * 
 * @param data New data
 */
template <typename T>
void MinimumBinaryHeap<T>::insert(T data)
{
    push_back(data);

    int index = _size - 1;
    while (index != 0 && _root[get_parent_index(index)] > _root[index])
    {
        swap(_root[index], _root[get_parent_index(index)]);
        
        index = get_parent_index(index);
    }
}

/**
 * Remove data from `Minimum Heap`
 */
template <typename T>
void MinimumBinaryHeap<T>::extract()
{
    swap(_root[0], _root[_size - 1]);
    
    pop_back();

    heapify(0);
}