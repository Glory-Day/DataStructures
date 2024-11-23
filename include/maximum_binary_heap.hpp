#ifndef __MAXIMUM_BINARY_HEAP_HPP__
#define __MAXIMUM_BINARY_HEAP_HPP__

#include "binary_heap.hpp"

template<typename T>
class MaximumBinaryHeap : public BinaryHeap<T>
{
protected:
    void heapify(int index) override final;

public:
    explicit MaximumBinaryHeap() : BinaryHeap<T>() {}

    void insert(T data) override final;
};

#endif