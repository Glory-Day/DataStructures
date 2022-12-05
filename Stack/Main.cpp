#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Stack {
private:
    // Current index number of the stack;
    int index;
    // Stack where data is stored
    T* stack;

public:
    // Stack constructor
    Stack() : index(-1), stack(nullptr) { }

    // Abstract data type, ADT
    int top();
    void push(T data);
    void pop();
    bool empty();
};

// Returns the most recently stored data in the stack
template <typename T>
int Stack<T>::top() {
    int data;

    try {
        // Throw exception when accessing NULL pointer
        if (empty() == true) {
            throw out_of_range("Stack is empty.");
        }

        data = *(stack + index);
    }
    catch (out_of_range& exception) {
        cout << exception.what() << endl;
    }

    return data;
}

// Push data in a stack
template <typename T>
void Stack<T>::push(T data) {
    if (empty()) {
        // Stack is not allocated memory
        stack = (T*)malloc(sizeof(T));

        // Store data and increase index
        *stack = data;
        index++;
    }
    else {
        // Reallocate one more memory increase from the current allocated memory
        int size = (++index) + 1;
        stack = (T*)realloc(stack, sizeof(T) * size);

        // Store data
        *(stack + index) = data;
    }
}

// Pop data in stack
template <typename T>
void Stack<T>::pop() {
    try {
        // Throw exception when accessing NULL pointer
        if (empty()) {
            throw out_of_range("Stack is empty.");
        }

        // Get popped stack size
        int size = (--index) + 1;
        if (size == 0) {
            free(stack);
        }
        else {
            // Reallocate one more memory decrease from the current allocated memory
            stack = (T*)realloc(stack, sizeof(T) * size);
        }
    }
    catch (out_of_range& exception) {
        cout << exception.what() << endl;
    }
}

// Check stack is empty
template <typename T>
bool Stack<T>::empty() {
    return index == -1;
}

int main() {
    Stack<int> stack = Stack<int>();

    cout << "Data structure - Stack" << endl;
    cout << "(1). Push data in stack" << endl;
    cout << "(2). Pop data in stack" << endl;
    cout << "(3). Show data in stack" << endl;
    cout << "(4). Check stack is empty" << endl;
    cout << "(5). Exit" << endl;

    bool isLoop = true;
    while (isLoop) {
        int index;
        cin >> index;
        switch (index) {
            case 1:
                int data;
                cin >> data;
                stack.push(data);
                cout << "Pushed " << data << " in stack" << endl;
                break;
            case 2:
                stack.pop();
                cout << "Popped stack" << endl;
                break;
            case 3:
                cout << "Top of stack is " << stack.top() << endl;
                break;
            case 4:
                cout << (stack.empty() ? "True" : "False") << endl;
                break;
            default:
                isLoop = false;
                break;
        }
    }
}