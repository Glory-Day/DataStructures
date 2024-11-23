#include <iostream>

#include "binary_search_tree.hpp"

#include "binary_tree.cpp"

using namespace std;

template<typename T>
void BinarySearchTree<T>::insert(T data)
{
    Node<T>* node = new Node<T>(data);

    if (this->_root == nullptr)
    {
        this->_root = node;

        return;
    }

    Node<T>* current = this->_root;
    Node<T>* parent = nullptr;
    while (current != nullptr)
    {
        parent = current;

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
            throw invalid_argument("DATA IS ALREADY INSERTED");
        }
    }

    if (parent->get_data() > data)
    {
        parent->set_left_child_node(node);
    }
    else
    {
        parent->set_right_child_node(node);
    }
}

template<typename T>
Node<T>* BinarySearchTree<T>::remove(Node<T>* child_node, T data)
{
    if (child_node == nullptr)
    {
        return child_node;
    }
    else if (child_node->get_data() > data)
    {
        child_node->set_left_child_node(remove(child_node->get_left_child_node(), data));
    }
    else if (child_node->get_data() < data)
    {
        child_node->set_right_child_node(remove(child_node->get_right_child_node(), data));
    }
    else
    {
        Node<T>* current = child_node;
        if (child_node->get_left_child_node() == nullptr && child_node->get_right_child_node() == nullptr)
        {
            delete child_node;

            child_node = nullptr;
        }
        else if (child_node->get_left_child_node() == nullptr)
        {
            child_node = child_node->get_right_child_node();

            delete current;
        }
        else if (child_node->get_right_child_node() == nullptr)
        {
            child_node = child_node->get_left_child_node();

            delete current;
        }
        else
        {
            Node<T>* left_child_node = child_node->get_left_child_node();
            if (left_child_node != nullptr)
            {
                while (left_child_node->get_right_child_node() != nullptr)
                {
                    left_child_node = left_child_node->get_right_child_node();
                }
            }

            child_node->set_data(left_child_node->get_data());
            child_node->set_left_child_node(remove(child_node->get_left_child_node(), left_child_node->get_data()));
        }
    }

    return child_node;
}

template<typename T>
void BinarySearchTree<T>::remove(T data)
{
    if (search(data) == false)
    {
        throw invalid_argument("DATA IS NOT EXISTED");
    }

    this->_root = remove(this->_root, data);
}

template<typename T>
bool BinarySearchTree<T>::search(T data)
{
    if (this->_root == nullptr)
    {
        throw out_of_range("BINARY SEARCH TREE IS EMPTY");
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