#ifndef __MINIMUM_BINARY_HEAP_HPP__
#define __MINIMUM_BINARY_HEAP_HPP__

#include "binary_heap.hpp"

template<typename T>
class MinimumBinaryHeap : public BinaryHeap<T>
{
protected:
    void heapify(int index) override final;

public:
    explicit MinimumBinaryHeap() : BinaryHeap<T>() {}

    void insert(T data) override final;
};

#endif