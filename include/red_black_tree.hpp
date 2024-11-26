#ifndef __RED_BLACK_HPP__
#define __RED_BLACK_HPP__

#define RED_BLACK_TREE

#include <string>
#include <vector>

#include "binary_tree.hpp"

using namespace std;

template<typename T>
class RedBlackTree : public BinaryTree<T>
{
private:
    Node<T>* _leaf_node;

    Node<T>* find(T);

    void  balance_after_inserted(Node<T>*);
    void  balance_after_removed(Node<T>*);

    void  transplat(Node<T>*, Node<T>*);

    void  rotate_left(Node<T>*);
    void  rotate_right(Node<T>*);

    virtual void set_preorder_traversal_output(Node<T>*, string&) override final;
    virtual void set_inorder_traversal_output(Node<T>*, string&) override final;
    virtual void set_post_order_traversal_output(Node<T>*, string&) override final;

protected:
    virtual string get_data_output(string&, Node<T>*) override final;

public:
    RedBlackTree() : BinaryTree<T>()
    {
        _leaf_node = new Node<T>();
        _leaf_node->set_color(Color::Black);

        this->_root = _leaf_node;
    }

    ~RedBlackTree()
    {
        delete _leaf_node;
    }

    virtual void insert(T) override final;
    virtual void remove(T) override final;
    virtual bool search(T) override final;
};

#endif