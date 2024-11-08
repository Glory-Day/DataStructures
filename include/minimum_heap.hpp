#ifndef __MINIMUM_HEAP_HPP__
#define __MINIMUM_HEAP_HPP__

template <typename T>
class MinimumHeap {
private:
    T*  _head;     // Head of elements
    int _capacity; // Maximum possible size
    int _size;     // Current index number of elements

    int GetParentIndex(int);
    int GetLeftChildIndex(int);
    int GetRightChildIndex(int);

    void Heapify(int);

public:
    /**
     * `Minimum Heap` default constructor
     * 
     * @param capacity Maximum possible size
     */
    explicit MinimumHeap(int capacity) : _head{new T[capacity]}, _capacity{capacity}, _size{0} {}

    T Top();
    void Insert(T);
    void Extract();
};

#endif