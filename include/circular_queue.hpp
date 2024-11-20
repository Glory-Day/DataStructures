#ifndef __CIRCULAR_QUEUE_HPP__
#define __CIRCULAR_QUEUE_HPP__

template<typename T>
class CircularQueue
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
    
    void enqueue(T);
    void dequeue();
    T    front();
    bool empty();
};

#endif