#include "binary_tree.hpp"

template<typename T>
void BinaryTree<T>::set_preorder_traversal_output(Node<T>* child_node, string& output)
{
    if (child_node == nullptr)
    {
        return;
    }

    output += to_string(child_node->get_data()) + " ";

    set_preorder_traversal_output(child_node->get_left_child_node(), output);
    set_preorder_traversal_output(child_node->get_right_child_node(), output);
}

template<typename T>
void BinaryTree<T>::set_inorder_traversal_output(Node<T>* child_node, string& output)
{
    if (child_node == nullptr)
    {
        return;
    }

    set_inorder_traversal_output(child_node->get_left_child_node(), output);

    output += to_string(child_node->get_data()) + " ";

    set_inorder_traversal_output(child_node->get_right_child_node(), output);
}

template<typename T>
void BinaryTree<T>::set_post_order_traversal_output(Node<T>* child_node, string& output)
{
    if (child_node == nullptr)
    {
        return;
    }

    set_post_order_traversal_output(child_node->get_left_child_node(), output);
    set_post_order_traversal_output(child_node->get_right_child_node(), output);

    output += to_string(child_node->get_data()) + " ";
}

template<typename T>
string BinaryTree<T>::get_preorder_traversal_output()
{
    string output = "";

    if (this->_root == nullptr)
    {
        return output;
    }

    set_preorder_traversal_output(this->_root, output);

    return output;
}

template<typename T>
string BinaryTree<T>::get_inorder_traversal_output()
{
    string output = "";

    if (this->_root == nullptr)
    {
        return output;
    }

    set_inorder_traversal_output(this->_root, output);

    return output;
}

template<typename T>
string BinaryTree<T>::get_post_order_traversal_output()
{
    string output = "";

    if (this->_root == nullptr)
    {
        return output;
    }

    set_post_order_traversal_output(this->_root, output);

    return output;
}

template<typename T>
vector<string> BinaryTree<T>::traversal()
{
    vector<string> output(3);
    output[0] = get_preorder_traversal_output();
    output[1] = get_inorder_traversal_output();
    output[2] = get_post_order_traversal_output();

    return output;
}

template<typename T>
void BinaryTree<T>::display(vector<string>& output, string path, Node<T>* node)
{
    int length = (int)path.length();

    string line = "";
    for (int i = 0; i < length - 1; i++)
    {
        switch (path[i])
        {
            case 'L':
                line += "  \u2502 ";
                break;
            case 'R':
                line += "    ";
                break;
        }
    }

#ifdef BINARY_SEARCH_TREE

    string data = (node != nullptr ? to_string(node->get_data()) : "-");
    if (path.empty() == false)
    {
        switch (path[length - 1])
        {
            case 'L':
                line += "  \u251C\u2500[L:" + data + "]";
                break;
            case 'R':
                line += "  \u2514\u2500[R:" + data + "]";
                break;
        }
    }
    else
    {
        line += "[T:" + data + "]";
    }

#endif

#ifdef AVL_TREE

    string data = (node != nullptr ? to_string(node->get_data()) + "(" + to_string(node->get_height()) + ")" : "-");
    if (path.empty() == false)
    {
        switch (path[length - 1])
        {
            case 'L':
                line += "  \u251C\u2500[L:" + data + "]";
                break;
            case 'R':
                line += "  \u2514\u2500[R:" + data + "]";
                break;
        }
    }
    else
    {        
        line += "[T:" + data + "]";
    }

#endif

    output.push_back(line);

    if (node != nullptr)
    {
        this->display(output, path + "L", node->get_left_child_node());
        this->display(output, path + "R", node->get_right_child_node());
    }
}

template<typename T>
vector<string> BinaryTree<T>::display()
{
    vector<string> output;

    display(output, "", this->_root);

    return output;
}