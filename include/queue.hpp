#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

template <typename T>
class Queue {
private:
    int _size;  // Number of queue memory size
    int _head;  // Head of queue index
    int _tail;  // Tail of queue index
    T*  _queue; // Queue where data is stored

public:
    /**
     * `Queue` default constructor
     */
    Queue() : _size(0), _head(-1), _tail(-1), _queue(nullptr) {}

    /**
     * `Queue` constructor to allocate queue memory
     * 
     * @param size : Size of allocating queue memory
     */
    explicit Queue(const int size) : _size(size), _head(-1), _tail(-1), _queue((T*)calloc(size,sizeof(T))) {}

    T    Front();
    bool IsEmpty();
    void Enqueue(T data);
    void Dequeue();
};

#endif