#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include "hash_table.hpp"

using namespace std;

int HashTable::get_hash_code(int key) const
{
    return floor(_size * (key * A - floor(key * A)));
}

void HashTable::reserve(int size)
{
    int cache = _size;
    _size = size;

    rehashing(cache);
}

void HashTable::rehashing(int size)
{
    Node** table = new Node*[_size];
    for (int i = 0; i < _size; i++)
    {
        table[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        Node* current = _table[i];
        Node* previous = nullptr;

        while (current != nullptr)
        {
            previous = current->next;

            int index = get_hash_code(current->key);
            if (table[index] == nullptr)
            {
                table[index] = current;
                table[index]->next = 0;
            }
            else
            {
                Node* next = table[index]->next;
                table[index]->next = current;
                current->next = next;
            }

            current = previous;
        }
    }

    delete[] _table;

    _table = table;
}

void HashTable::insert(Node data)
{
    _count++;

    if (_size < _count)
    {
        reserve(_size * 2);
    }

    int index = get_hash_code(data.key);
    Node* clone = new Node(data);

    if (_table[index] == nullptr)
    {
        _table[index] = clone;
    }
    else
    {
        Node* next = _table[index]->next;
        _table[index]->next = clone;
        clone->next = next;
    }
}

void HashTable::remove(int key)
{
    int index = get_hash_code(key);
    Node* current = _table[index];
    Node* previous = nullptr;

    while (current != nullptr && current->key != key)
    {
        previous = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        throw invalid_argument("DATA NOT FOUND");
    }
    else
    {
        if (previous == nullptr)
        {
            _table[index] = current->next;
        }
        else
        {
            previous->next = current->next;
        }

        delete current;
        
        current = nullptr;
    }

    _count--;

    if (_count < _size / 4)
    {
        reserve(_size / 2);
    }
}

Node* HashTable::search(int key) const
{
    int index = get_hash_code(key);
    Node* current = _table[index];

    while (current != nullptr)
    {
        if (current->key == key)
        {
            return current;
        }

        current = current->next;
    }

    return nullptr;
}

vector<string> HashTable::display()
{
    vector<string> lines;
    for (int i = 0; i < _size; i++)
    {
        string line = "(" + to_string(i) + ") ";

        Node* current = _table[i];
        while (current != nullptr)
        {
            line = line + "(" + to_string(current->key) + "," + current->value + ") ";
            
            current = current->next;
        }

        lines.push_back(line);
    }

    return lines;
}