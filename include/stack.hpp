#ifndef __STACK_HPP__
#define __STACK_HPP__

template<typename T>
class Stack {
private:
    int _index;     // Current index number of the stack;

    T*  _container; // Container where data is stored
    int _capacity;  // 

    void reserve(int capacity);

public:
    Stack(int capacity = 1) : _index(-1), _capacity(capacity), _container(nullptr) 
    {
        _container = new T[capacity];
    }

    ~Stack()
    {
        if (_container != nullptr)
        {
            delete[] _container;

            _container = nullptr;
        }
    }

    int size() const;

    T& top() const;
    
    bool empty() const;
          
    void push(const T& data);
    void pop();
};

#endif