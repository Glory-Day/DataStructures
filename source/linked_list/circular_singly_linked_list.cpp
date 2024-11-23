#include <iostream>
#include <string>

#include "circular_singly_linked_list.hpp"

#include "linked_list.cpp"

using namespace std;

/**
 * Push data in front of `Singly Linked List`
 * 
 * @param data Data to push in linked list
 */
template<typename T>
void CircularSinglyLinkedList<T>::push(T data)
{
    Node<T>* node = new Node(data);

    if (this->empty())
    {
        this->_begin = this->_end = node;

        this->_end->set_next_node(this->_begin);
    }
    else
    {
        this->_end->set_next_node(node);
        this->_end = this->_end->get_next_node();

        this->_end->set_next_node(this->_begin);
    }

    this->_size++;
}

/**
 * Pop data in front of `Singly Linked List`
 * 
 * @return Check data is popped or not
 */
template<typename T>
void CircularSinglyLinkedList<T>::pop()
{
    // Throw exception when accessing null pointer
    if (this->empty())
    {
        throw out_of_range("LINKED LIST IS EMPTY");
    }

    if (this->_size == 1)
    {
        delete this->_begin;

        this->_begin = this->_end = nullptr;
    }
    else
    {
        Node<T>* current = this->_begin;
        while (current->get_next_node() != this->_end)
        {
            current = current->get_next_node();
        }

        current->set_next_node(nullptr);

        delete this->_end;

        this->_end = current;

        this->_end->set_next_node(this->_begin);
    }

    this->_size--;
}

/**
 * Insert data into the specified index of `Singly Linked List`
 * 
 * @param index Number of index
 * @param data Data to insert
 * 
 * @return Check data is inserted or not
 */
template<typename T>
void CircularSinglyLinkedList<T>::insert(int index, T data)
{
    // Throw exception when index is out of range in linked list
    if ((0 <= index && index <= this->_size) == false)
    {
        throw out_of_range("INDEX IS OUT OF RANGE");
    }

    Node<T>* node = new Node<T>(data);

    if (this->empty() || index == this->_size)
    {
        push(data);

        return;
    }

    if (index == 0)
    {
        node->set_next_node(this->_begin);

        this->_begin = node;

        this->_end->set_next_node(this->_begin);
    }
    else
    {
        Node<T>* current = this->_begin;
        for (int i = 0; i < index; i++)
        {
            current = current->get_next_node();
        }

        node->set_next_node(current->get_next_node());
        current->set_next_node(node);
    }

    this->_size++;
}

/**
 * Remove data into the specified index in `Singly Linked List`
 * 
 * @param index Number of index
 * 
 * @return Check data is removed or not
 */
template<typename T>
void CircularSinglyLinkedList<T>::remove(int index)
{
    // Throw exception when index is out of range in singly linked list
    if ((0 <= index && index <= this->_size) == false)
    {
        throw out_of_range("INDEX IS OUT OF RANGE");
    }

    if (index == this->_size - 1)
    {
        pop();

        return;
    }
    
    if (index == 0)
    {
        Node<T>* next = this->_begin->get_next_node();

        delete this->_begin;

        this->_begin = next;

        this->_end->set_next_node(this->_begin);
    }
    else
    {
        Node<T>* current = this->_begin;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->get_next_node();
        }

        Node<T>* next = current->get_next_node()->get_next_node();

        delete current->get_next_node();

        current->set_next_node(next);
    }

    this->_size--;
}

/**
 * Search data in `Singly Linked List`
 * 
 * @param data Data to search
 * @return If data is found, returns index of node, else returns `-1`
 */
template<typename T>
int CircularSinglyLinkedList<T>::search(T data)
{
    int index = 0;
    Node<T>* current = this->_begin;
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

template<typename T>
string CircularSinglyLinkedList<T>::display(int count)
{
    string output = "";

    Node<T>* current = this->_begin;
    for (int i = 0; i < this->_size * count; i++)
    {
        output += to_string(current->get_data());
        output += " ";

        current = current->get_next_node();
    }

    return output;
}