#ifndef __STACK_HPP__
#define __STACK_HPP__

template<typename T>
class Stack {
private:
    int _index;     // Current index number of the stack;
    T*  _container; // Container where data is stored

public:
    /**
     * `Stack` default constructor
     */
    Stack() : _index(-1), _container(nullptr) { }

    const T Top();
    
    const bool IsEmpty();
          
    void Push(const T data);
    void Pop();
};

#endif