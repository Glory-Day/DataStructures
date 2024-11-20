#include <iostream>
#include <string>
#include <vector>

#include "doubly_linked_list.hpp"

using namespace std;

/**
 * Push data in front of `Singly Linked List`
 * 
 * @param data Data to push in linked list
 */
template<typename T>
void DoublyLinkedList<T>::push(T data)
{
    Node<T>* node = new Node(data);

    if (empty())
    {
        _begin = _end = node;
    }
    else
    {
        _end->set_next_node(node);
        node->set_previous_node(_end);

        _end = _end->get_next_node();
    }

    _size++;
}

/**
 * Pop data in front of `Singly Linked List`
 */
template<typename T>
void DoublyLinkedList<T>::pop()
{
    // Throw exception when accessing null pointer
    if (empty())
    {
        throw out_of_range("LINKED LIST IS EMPTY");
    }

    if (1 < _size)
    {
        Node<T>* previous = _end->get_previous_node();
        previous->set_next_node(nullptr);

        delete _end;

        _end = previous;
    }
    else
    {
        delete _begin;

        _begin = _end = nullptr;
    }

    _size--;
}

/**
 * Insert data into the specified index of `Singly Linked List`
 * 
 * @param index Number of index
 * @param data Data to insert
 */
template<typename T>
void DoublyLinkedList<T>::insert(int index, T data)
{
    // Throw exception when index is out of range in linked list
    if ((0 <= index && index <= _size) == false)
    {
        throw out_of_range("INDEX IS OUT OF RANGE");
    }

    Node<T>* node = new Node<T>(data);

    if (empty() || index == _size)
    {
        push(data);

        return;
    }

    if (index == 0)
    {
        node->set_next_node(_begin);
        _begin->set_previous_node(node);

        _begin = node;
    }
    else
    {
        Node<T>* current = _begin;
        for (int i = 0; i < index; i++)
        {
            current = current->get_next_node();
        }

        node->set_previous_node(current->get_previous_node());
        node->set_next_node(current);
        current->get_previous_node()->set_next_node(node);
        current->set_previous_node(node);
    }

    _size++;
}

/**
 * Remove data into the specified index in `Singly Linked List`
 * 
 * @param index Number of index
 * 
 * @return Check data is removed or not
 */
template<typename T>
void DoublyLinkedList<T>::remove(int index)
{
    // Throw exception when index is out of range in singly linked list
    if ((0 <= index && index <= _size) == false)
    {
        throw out_of_range("INDEX IS OUT OF RANGE");
    }

    if (index == _size - 1)
    {
        pop();

        return;
    }
    
    if (index == 0)
    {
        Node<T>* next = _begin->get_next_node();
        next->set_previous_node(nullptr);

        delete _begin;

        _begin = next;
    }
    else
    {
        Node<T>* current = _begin;
        for (int i = 0; i < index; i++)
        {
            current = current->get_next_node();
        }

        current->get_previous_node()->set_next_node(current->get_next_node());
        current->get_next_node()->set_previous_node(current->get_previous_node());

        delete current;
    }

    _size--;
}

/**
 * Search data in `Singly Linked List`
 * 
 * @param data Data to search
 * @return If data is found, returns index of node, else returns `-1`
 */
template<typename T>
int DoublyLinkedList<T>::search(T data)
{
    int index = 0;
    Node<T>* current = _begin;
    while (current != nullptr)
    {
        if (current->get_data() == data)
        {
            return index;
        }

        index++;
    }

    return -1;
}

/**
 * @return Check linked list is empty or not
 */
template<typename T>
bool DoublyLinkedList<T>::empty()
{
    return _begin == nullptr && _end == nullptr;
}

/**
 * @return Size of nodes in `Singly Linked List`
 */
template<typename T>
int DoublyLinkedList<T>::size()
{
    return _size;
}

/**
 * Clear all nodes.
 */
template<typename T>
void DoublyLinkedList<T>::clear()
{
    while (empty() == false)
    {
        pop();
    }
}

template<typename T>
vector<string> DoublyLinkedList<T>::display()
{
    vector<string> output;
    
    string line = "";

    Node<T>* current = _begin;
    while (current != nullptr)
    {
        line += to_string(current->get_data());
        line += " ";

        current = current->get_next_node();
    }

    output.push_back(line);
    line.clear();

    current = _end;
    while (current != nullptr)
    {
        line += to_string(current->get_data());
        line += " ";

        current = current->get_previous_node();
    }

    output.push_back(line);
    line.clear();

    return output;
}