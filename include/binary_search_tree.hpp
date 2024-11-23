#ifndef __BINARY_SEARCH_TREE_HPP__
#define __BINARY_SEARCH_TREE_HPP__

#define BINARY_SEARCH_TREE

#include <string>
#include <vector>

#include "binary_tree.hpp"

using namespace std;

template<typename T>
class BinarySearchTree : public BinaryTree<T>
{
private:
    Node<T>* remove(Node<T>*, T);

public:
    BinarySearchTree() : BinaryTree<T>() {}

    virtual void insert(T) override final;
    virtual void remove(T) override final;
    virtual bool search(T) override final;
};

#endif