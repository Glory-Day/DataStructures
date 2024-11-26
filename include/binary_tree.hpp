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
    string get_inorder_traversal_output();
    string get_preorder_traversal_output();
    string get_post_order_traversal_output();

protected:
    BinaryTree() : Tree<Node<T>, T>() {}

    virtual void set_preorder_traversal_output(Node<T>*, string&);
    virtual void set_inorder_traversal_output(Node<T>*, string&);
    virtual void set_post_order_traversal_output(Node<T>*, string&);

    virtual string get_data_output(string&, Node<T>*) override;
    virtual void display(vector<string>&, string, Node<T>*) override;

public:
    virtual vector<string> traverse() override final;
};

#endif