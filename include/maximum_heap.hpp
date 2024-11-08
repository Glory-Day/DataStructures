#ifndef __MAXIMUM_HEAP_HPP__
#define __MAXIMUM_HEAP_HPP__

template <typename T>
class MaximumHeap {
private:
    T*  _head;     // Head of elements
    int _capacity; // Maximum possible size
    int _size;     // Current index number of elements

    void Heapify(int);

    int GetParentIndex(int);
    int GetLeftChildIndex(int);
    int GetRightChildIndex(int);

public:
    /**
     * `Maximum Heap` default constructor
     * 
     * @param capacity Maximum possible size
     */
    explicit MaximumHeap(int capacity) : _head{new T[capacity]}, _capacity{capacity}, _size{0} {}

    T Top();
    void Insert(T);
    void Extract();
};

#endif