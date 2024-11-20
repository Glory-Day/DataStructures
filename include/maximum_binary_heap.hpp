#ifndef __MAXIMUM_BINARY_HEAP_HPP__
#define __MAXIMUM_BINARY_HEAP_HPP__

template<typename T>
class MaximumBinaryHeap
{
private:
    T*  _root;     // Head of elements
    int _capacity; // Maximum possible size
    int _size;     // Current index number of elements

    void reserve(int);
    void push_back(T);
    void pop_back();

    void heapify(int);

    int get_parent_index(int);
    int get_left_child_index(int);
    int get_right_child_index(int);

public:
    explicit MaximumBinaryHeap() : _root{new T[1]}, _capacity{1}, _size{0} {}

    void insert(T);
    void extract();
    T    top();
};

#endif