#ifndef __BINARY_TREE_HPP__
#define __BINARY_TREE_HPP__

#define BINARY_TREE

#include <string>
#include <vector>

#include "node.hpp"
#include "tree.hpp"

using namespace std;

template<typename T>
class BinaryTree : public Tree<Node<T>, T>
{
private:
    void set_preorder_traversal_output(Node<T>*, string&);
    void set_inorder_traversal_output(Node<T>*, string&);
    void set_post_order_traversal_output(Node<T>*, string&);

    string get_inorder_traversal_output();
    string get_preorder_traversal_output();
    string get_post_order_traversal_output();

    void display(vector<string>&, string, Node<T>*);

protected:
    BinaryTree() : Tree<Node<T>, T>() {}

public:
    virtual vector<string> traversal() override final;

    virtual vector<string> display() override final;
};

#endif