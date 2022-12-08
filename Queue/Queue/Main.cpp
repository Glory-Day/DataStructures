#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Queue {
private:
    int _size; // Number of queue memory size
    int _head; // Index of queue head
    int _tail; // Index of queue tail
    T* _queue; // Queue where data is stored

public:
    // Default queue constructor
    Queue() : _size(0), _head(-1), _tail(-1), _queue(nullptr) {}

    // Queue constructor to allocate queue memory
    explicit Queue(const int size) : _size(size), _head(-1), _tail(-1), _queue((T*)calloc(size,sizeof(T))) {}

    // Abstract data type, ADT
    void enqueue(T data);
    void dequeue();
    T front();
    bool empty();
};

// Push data in queue
template <typename T>
void Queue<T>::enqueue(T data) {
    try {
        // Throw exception when accessing null pointer
        if (_tail == _size - 1) {
            throw out_of_range("Queue is full.");
        }

        // Store data
        _queue[++_tail] = data;
    }
    catch (out_of_range& exception) {
        cout << " - Exception" << endl;
        cout << exception.what() << endl;
    }
}

// Pop data in queue
template <typename T>
void Queue<T>::dequeue() {
    try {
        // Throw exception when accessing null pointer
        if (empty()) {
            throw out_of_range("Queue is empty.");
        }

        // Increase queue head index
        _head++;
    }
    catch (out_of_range& exception) {
        cout << " - Exception" << endl;
        cout << exception.what() << endl;
    }
}

// Returns the first stored data in the stack
template <typename T>
T Queue<T>::front() {
    T data;

    try {
        // Throw exception when accessing null pointer
        if (empty()) {
            throw out_of_range("Queue is empty.");
        }

        data = _queue[_head + 1];
    }
    catch (out_of_range& exception) {
        cout << " - Exception" << endl;
        cout << exception.what() << endl;
    }

    return data;
}

// Check queue is empty
template <typename T>
bool Queue<T>::empty() {
    return _head == _tail;
}

int main() {
    Queue<int> queue = Queue<int>(10);

    bool isLoop = true;
    while (isLoop) {
        cout << "Data structure - Queue(ADT)" << endl;
        cout << "(1). enqueue()" << endl;
        cout << "(2). dequeue()" << endl;
        cout << "(3). front()" << endl;
        cout << "(4). empty()" << endl;
        cout << " - Input" << endl;

        int index;
        cin >> index;

        switch (index) {
            case 1:
                int data;
                cout << " - Input" << endl;
                cin >> data;
                queue.enqueue(data);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                cout << " - Output" << endl;
                cout << queue.front() << endl;
                break;
            case 4:
                cout << " - Output" << endl;
                cout << (queue.empty() ? "True" : "False") << endl;
                break;
            default:
                isLoop = false;
                break;
        }

        cout << endl;
    }
}