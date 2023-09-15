#include <iostream>
#include <cstdlib>

template <typename T>
class CircularQueue {
    int _size; // Number of queue memory size
    int _head; // Head of queue index
    int _tail; // Tail of queue index
    T* _queue; // Queue where data is stored

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

    T Front();
    bool IsEmpty();
    void Enqueue(T data);
    void Dequeue();
};

/**
 * @return First stored data in `Circular Queue`
 */
template <typename T>
T CircularQueue<T>::Front() {
    T data;

    try {
        // Throw exception when accessing null pointer
        if (IsEmpty()) {
            throw std::out_of_range("Circular queue is empty");
        }

        data = _queue[(_head + 1) % _size];
    }
    catch (std::out_of_range& exception) {
        std::cout << " - Exception : " << exception.what() << std::endl;
    }

    return data;
}

/**
 * @return Check circular queue is empty or not
 */
template <typename T>
bool CircularQueue<T>::IsEmpty() {
    return _head == _tail;
}

/**
 * Push data in `Circular Queue`
 * 
 * @param data : Data to push
 */
template <typename T>
void CircularQueue<T>::Enqueue(T data) {
    try {
        // Throw exception when accessing null pointer
        if ((_head == -1 && _tail == (_size - 1)) || (_head == ((_tail + 1) % _size))) {
            throw std::out_of_range("Circular queue is full");
        }

        // Calculate increased tail index and stored data
        _tail = (_tail + 1) % _size;
        _queue[_tail] = data;
    }
    catch (std::out_of_range& exception) {
        std::cout << " - Exception : " << exception.what() << std::endl;
    }
}

/**
 * Pop data in `Circular Queue`
 */
template <typename T>
void CircularQueue<T>::Dequeue() {
    try {
        // Throw exception when accessing null pointer
        if (IsEmpty()) {
            throw std::out_of_range("Circular queue is empty");
        }

        // Calculate increased head index
        _head = (_head + 1) % _size;
    }
    catch (std::out_of_range& exception) {
        std::cout << " - Exception : " << exception.what() << std::endl;
    }
}