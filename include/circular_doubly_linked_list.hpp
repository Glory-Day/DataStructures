#ifndef __CIRCULAR_DOUBLY_LINKED_LIST_HPP__
#define __CIRCULAR_DOUBLY_LINKED_LIST_HPP__

#define DOUBLY_LINKED_LIST

#include <string>

#include "node.hpp"

using namespace std;

template<typename T>
class CircularDoublyLinkedList
{
private:
    Node<T>* _begin; // Head of linked list.
    Node<T>* _end;   // Tail of linked list.

    int _size;

public:
    CircularDoublyLinkedList() : _begin{nullptr}, _end{nullptr}, _size(0) {}

    ~CircularDoublyLinkedList()
    {
        clear();

        delete _begin;
        
        _begin = nullptr;
        _end = nullptr;
    }

    void push(T);
    void pop();
    void insert(int, T);
    void remove(int);
    int  search(T);
    bool empty();
    int  size();
    void clear();

    vector<string> display(int);
};

#endif