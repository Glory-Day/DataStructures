#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <string>
#include <vector>

using namespace std;

template<typename T1, typename T2>
class Tree
{
protected:
    T1* _root;

    Tree() : _root(nullptr) {}

public:
    virtual void insert(T2) = 0;
    virtual void remove(T2) = 0;
    virtual bool search(T2) = 0;

    virtual vector<string> traversal() = 0;

    virtual vector<string> display() = 0;
};

#endif