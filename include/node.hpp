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

    T        get_data() { return _data; }
    
    Node<T>* get_next_node() { return (Node<T>*)this->get_iterator(0); }
    void     set_next_node(Node<T>* next_node) { this->set_iterator(0, next_node); }
};

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

    T        get_data() { return _data; }
    
    Node<T>* get_next_node() { return (Node<T>*)this->get_iterator(0); }
    void     set_next_node(Node* next_node) { this->set_iterator(0, next_node); }
    Node<T>* get_previous_node() { return (Node<T>*)this->get_iterator(1); }
    void     set_previous_node(Node* previous_node) { this->set_iterator(1, previous_node); }
};

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

    int     get_key() { return _key; }
    void    set_key(int key) { _key = key; }
    T       get_value() { return _value; }
    void    set_value(T value) { _value = value; }

    Node<T>* get_next_node() { return (Node<T>*)this->get_iterator(0); }
    void    set_next_node(Node<T>* next_node) { this->set_iterator(0, next_node); }
};

#endif

#ifdef BINARY_TREE

#ifdef RED_BLACK_TREE

enum class Color : int
{
    Red   = (0x01 << 0),
    Black = (0x01 << 1)
};

#endif

template<typename T>
class Node : protected Iterator<T>
{
private:
    T _data;

#ifdef AVL_TREE

    int _height;

#endif

#ifdef RED_BLACK_TREE

    Color _color;

    Node<T>* _parent_node;

#endif

public:
    Node(T data = 0, Node<T>* left_child_node = nullptr, Node<T>* right_child_node = nullptr) : Iterator<T>(2)
    {
        _data = data;

#ifdef AVL_TREE

        _height = 1;

#endif

#ifdef RED_BLACK_TREE

        _color = Color::Red;

        _parent_node = nullptr;

#endif

        this->set_iterator(0, left_child_node);
        this->set_iterator(1, right_child_node);
    }

    T        get_data() { return _data; }
    void     set_data(T data) { _data = data; }
    
    Node<T>* get_left_child_node() { return (Node<T>*)this->get_iterator(0); }
    void     set_left_child_node(Node<T>* node) { this->set_iterator(0, node); }
    Node<T>* get_right_child_node() { return (Node<T>*)this->get_iterator(1); }
    void     set_right_child_node(Node<T>* node) { this->set_iterator(1, node); }

#ifdef AVL_TREE

    int      get_height() { return _height; }
    void     set_height(int height) { _height = height; }

#endif

#ifdef RED_BLACK_TREE

    Node<T>* get_parent_node() { return _parent_node; }
    void     set_parent_node(Node<T>* node) { _parent_node = node; }

    Color    get_color() { return _color; }
    void     set_color(Color color) { _color = color; }

#endif
};

#endif

#if defined(B_TREE)

template<typename T>
class Node : protected Iterator<T>
{
private:
    T*   _data;
    int  _count;

public:
    bool is_leaf_node;

    Node(int size, bool is_leaf_node = true) : Iterator<T>(size)
    {
        _data = new T[size - 1];
        _count = 0;

        this->is_leaf_node = is_leaf_node;
    }

    ~Node()
    {
        delete[] _data;
    }

    T get_data(int index) { return _data[index]; }
    void set_data(int index, T data) { _data[index] = data; }

    Node<T>* get_child_node(int index) { return (Node<T>*)this->get_iterator(index); }
    void set_child_node(int index, Node<T>* node) { this->set_iterator(index, node); }

    int get_count() { return _count; }
    void set_count(int count) { _count = count; }
};

#endif

#endif