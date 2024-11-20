#ifndef __DOUBLY_LINKED_LIST_HPP__
#define __DOUBLY_LINKED_LIST_HPP__

#define DOUBLY_LINKED_LIST

#include <string>

#include "node.hpp"

using namespace std;

template<typename T>
class DoublyLinkedList
{
private:
    Node<T>* _begin; // Head of linked list.
    Node<T>* _end;   // Tail of linked list.

    int _size;

public:
    DoublyLinkedList() : _begin{nullptr}, _end{nullptr}, _size(0) {}

    ~DoublyLinkedList()
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

    vector<string> display();
};

#endif