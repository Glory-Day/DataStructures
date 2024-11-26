#ifndef __AVL_TREE_HPP__
#define __AVL_TREE_HPP__

#define AVL_TREE

#include <string>
#include <vector>

#include "binary_tree.hpp"

using namespace std;

template<typename T>
class AVLTree : public BinaryTree<T>
{
private:
    Node<T>* insert(Node<T>*, T);
    Node<T>* remove(Node<T>*, T);

    Node<T>* balance(Node<T>*, T);

    Node<T>* transplat(Node<T>*);

    int get_height(Node<T>*);
    int get_height_difference(Node<T>*);

    Node<T>* rotate_left(Node<T>*);
    Node<T>* rotate_right(Node<T>*);

protected:
    virtual string get_data_output(string&, Node<T>*) override final;

public:
    AVLTree() : BinaryTree<T>() {}

    virtual void insert(T) override final;
    virtual void remove(T) override final;
    virtual bool search(T) override final;
};

#endif