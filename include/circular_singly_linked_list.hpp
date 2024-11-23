#ifndef __CIRCULAR_SINGLY_LINKED_LIST_HPP__
#define __CIRCULAR_SINGLY_LINKED_LIST_HPP__

#define SINGLY_LINKED_LIST

#include <string>

#include "node.hpp"
#include "linked_list.hpp"

using namespace std;

template<typename T>
class CircularSinglyLinkedList : public LinkedList<Node<T>, T>
{
public:
    CircularSinglyLinkedList() : LinkedList<Node<T>, T>() {}

    virtual void push(T) override final;
    virtual void pop() override final;
    virtual void insert(int, T) override final;
    virtual void remove(int) override final;
    virtual int  search(T) override final;

    string display(int);
};

#endif