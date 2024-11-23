#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "avl_tree.hpp"

#include "binary_tree.cpp"

using namespace std;

template<typename T>
int AVLTree<T>::get_height(Node<T>* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    return node->get_height();
}

template<typename T>
int AVLTree<T>::get_height_difference(Node<T>* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    return get_height(node->get_left_child_node()) - get_height(node->get_right_child_node());
}

template<typename T>
Node<T>* AVLTree<T>::rotate_left(Node<T>* node)
{
    Node<T>* right_child_node = node->get_right_child_node();
    Node<T>* subtree = right_child_node->get_left_child_node();

    right_child_node->set_left_child_node(node);
    node->set_right_child_node(subtree);

    node->set_height(max(get_height(node->get_left_child_node()), get_height(node->get_right_child_node())) + 1);
    right_child_node->set_height(max(get_height(right_child_node->get_left_child_node()), get_height(right_child_node->get_right_child_node())) + 1);

    return right_child_node;
}

template<typename T>
Node<T>* AVLTree<T>::rotate_right(Node<T>* node)
{
    Node<T>* left_child_node = node->get_left_child_node();
    Node<T>* subtree = left_child_node->get_right_child_node();

    left_child_node->set_right_child_node(node);
    node->set_left_child_node(subtree);

    node->set_height(max(get_height(node->get_left_child_node()), get_height(node->get_right_child_node())) + 1);
    left_child_node->set_height(max(get_height(left_child_node->get_left_child_node()), get_height(left_child_node->get_right_child_node())) + 1);

    return left_child_node;
}

template<typename T>
Node<T>* AVLTree<T>::balance(Node<T>* node, T data)
{
    int height_difference = get_height_difference(node);

    if (height_difference > 1 && data < node->get_left_child_node()->get_data())
    {
        return rotate_right(node);
    }

    if (height_difference < -1 && data > node->get_right_child_node()->get_data())
    {
        return rotate_left(node);
    }

    if (height_difference > 1 && data > node->get_left_child_node()->get_data())
    {
        node->set_left_child_node(rotate_left(node->get_left_child_node()));

        return rotate_right(node);
    }

    if (height_difference < -1 && data < node->get_right_child_node()->get_data())
    {
        node->set_right_child_node(rotate_right(node->get_right_child_node()));

        return rotate_left(node);
    }

    return node;
}

template<typename T>
Node<T>* AVLTree<T>::transplat(Node<T>* node)
{
    Node<T>* cache = node;

    if (node->get_left_child_node() == nullptr)
    {
        node = node->get_right_child_node();
    }
    else if (node->get_right_child_node() == nullptr)
    {
        node = node->get_left_child_node();
    }
    else
    {
        Node<T>* parent_node = node;
        Node<T>* child_node = node->get_right_child_node();

        while (child_node->get_left_child_node() != nullptr)
        {
            parent_node = child_node;
            child_node = child_node->get_left_child_node();
        }

        node->set_data(child_node->get_data());

        if (parent_node == node)
        {
            node->set_right_child_node(child_node->get_right_child_node());
        }
        else
        {
            parent_node->set_left_child_node(child_node->get_right_child_node());
        }

        cache = child_node;
    }

    delete cache;

    return node;
}

template<typename T>
Node<T>* AVLTree<T>::insert(Node<T>* node, T data)
{
    if (node == nullptr)
    {
        return new Node<T>(data);
    }

    if (data < node->get_data())
    {
        node->set_left_child_node(insert(node->get_left_child_node(), data));
    }
    else
    {
        node->set_right_child_node(insert(node->get_right_child_node(), data));
    }

    node->set_height(max(get_height(node->get_left_child_node()), get_height(node->get_right_child_node())) + 1);

    node = balance(node, data);

    return node;
}

template<typename T>
void AVLTree<T>::insert(T data)
{
    if (this->_root == nullptr)
    {
        this->_root = new Node<T>(data);

        return;
    }

    if (search(data))
    {
        throw invalid_argument("DATA IS ALREADY INSERTED");
    }

    this->_root = insert(this->_root, data);
}


template<typename T>
Node<T>* AVLTree<T>::remove(Node<T>* node, T data)
{
    if (node == nullptr)
    {
        return node;
    }

    if (node->get_data() > data)
    {
        node->set_left_child_node(remove(node->get_left_child_node(), data));
    }
    else if (node->get_data() < data)
    {
        node->set_right_child_node(remove(node->get_right_child_node(), data));
    }
    else
    {
        node = transplat(node);
    }

    if (node != nullptr)
    {
        node->set_height(max(get_height(node->get_left_child_node()), get_height(node->get_right_child_node())) + 1);

        node = balance(node, data);
    }

    return node;
}

template<typename T>
void AVLTree<T>::remove(T data)
{
    if (search(data) == false)
    {
        throw invalid_argument("DATA IS NOT EXISTED");
    }

    this->_root = this->remove(this->_root, data);
}

template<typename T>
bool AVLTree<T>::search(T data)
{
    if (this->_root == nullptr)
    {
        throw out_of_range("AVL TREE IS EMPTY");
    }

    Node<T>* current = this->_root;
    while (current != nullptr)
    {
        
        if (current->get_data() > data)
        {
            current = current->get_left_child_node();
        }
        else if (current->get_data() < data)
        {
            current = current->get_right_child_node();
        }
        else
        {
            return true;
        }
    }

    return false;
}