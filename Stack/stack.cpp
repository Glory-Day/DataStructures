#include <iostream>
#include <cstdlib>

template <typename T>
class Stack {
private:
    int _index; // Current index number of the stack;
    T*  _stack; // Stack where data is stored

public:
    /**
     * `Stack` default constructor
     */
    Stack() : _index(-1), _stack(nullptr) { }

    T    Top();
    bool IsEmpty();
    void Push(T data);
    void Pop();
};

/**
 * @return First stored data in `stack`
 */
template <typename T>
T Stack<T>::Top() {
    T data;

    try {
        // Throw exception when accessing null pointer
        if (IsEmpty()) {
            throw std::out_of_range("Stack is empty");
        }

        data = *(_stack + _index);
    }
    catch (std::out_of_range& exception) {
        std::cout << " - Exception : " << exception.what() << std::endl;
    }

    return data;
}

/**
 * @return Check stack is empty or not
 */
template <typename T>
bool Stack<T>::IsEmpty() {
    return _index == -1;
}

/**
 * Push data in `stack`
 *
 * @param data : Data to push
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
 * Pop data in `stack`
 */
template <typename T>
void Stack<T>::Pop() {
    try {
        // Throw exception when accessing null pointer
        if (IsEmpty()) {
            throw std::out_of_range("Stack is empty");
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
    catch (std::out_of_range& exception) {
        std::cout << " - Exception : " << exception.what() << std::endl;
    }
}