#ifndef __HEAP_HPP__
#define __HEAP_HPP__

template<typename T>
class Heap
{
public:
    virtual void insert(T) = 0;
    virtual void extract() = 0;
    virtual T top() = 0;
};

#endif