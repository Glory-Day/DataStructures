#ifndef __NODE_HPP__
#define __NODE_HPP__

#if defined(SINGLY_LINKED_LIST) || defined(QUEUE)

template<typename T>
class Node
{
private:
    T        _data; // Data in node.
    Node<T>* _next; // Next linked node pointer.

public:
    /**
     * `Node` constructor to initialize fields
     * 
     * @param data : Data in node.
     * @param next : Next linked node pointer.
     */
    explicit Node(T data, Node<T>* next = nullptr) : _data{data}, _next{next} {}

    T        get_data();
    Node<T>* get_next_node();
    void     set_next_node(Node<T>*);
};

template<typename T>
T Node<T>::get_data()
{
    return _data;
}

template<typename T>
Node<T>* Node<T>::get_next_node()
{
    return _next;
}

template<typename T>
void Node<T>::set_next_node(Node<T>* next)
{
    _next = next;
}

#endif

#ifdef DOUBLY_LINKED_LIST

template<typename T>
class Node
{
private:
    T        _data;     // Data in node.
    Node<T>* _next;     // Next linked node pointer.
    Node<T>* _previous; // Previous linked node pointer.

public:
    /**
     * `Node` constructor to initialize fields
     * 
     * @param data : Data in node.
     * @param next : Next linked node pointer.
     * @param previous : Previous linked node pointer.
     */
    explicit Node(T data, Node<T>* next = nullptr, Node<T>* previous = nullptr) : _data{data}, _next{next}, _previous{previous} {}

    T        get_data();
    Node<T>* get_next_node();
    void     set_next_node(Node*);
    Node<T>* get_previous_node();
    void     set_previous_node(Node*);
};

template<typename T>
T Node<T>::get_data()
{
    return _data;
}

template<typename T>
Node<T>* Node<T>::get_next_node()
{
    return _next;
}

template<typename T>
void Node<T>::set_next_node(Node<T>* next)
{
    _next = next;
}

template<typename T>
Node<T>* Node<T>::get_previous_node()
{
    return _previous;
}

template<typename T>
void Node<T>::set_previous_node(Node<T>* previous)
{
    _previous = previous;
}

#endif

#ifdef HASH_TABLE

#include <string>

using namespace std;

struct Node
{
    int key;
    string value;
    
    Node *next; // Pointer to access memory address of next node.

    Node() : key(0), value(""), next(0) { }
    Node(int key, string value) : key(key), value(value), next(0) { }
    Node(Node const &data) : key(data.key), value(data.value), next(data.next) { }
};

#endif

#endif