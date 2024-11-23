#ifndef __BINARY_HEAP_HPP__
#define __BINARY_HEAP_HPP__

#include <iostream>

#include "heap.hpp"

using namespace std;

template<typename T>
class BinaryHeap : public Heap<T>
{
protected:
    T*  _root;     // Head of elements
    int _capacity; // Maximum possible size
    int _size;     // Current index number of elements

    void reserve(int);
    void push_back(T);
    void pop_back();

    int get_parent_index(int);
    int get_left_child_index(int);
    int get_right_child_index(int);

    virtual void heapify(int) = 0;

    BinaryHeap() : _root{new T[1]}, _capacity{1}, _size{0} {}

    virtual ~BinaryHeap()
    {
        delete[] _root;
    }

public:
    virtual void extract() override final;
    virtual T top() override final;
};

#endif