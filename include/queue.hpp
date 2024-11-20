#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#define QUEUE

#include "node.hpp"

template<typename T>
class Queue {
private:
    Node<T>* _begin; // Head of linked list.
    Node<T>* _end;   // Tail of linked list.

    int _size;

public:
    Queue() : _begin{nullptr}, _end{nullptr}, _size(0) {}

    ~Queue()
    {
        while (empty() == false)
        {
            dequeue();
        }

        delete _begin;
        
        _begin = nullptr;
        _end = nullptr;
    }

    void enqueue(T data);
    void dequeue();
    T    front();
    bool empty();
};

#endif