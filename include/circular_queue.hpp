#ifndef __CIRCULAR_QUEUE_HPP__
#define __CIRCULAR_QUEUE_HPP__

template <typename T>
class CircularQueue {
    int _size;  // Number of queue memory size
    int _head;  // Head of queue index
    int _tail;  // Tail of queue index
    T*  _queue; // Queue where data is stored

public:
    /**
     * `Circular Queue` default constructor
     */
    CircularQueue() : _size(0), _head(-1), _tail(-1), _queue(nullptr) {}

    /**
     * `Circular Queue` constructor to allocate queue memory
     * 
     * @param size : Size of allocating queue memory
     */
    explicit CircularQueue(const int size) : _size(size), _head(-1), _tail(-1), _queue((T*)calloc(size, sizeof(T))) {}

    T    Front();
    bool IsEmpty();
    void Enqueue(T data);
    void Dequeue();
};

#endif