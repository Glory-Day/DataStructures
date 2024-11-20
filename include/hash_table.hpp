#ifndef __HASH_TABLE_HPP__
#define __HASH_TABLE_HPP__

#define HASH_TABLE

#include <string>
#include <vector>

#include "node.hpp"

using namespace std;

class HashTable
{
private:
    const double A = 0.6180339887;

    int _size;  // Size of table.
    int _count; // Number of data.

    Node** _table;

    int get_hash_code(int key) const;
    void reserve(int size);
    void rehashing(int size);

public:
    HashTable() { }
    HashTable(int size) : _size(size), _count(0)
    {
        // Allocate the first demension of table.
        _table = new Node*[_size];
        for (int i = 0; i < _size; i++)
        {
            _table[i] = nullptr;
        }
    }
    
    ~HashTable()
    {
        for (int i = 0; i < _size; i++)
        {
            Node* current = _table[i];
            while (current != nullptr)
            {
                Node* previous = current;
                current = current->next;

                delete previous;
                previous = nullptr;
            }
        }

        delete[] _table;
        
        _table = nullptr;
    }

    void insert(Node data);
    void remove(int key);
    Node* search(int key) const;

    vector<string> display();
};

#endif