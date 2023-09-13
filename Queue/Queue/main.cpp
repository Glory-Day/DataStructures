#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Queue {
private:
    int _size; // Number of queue memory size
    int _head; // Head of queue index
    int _tail; // Tail of queue index
    T* _queue; // Queue where data is stored

public:
    /**
     * Default queue constructor
     */
    Queue() : _size(0), _head(-1), _tail(-1), _queue(nullptr) {}

    /**
     * Queue constructor to allocate queue memory
     * 
     * @param size : Size of allocating queue memory
     */
    explicit Queue(const int size) : _size(size), _head(-1), _tail(-1), _queue((T*)calloc(size,sizeof(T))) {}

    T GetFront();
    bool IsEmpty();
    void Enqueue(T data);
    void Dequeue();
};

/**
 * Add data in queue
 * 
 * @tparam T : Data type
 * @param data : Data to add
 */
template <typename T>
void Queue<T>::Enqueue(T data) {
    try {
        // Throw exception when accessing null pointer
        if (_tail == _size - 1) {
            throw out_of_range("Queue is full");
        }

        // Store data
        _queue[++_tail] = data;
    }
    catch (out_of_range& exception) {
        cout << " - Exception : " << exception.what() << endl;
    }
}

/**
 * Remove data in queue
 * 
 * @tparam T : Data type
 */
template <typename T>
void Queue<T>::Dequeue() {
    try {
        // Throw exception when accessing null pointer
        if (IsEmpty()) {
            throw out_of_range("Queue is empty");
        }

        // Increase queue head index
        _head++;
    }
    catch (out_of_range& exception) {
        cout << " - Exception : " << exception.what() << endl;
    }
}

/**
 * Returns the first stored data in the queue
 * 
 * @tparam T : Data type
 * @return First stored data in the queue
 */
template <typename T>
T Queue<T>::GetFront() {
    T data;

    try {
        // Throw exception when accessing null pointer
        if (IsEmpty()) {
            throw out_of_range("Queue is empty");
        }

        data = _queue[_head + 1];
    }
    catch (out_of_range& exception) {
        cout << " - Exception : " << exception.what() << endl;
    }

    return data;
}

/**
 * Check queue is empty
 * 
 * @tparam T : Data type
 * @return Queue is empty or not
 */
template <typename T>
bool Queue<T>::IsEmpty() {
    return _head == _tail;
}

int main() {
    Queue<int> queue = Queue<int>(10);

    bool isLoop = true;
    while (isLoop) {
        cout << "Data structure - Queue(ADT)" << endl;
        cout << "(1). Enqueue" << endl;
        cout << "(2). Dequeue" << endl;
        cout << "(3). Get front data in queue" << endl;
        cout << "(4). Check queue is empty" << endl;
        cout << " - Input" << endl;

        int index;
        cin >> index;

        switch (index) {
            case 1:
                int data;
                cout << " - Input" << endl;
                cin >> data;
                queue.Enqueue(data);
                break;
            case 2:
                queue.Dequeue();
                break;
            case 3:
                cout << " - Output" << endl;
                cout << queue.GetFront() << endl;
                break;
            case 4:
                cout << " - Output" << endl;
                cout << (queue.IsEmpty() ? "True" : "False") << endl;
                break;
            default:
                isLoop = false;
                break;
        }

        cout << endl;
    }
}