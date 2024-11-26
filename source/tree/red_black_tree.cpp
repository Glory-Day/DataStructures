#include <iostream>

#include "Red_black_tree.hpp"

#include "binary_tree.cpp"

template<typename T>
void RedBlackTree<T>::set_preorder_traversal_output(Node<T>* node, string& output)
{
    if (node == _leaf_node)
    {
        return;
    }

    BinaryTree<T>::set_preorder_traversal_output(node, output);
}

template<typename T>
void RedBlackTree<T>::set_inorder_traversal_output(Node<T>* node, string& output)
{
    if (node == _leaf_node)
    {
        return;
    }

    BinaryTree<T>::set_inorder_traversal_output(node, output);
}

template<typename T>
void RedBlackTree<T>::set_post_order_traversal_output(Node<T>* node, string& output)
{
    if (node == _leaf_node)
    {
        return;
    }

    BinaryTree<T>::set_post_order_traversal_output(node, output);
}

template<typename T>
void RedBlackTree<T>::transplat(Node<T>* a_node, Node<T>* b_node)
{
    if (a_node->get_parent_node() == nullptr)
    {
        this->_root = b_node;
    }
    else if (a_node == a_node->get_parent_node()->get_left_child_node())
    {
        a_node->get_parent_node()->set_left_child_node(b_node);
    }
    else
    {
        a_node->get_parent_node()->set_right_child_node(b_node);
    }

    b_node->set_parent_node(a_node->get_parent_node());
}

template<typename T>
void RedBlackTree<T>::rotate_left(Node<T>* node)
{
    Node<T>* right_child_node = node->get_right_child_node();
    node->set_right_child_node(right_child_node->get_left_child_node());

    if (right_child_node->get_left_child_node() != _leaf_node)
    {
        right_child_node->get_left_child_node()->set_parent_node(node);
    }

    right_child_node->set_parent_node(node->get_parent_node());

    if (node->get_parent_node() == nullptr)
    {
        this->_root = right_child_node;
    }
    else if (node == node->get_parent_node()->get_left_child_node())
    {
        node->get_parent_node()->set_left_child_node(right_child_node);
    }
    else
    {
        node->get_parent_node()->set_right_child_node(right_child_node);
    }

    node->set_parent_node(right_child_node);
    right_child_node->set_left_child_node(node);
}

template<typename T>
void RedBlackTree<T>::rotate_right(Node<T>* node)
{
    Node<T>* left_child_node = node->get_left_child_node();
    node->set_left_child_node(left_child_node->get_right_child_node());

    if (left_child_node->get_right_child_node() != _leaf_node)
    {
        left_child_node->get_right_child_node()->set_parent_node(node);
    }

    left_child_node->set_parent_node(node->get_parent_node());

    if (node->get_parent_node() == nullptr)
    {
        this->_root = left_child_node;
    }
    else if (node == node->get_parent_node()->get_left_child_node())
    {
        node->get_parent_node()->set_left_child_node(left_child_node);
    }
    else
    {
        node->get_parent_node()->set_right_child_node(left_child_node);
    }

    node->set_parent_node(left_child_node);
    left_child_node->set_right_child_node(node);
}

template<typename T>
Node<T>* RedBlackTree<T>::find(T data)
{
    Node<T>* node = this->_root;

    Node<T>* parent_node = nullptr;
    while (node != nullptr && node->get_data() != data)
    {
        parent_node = node;

        node = (data < parent_node->get_data()) ? parent_node->get_left_child_node() : parent_node->get_right_child_node();
    }

    return node;
}

template<typename T>
void RedBlackTree<T>::balance_after_inserted(Node<T>* node)
{
    while (node != this->_root && node->get_parent_node()->get_color() == Color::Red)
    {
        Node<T>* grand_parent_node = node->get_parent_node()->get_parent_node();
        Node<T>* uncle_node = grand_parent_node->get_left_child_node();
        if (node->get_parent_node() == grand_parent_node->get_left_child_node())
        {
            uncle_node = grand_parent_node->get_right_child_node();
        }

        bool check = node->get_parent_node() == grand_parent_node->get_left_child_node();
        if (uncle_node != nullptr && uncle_node->get_color() == Color::Red)
        {
            node->get_parent_node()->set_color(Color::Black);
            uncle_node->set_color(Color::Black);
            grand_parent_node->set_color(Color::Red);

            node = grand_parent_node;
        }
        else
        {
            if (node == (check ? node->get_parent_node()->get_right_child_node() : node->get_parent_node()->get_left_child_node()))
            {
                node = node->get_parent_node();

                check ? rotate_left(node) : rotate_right(node);
            }

            node->get_parent_node()->set_color(Color::Black);
            grand_parent_node->set_color(Color::Red);

            check ? rotate_right(grand_parent_node) : rotate_left(grand_parent_node);
        }
    }

    this->_root->set_color(Color::Black);
}

template<typename T>
void RedBlackTree<T>::insert(T data)
{
    if (find(data) != nullptr)
    {
        throw invalid_argument("DATA IS ALREADY INSERTED");
    }

    Node<T>* node = new Node<T>(data, _leaf_node, _leaf_node);

    Node<T>* current_node = this->_root;
    Node<T>* parent_node = nullptr;
    while (current_node != _leaf_node)
    {
        parent_node = current_node;

        if (current_node->get_data() > data)
        {
            current_node = current_node->get_left_child_node();
        }
        else
        {
            current_node = current_node->get_right_child_node();
        }
    }

    node->set_parent_node(parent_node);

    if (parent_node == nullptr)
    {
        this->_root = node;
    }
    else if (node->get_data() < parent_node->get_data())
    {
        parent_node->set_left_child_node(node);
    }
    else
    {
        parent_node->set_right_child_node(node);
    }

    if (node->get_parent_node() == nullptr)
    {
        node->set_color(Color::Black);

        return;
    }

    if (node->get_parent_node()->get_parent_node() == nullptr)
    {
        return;
    }

    balance_after_inserted(node);
}

