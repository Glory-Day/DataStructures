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

    virtual string get_data_output(string&, T1*) = 0;
    virtual void display(vector<string>&, string, T1*) = 0;

public:
    virtual void insert(T2) = 0;
    virtual void remove(T2) = 0;
    virtual bool search(T2) = 0;

    virtual vector<string> traverse() = 0;

    vector<string> display();
};

template<typename T1, typename T2>
vector<string> Tree<T1, T2>::display()
{
    vector<string> output;

    display(output, "", _root);

    return output;
}

#endif