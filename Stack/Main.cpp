#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Stack {
private:
    int _index; // Current index number of the stack;
    T*  _stack; // Stack where data is stored

public:
    // Stack constructor
    Stack() : _index(-1), _stack(nullptr) { }

    // Abstract data type, ADT
    void push(T data);
    void pop();
    int top();
    bool empty();
};

// Push data in stack
template <typename T>
void Stack<T>::push(const T data) {
    if (empty()) {
        // Stack is not allocated memory
        _stack = (T*)malloc(sizeof(T));

        // Store data and increase index
        *_stack = data;
        _index++;
    }
    else {
        // Reallocate one more memory increase from the current allocated memory
        int size = (++_index) + 1;
        _stack = (T*)realloc(_stack, sizeof(T) * size);

        // Store data
        *(_stack + _index) = data;
    }
}

// Pop data in stack
template <typename T>
void Stack<T>::pop() {
    try {
        // Throw exception when accessing null pointer
        if (empty()) {
            throw out_of_range("Stack is empty.");
        }

        if (_index == 0) {
            // Returns allocated memory to prevent memory leakage
            free(_stack);
        }
        else {
            // Reallocate one more memory decrease from the current allocated memory
            _stack = (T*)realloc(_stack, sizeof(T) * (_index - 1));
        }
    }
    catch (out_of_range& exception) {
        cout << " - Exception" << endl;
        cout << exception.what() << endl;
    }
}


// Returns the most recently stored data in the stack
template <typename T>
int Stack<T>::top() {
    T data;

    try {
        // Throw exception when accessing null pointer
        if (empty() == true) {
            throw out_of_range("Stack is empty.");
        }

        data = *(_stack + _index);
    }
    catch (out_of_range& exception) {
        cout << " - Exception" << endl;
        cout << exception.what() << endl;
    }

    return data;
}

// Check stack is empty
template <typename T>
bool Stack<T>::empty() {
    return _index == -1;
}

int main() {
    Stack<int> stack = Stack<int>();

    bool isLoop = true;
    while (isLoop) {
        cout << "Data structure - Stack(ADT)" << endl;
        cout << "(1). push()" << endl;
        cout << "(2). pop()" << endl;
        cout << "(3). top()" << endl;
        cout << "(4). empty()" << endl;
        cout << " - Input" << endl;

        int index;
        cin >> index;

        switch (index) {
            case 1:
                cout << " - Input" << endl;

                int data;
                cin >> data;
                stack.push(data);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << " - Output" << endl;
                cout << stack.top() << endl;
                break;
            case 4:
                cout << " - Output" << endl;
                cout << (stack.empty() ? "True" : "False") << endl;
                break;
            default:
                isLoop = false;
                break;
        }

        cout << endl;
    }
}