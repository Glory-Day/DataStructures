#ifndef __HASH_TABLE_HPP__
#define __HASH_TABLE_HPP__

#define HASH_TABLE

#include <string>
#include <vector>

#include "node.hpp"

using namespace std;

template<typename T>
class HashTable
{
private:
    const double A = 0.6180339887;

    int _size;  // Size of table.
    int _count; // Number of data.

    Node<T>** _table;

    int get_hash_code(int) const;
    void reserve(int);
    void rehashing(int);

public:
    HashTable() { }
    HashTable(int size) : _size(size), _count(0)
    {
        // Allocate the first demension of table.
        _table = new Node<T>*[_size];
        for (int i = 0; i < _size; i++)
        {
            _table[i] = nullptr;
        }
    }
    
    ~HashTable()
    {
        for (int i = 0; i < _size; i++)
        {
            Node<T>* current = _table[i];
            while (current != nullptr)
            {
                Node<T>* previous = current;
                current = current->get_next_node();

                delete previous;

                previous = nullptr;
            }
        }

        delete[] _table;
        
        _table = nullptr;
    }

    void     insert(Node<T>);
    void     remove(int);
    Node<T>* search(int) const;

    vector<string> display();
};

#endif