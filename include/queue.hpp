#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

template<typename T>
class Queue
{
public:
    virtual void enqueue(T) = 0;
    virtual void dequeue() = 0;
    virtual T front() = 0;
    virtual bool empty() = 0;
};

#endif