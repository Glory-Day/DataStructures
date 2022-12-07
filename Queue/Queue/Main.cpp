#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Queue {
private:
    int size; // Number of queue memory size
    int head; // Index of queue head
    int tail; // Index of queue tail
    T* queue; // Queue where data is stored

public:
    // Default queue constructor
    Queue() : size(0), head(-1), tail(-1), queue(nullptr) {}

    // Queue constructor to allocate queue memory
    explicit Queue(const int _size) : size(_size), head(-1),tail(-1), queue((T*)calloc(_size,sizeof(T))) {}

    // Abstract data type, ADT
    void push(T data);
    void pop();
    T front();
    bool empty();
};

// Push data in queue
template <typename T>
void Queue<T>::push(T data) {
    try {
        // Throw exception when accessing null pointer
        if (tail == size - 1) {
            throw out_of_range("Queue is full.");
        }

        // Store data
        queue[++tail] = data;
    }
    catch (out_of_range& exception) {
        cout << " - Exception" << endl;
        cout << exception.what() << endl;
    }
}

// Pop data in queue
template <typename T>
void Queue<T>::pop() {
    try {
        // Throw exception when accessing null pointer
        if (empty()) {
            throw out_of_range("Queue is empty.");
        }

        // Increase queue head index
        head++;
    }
    catch (out_of_range& exception) {
        cout << " - Exception" << endl;
        cout << exception.what() << endl;
    }
}

template <typename T>
T Queue<T>::front() {
    T data;

    try {
        // Throw exception when accessing null pointer
        if (empty()) {
            throw out_of_range("Queue is empty.");
        }

        data = queue[head + 1];
    }
    catch (out_of_range& exception) {
        cout << exception.what() << endl;
    }

    return data;
}

// Check queue is empty
template <typename T>
bool Queue<T>::empty() {
    return head == tail;
}

int main() {
    Queue<int> queue = Queue<int>(10);

    bool isLoop = true;
    while (isLoop) {
        cout << "Data structure - Queue(ADT)" << endl;
        cout << "(1). push()" << endl;
        cout << "(2). pop()" << endl;
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
                queue.push(data);
                break;
            case 2:
                queue.pop();
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