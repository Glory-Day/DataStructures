#ifndef __STACK_HPP__
#define __STACK_HPP__

template<typename T>
class Stack {
private:
    int _index;     // Current index number of the stack;
    int _capacity;

    T*  _container; // Container where data is stored

    void reserve(const int capacity);

public:
    Stack(int capacity = 1) : _index(-1), _capacity(capacity), _container(nullptr) {
        reserve(capacity);
    }

    ~Stack() {
        if (_container != nullptr) {
            delete[] _container;
        }
    }

    int size() const;

    T& top() const;
    
    bool empty() const;
          
    void push(const T& value);
    void pop();
};

#endif