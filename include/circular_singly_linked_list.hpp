#ifndef __CIRCULAR_SINGLY_LINKED_LIST_HPP__
#define __CIRCULAR_SINGLY_LINKED_LIST_HPP__

#define SINGLY_LINKED_LIST

#include <string>

#include "node.hpp"

using namespace std;

template<typename T>
class CircularSinglyLinkedList
{
private:
    Node<T>* _begin; // Head of linked list.
    Node<T>* _end;   // Tail of linked list.

    int _size;

public:
    CircularSinglyLinkedList() : _begin{nullptr}, _end{nullptr}, _size(0) {}

    ~CircularSinglyLinkedList()
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

    string display(int);
};

#endif