template<typename T>
void RedBlackTree<T>::balance_after_removed(Node<T>* node)
{
    Node<T>* sibling_node;

    while (node != this->_root && node->get_color() == Color::Black)
    {
        if (node == node->get_parent_node()->get_left_child_node())
        {
            sibling_node = node->get_parent_node()->get_right_child_node();

            if (sibling_node->get_color() == Color::Red)
            {
                sibling_node->set_color(Color::Black);
                node->get_parent_node()->set_color(Color::Red);
                
                rotate_left(node->get_parent_node());
                
                sibling_node = node->get_parent_node()->get_right_child_node();
            }

            if (sibling_node->get_left_child_node()->get_color() == Color::Black && sibling_node->get_right_child_node()->get_color() == Color::Black)
            {
                sibling_node->set_color(Color::Red);
                
                node = node->get_parent_node();
            }
            else
            {
                if (sibling_node->get_right_child_node()->get_color() == Color::Black)
                {
                    sibling_node->get_left_child_node()->set_color(Color::Black);
                    sibling_node->set_color(Color::Red);
                    
                    rotate_right(sibling_node);
                    
                    sibling_node = node->get_parent_node()->get_right_child_node();
                }

                sibling_node->set_color(node->get_parent_node()->get_color());
                node->get_parent_node()->set_color(Color::Black);
                sibling_node->get_right_child_node()->set_color(Color::Black);
                
                rotate_left(node->get_parent_node());
                
                node = this->_root;
            }
        }
        else
        {
            sibling_node = node->get_parent_node()->get_left_child_node();

            if (sibling_node->get_color() == Color::Red)
            {
                sibling_node->set_color(Color::Black);
                node->get_parent_node()->set_color(Color::Red);
                
                rotate_right(node->get_parent_node());
                
                sibling_node = node->get_parent_node()->get_left_child_node();
            }

            if (sibling_node->get_left_child_node()->get_color() == Color::Black && sibling_node->get_right_child_node()->get_color() == Color::Black)
            {
                sibling_node->set_color(Color::Red);

                node = node->get_parent_node();
            }
            else
            {
                if (sibling_node->get_left_child_node()->get_color() == Color::Black)
                {
                    sibling_node->get_right_child_node()->set_color(Color::Black);
                    sibling_node->set_color(Color::Red);

                    rotate_left(sibling_node);

                    sibling_node = node->get_parent_node()->get_left_child_node();
                }

                sibling_node->set_color(node->get_parent_node()->get_color());
                node->get_parent_node()->set_color(Color::Black);
                sibling_node->get_left_child_node()->set_color(Color::Black);

                rotate_right(node->get_parent_node());
                
                node = this->_root;
            }
        }
    }

    node->set_color(Color::Black);
    this->_root->set_color(Color::Black);
}

template<typename T>
void RedBlackTree<T>::remove(T data)
{
    Node<T>* node = find(data);
    if (node == nullptr)
    {
        throw invalid_argument("DATA IS NOT EXISTED");
    }
    
    Color color = node->get_color();

    Node<T>* child_node;
    Node<T>* current_node;
    if (node->get_left_child_node() == _leaf_node)
    {
        child_node = node->get_right_child_node();

        transplat(node, node->get_right_child_node());
    }
    else if (node->get_right_child_node() == _leaf_node)
    {
        child_node = node->get_left_child_node();

        transplat(node, node->get_left_child_node());
    }
    else
    {
        current_node = node->get_right_child_node();
        while (current_node->get_left_child_node() != _leaf_node)
        {
            current_node = current_node->get_left_child_node();
        }

        color = current_node->get_color();

        child_node = current_node->get_right_child_node();
        if (current_node->get_parent_node() == node)
        {
            child_node->set_parent_node(current_node);
        }
        else
        {
            transplat(current_node, current_node->get_right_child_node());
        
            current_node->set_right_child_node(node->get_right_child_node());
            current_node->get_right_child_node()->set_parent_node(current_node);
        }

        transplat(node, current_node);
        
        current_node->set_left_child_node(node->get_left_child_node());
        current_node->get_left_child_node()->set_parent_node(current_node);
        current_node->set_color(node->get_color());
    }

    delete node;
    
    if (color == Color::Black)
    {
        balance_after_removed(child_node);
    }
}

template<typename T>
bool RedBlackTree<T>::search(T data)
{
    if (this->_root == nullptr)
    {
        throw out_of_range("TREE IS EMPTY");
    }

    return find(data) != nullptr;
}

template<typename T>
string RedBlackTree<T>::get_data_output(string& path, Node<T>* node)
{
    string output = "";
    if (node == nullptr)
    {
        return output;
    }

    string red_color = "\033[41m";
    string black_color = "\033[40m";
    string reset_color = "\033[0m";

    string data;
    string color;
    if (node == this->_leaf_node)
    {
        data = "-";
        color = black_color;
    }
    else
    {
        data = to_string(node->get_data());
        color = (node->get_color() == Color::Red ? red_color : black_color);
    }

    if (path.empty() == false)
    {
        switch (path.back())
        {
            case 'L':
                output = "  \u251C\u2500" + color + "[L:" + data + "]" + reset_color;
                break;
            case 'R':
                output = "  \u2514\u2500" + color + "[R:" + data + "]" + reset_color;
                break;
        }
    }
    else
    {        
        output = color + "[T:" + data + "]" + reset_color;
    }

    return output;
}