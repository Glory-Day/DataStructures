#ifndef __SINGLY_LINKED_LIST_HPP__
#define __SINGLY_LINKED_LIST_HPP__

#define SINGLY_LINKED_LIST

#include "node.hpp"

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* _head; // Head of linked list

public:
    /**
     * `Singly Linked List` default constructor
     */
    SinglyLinkedList() : _head{new Node<T>(-1, nullptr)} {}

    void Push(T);
    bool Pop();
    bool Insert(int, T);
    bool Remove(int);
    int  Search(T);
    bool IsEmpty();
    int  Size();
    void Clear();
};

#endif