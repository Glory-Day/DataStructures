#ifndef __CIRCULAR_QUEUE_HPP__
#define __CIRCULAR_QUEUE_HPP__

#include "queue.hpp"

template<typename T>
class CircularQueue : public Queue<T>
{
private:
    int _capacity;  // Number of container memory size.
    int _size;
    int _front;     // Head of queue index
    int _back;      // Tail of queue index
    T*  _container; // Queue where data is stored

    void reserve(int);

public:
    explicit CircularQueue() : _capacity(1), _size(0), _front(-1), _back(-1), _container(new T[1]) { }
    
    virtual void enqueue(T) override final;
    virtual void dequeue() override final;
    virtual T    front() override final;
    virtual bool empty() override final;
};

#endif