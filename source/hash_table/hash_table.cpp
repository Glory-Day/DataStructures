#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include "hash_table.hpp"

using namespace std;

template<typename T>
int HashTable<T>::get_hash_code(int key) const
{
    return floor(_size * (key * A - floor(key * A)));
}

template<typename T>
void HashTable<T>::reserve(int size)
{
    int cache = _size;
    _size = size;

    rehashing(cache);
}

template<typename T>
void HashTable<T>::rehashing(int size)
{
    Node<T>** table = new Node<T>*[_size];
    for (int i = 0; i < _size; i++)
    {
        table[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        Node<T>* current = _table[i];
        Node<T>* previous = nullptr;

        while (current != nullptr)
        {
            previous = current->get_next_node();

            int index = get_hash_code(current->get_key());
            if (table[index] == nullptr)
            {
                table[index] = current;
                table[index]->set_next_node(nullptr);
            }
            else
            {
                Node<T>* next_node = table[index]->get_next_node();
                table[index]->set_next_node(current);
                current->set_next_node(next_node);
            }

            current = previous;
        }
    }

    delete[] _table;

    _table = table;
}

template<typename T>
void HashTable<T>::insert(Node<T> data)
{
    _count++;

    if (_size < _count)
    {
        reserve(_size * 2);
    }

    int index = get_hash_code(data.get_key());
    Node<T>* node = new Node<T>(data);

    if (_table[index] == nullptr)
    {
        _table[index] = node;
    }
    else
    {
        Node<T>* next_node = _table[index]->get_next_node();
        _table[index]->set_next_node(node);
        node->set_next_node(next_node);
    }
}

template<typename T>
void HashTable<T>::remove(int key)
{
    int index = get_hash_code(key);
    Node<T>* current = _table[index];
    Node<T>* previous = nullptr;

    while (current != nullptr && current->get_key() != key)
    {
        previous = current;
        current = current->get_next_node();
    }

    if (current == nullptr)
    {
        throw invalid_argument("DATA NOT FOUND");
    }
    else
    {
        if (previous == nullptr)
        {
            _table[index] = current->get_next_node();
        }
        else
        {
            previous->set_next_node(current->get_next_node());
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

template<typename T>
Node<T>* HashTable<T>::search(int key) const
{
    int index = get_hash_code(key);
    Node<T>* current = _table[index];

    while (current != nullptr)
    {
        if (current->get_key() == key)
        {
            return current;
        }

        current = current->get_next_node();
    }

    return nullptr;
}

template<typename T>
vector<string> HashTable<T>::display()
{
    vector<string> lines;
    for (int i = 0; i < _size; i++)
    {
        string line = "(" + to_string(i) + ")";

        Node<T>* current = _table[i];
        while (current != nullptr)
        {
            line = line + "\u2500(" + to_string(current->get_key()) + "," + current->get_value() + ")";
            
            current = current->get_next_node();
        }

        lines.push_back(line);
    }

    return lines;
}