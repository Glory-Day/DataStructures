#ifndef __NODE_HPP__
#define __NODE_HPP__

#include "iterator.hpp"

#if defined(SINGLY_LINKED_LIST) || defined(LINKED_QUEUE)

template<typename T>
class Node : protected Iterator<T>
{
private:
    T _data; // Data in node.

public:
    /**
     * `Node` constructor to initialize fields
     * 
     * @param data : Data in node.
     * @param next_node : Next linked node pointer.
     */
    explicit Node(T data, Node<T>* next_node = nullptr) : Iterator<T>(1)
    {
        _data = data;

        this->set_iterator(0, next_node);
    }

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
    return (Node<T>*)this->get_iterator(0);
}

template<typename T>
void Node<T>::set_next_node(Node<T>* next_node)
{
    this->set_iterator(0, next_node);
}

#endif

#ifdef DOUBLY_LINKED_LIST

template<typename T>
class Node : protected Iterator<T>
{
private:
    T _data; // Data in node.

public:
    /**
     * `Node` constructor to initialize fields
     * 
     * @param data : Data in node.
     * @param next_node : Next linked node pointer.
     * @param previous_node : Previous linked node pointer.
     */
    explicit Node(T data, Node<T>* next_node = nullptr, Node<T>* previous_node = nullptr) : Iterator<T>(2)
    {
        _data = data;

        this->set_iterator(0, next_node);
        this->set_iterator(1, previous_node);
    }

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
    return (Node<T>*)this->get_iterator(0);
}

template<typename T>
void Node<T>::set_next_node(Node<T>* next_node)
{
    this->set_iterator(0, next_node);
}

template<typename T>
Node<T>* Node<T>::get_previous_node()
{
    return (Node<T>*)this->get_iterator(1);
}

template<typename T>
void Node<T>::set_previous_node(Node<T>* previous_node)
{
    this->set_iterator(1, previous_node);
}

#endif

#ifdef HASH_TABLE

template<typename T>
class Node : protected Iterator<T>
{
private:
    int _key;
    T _value;

public:
    Node(int key, T value) : Iterator<T>(1)
    {
        _key = key;
        _value = value;

        this->set_iterator(0, nullptr);
    }
    Node(Node<T> &node) : Iterator<T>(1)
    {
        _key = node._key;
        _value = node._value;

        this->set_iterator(0, node.get_iterator(0));
    }

    int     get_key();
    void    set_key(int);
    T       get_value();
    void    set_value(T);

    Node<T>* get_next_node();
    void    set_next_node(Node<T>*); 
};

template<typename T>
int Node<T>::get_key()
{
    return _key;
}

template<typename T>
void Node<T>::set_key(int key)
{
    _key = key;
}

template<typename T>
T Node<T>::get_value()
{
    return _value;
}

template<typename T>
void Node<T>::set_value(T value)
{
    _value = value;
}

template<typename T>
Node<T>* Node<T>::get_next_node()
{
    return (Node<T>*)this->get_iterator(0);
}

template<typename T>
void Node<T>::set_next_node(Node<T>* next_node)
{
    this->set_iterator(0, next_node);
}

#endif

#ifdef BINARY_TREE

template<typename T>
class Node : protected Iterator<T>
{
private:
    T _data;

#ifdef AVL_TREE

    int _height;

#endif

public:
    Node(T data, Node<T>* left_child_node = nullptr, Node<T>* right_child_node = nullptr) : Iterator<T>(2)
    {
        _data = data;

#ifdef AVL_TREE

        _height = 1;

#endif

        this->set_iterator(0, left_child_node);
        this->set_iterator(1, right_child_node);
    }

    T        get_data();
    void     set_data(T);
    
    Node<T>* get_left_child_node();
    void     set_left_child_node(Node<T>*);
    Node<T>* get_right_child_node();
    void     set_right_child_node(Node<T>*);

#ifdef AVL_TREE

    int      get_height();
    void     set_height(int);

#endif
};

template<typename T>
T Node<T>::get_data()
{
    return _data;
}

template<typename T>
void Node<T>::set_data(T data)
{
    _data = data;
}

template<typename T>
Node<T>* Node<T>::get_left_child_node()
{
    return (Node<T>*)this->get_iterator(0);
}

template<typename T>
void Node<T>::set_left_child_node(Node<T>* left_child_node)
{
    this->set_iterator(0, left_child_node);
}

template<typename T>
Node<T>* Node<T>::get_right_child_node()
{
    return (Node<T>*)this->get_iterator(1);
}

template<typename T>
void Node<T>::set_right_child_node(Node<T>* right_child_node)
{
    this->set_iterator(1, right_child_node);
}

#ifdef AVL_TREE

template<typename T>
int Node<T>::get_height()
{
    return _height;
}

template<typename T>
void Node<T>::set_height(int height)
{
    _height = height;
}

#endif

#endif

#endif