#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Stack {
private:
    int _index; // Current index number of the stack;
    T*  _stack; // Stack where data is stored

public:
    /**
     * Default stack constructor
     */
    Stack() : _index(-1), _stack(nullptr) { }

    T Top();
    bool IsEmpty();
    void Push(T data);
    void Pop();
};

/**
 * Returns the first stored data in the stack
 * 
 * @tparam T : Data type
 * @return First stored data in the stack
 */
template <typename T>
T Stack<T>::Top() {
    T data;

    try {
        // Throw exception when accessing null pointer
        if (IsEmpty()) {
            throw out_of_range("Stack is empty");
        }

        data = *(_stack + _index);
    }
    catch (out_of_range& exception) {
        cout << " - Exception : " << exception.what() << endl;
    }

    return data;
}

/**
 * Check stack is empty
 * 
 * @tparam T : Data type
 * @return Stack is empty or not
 */
template <typename T>
bool Stack<T>::IsEmpty() {
    return _index == -1;
}

/**
 * Push data in stack
 * 
 * @tparam T : Data type
 * @param data : Data to add
 */
template <typename T>
void Stack<T>::Push(const T data) {
    if (IsEmpty()) {
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

/**
 * Pop data in stack
 * 
 * @tparam T : Data type
 */
template <typename T>
void Stack<T>::Pop() {
    try {
        // Throw exception when accessing null pointer
        if (IsEmpty()) {
            throw out_of_range("Stack is empty");
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
        cout << " - Exception : " << exception.what() << endl;
    }
}

int main() {
    Stack<int> stack = Stack<int>();

    bool isLoop = true;
    while (isLoop) {
        cout << "Data structure - Stack(ADT)" << endl;
        cout << "(1). Push data" << endl;
        cout << "(2). Pop data" << endl;
        cout << "(3). Get top data in stack" << endl;
        cout << "(4). Check stack is empty" << endl;
        cout << " - Input" << endl;

        int index;
        cin >> index;

        switch (index) {
            case 1:
                cout << " - Input" << endl;

                int data;
                cin >> data;
                stack.Push(data);
                break;
            case 2:
                stack.Pop();
                break;
            case 3:
                cout << " - Output" << endl;
                cout << stack.Top() << endl;
                break;
            case 4:
                cout << " - Output" << endl;
                cout << (stack.IsEmpty() ? "True" : "False") << endl;
                break;
            default:
                isLoop = false;
                break;
        }

        cout << endl;
    }
}