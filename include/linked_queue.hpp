#ifndef __LINKED_QUEUE_HPP__
#define __LINKED_QUEUE_HPP__

#define LINKED_QUEUE

#include "node.hpp"
#include "queue.hpp"

template<typename T>
class LinkedQueue : public Queue<T>
{
private:
    Node<T>* _begin; // Head of linked list.
    Node<T>* _end;   // Tail of linked list.

    int _size;

public:
    LinkedQueue() : _begin{nullptr}, _end{nullptr}, _size(0) {}

    ~LinkedQueue()
    {
        while (empty() == false)
        {
            dequeue();
        }

        delete _begin;
        
        _begin = nullptr;
        _end = nullptr;
    }

    virtual void enqueue(T) override final;
    virtual void dequeue() override final;
    virtual T    front() override final;
    virtual bool empty() override final;
};

#endif