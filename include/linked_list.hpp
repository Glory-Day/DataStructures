#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

#include <string>
#include <vector>

using namespace std;

template<typename T1, typename T2>
class LinkedList
{
protected:
    T1* _begin; // Head of linked list.
    T1* _end;   // Tail of linked list.

    int _size;

    LinkedList() : _begin{nullptr}, _end{nullptr}, _size(0) {}

    virtual ~LinkedList()
    {
        clear();
    }

public:
    virtual void push(T2) = 0;
    virtual void pop() = 0;
    virtual void insert(int, T2) = 0;
    virtual void remove(int) = 0;
    virtual int  search(T2) = 0;

    bool empty();
    int  size();
    void clear();
};

#endif