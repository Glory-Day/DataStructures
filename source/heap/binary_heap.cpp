#include "binary_heap.hpp"

template<typename T>
void BinaryHeap<T>::reserve(int capacity)
{
    this->_capacity = capacity;

    T* root = new T[capacity];
    for (int i = 0; i < this->_size; i++)
    {
        root[i] = this->_root[i];
    }

    delete[] this->_root;

    this->_root = root;
}

template<typename T>
void BinaryHeap<T>::push_back(T data)
{
    if (this->_size == this->_capacity)
    {
        reserve(this->_capacity * 2);
    }

    this->_root[_size++] = data;
}

template<typename T>
void BinaryHeap<T>::pop_back()
{
    if (this->_size == 0)
    {
        throw new out_of_range("HEAP IS EMPTY");
    }

    this->_size--;
    
    if (this->_size == this->_capacity / 2)
    {
        reserve(this->_capacity / 2);
    }
}

/**
 * @param index Index number of node
 * @return Get index number of parent node
 */
template <typename T>
int BinaryHeap<T>::get_parent_index(int index)
{
    return (index - 1) / 2;
}

/**
 * @param index Index number of node
 * @return Get index number of left child node
 */
template <typename T>
int BinaryHeap<T>::get_left_child_index(int index)
{
    return index * 2 + 1;
}

/**
 * @param index Index number of node
 * @return Get index number of right child node
 */
template <typename T>
int BinaryHeap<T>::get_right_child_index(int index)
{
    return index * 2 + 2;
}

template <typename T>
void BinaryHeap<T>::extract()
{
    swap(_root[0], _root[_size - 1]);
    
    pop_back();

    heapify(0);
}

template <typename T>
T BinaryHeap<T>::top()
{
    if (_size == 0)
    {
        throw out_of_range("HEAP IS EMPTY");
    }

    return _root[0];
}