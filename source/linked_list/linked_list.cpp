#include "linked_list.hpp"

/**
 * @return Check linked list is empty or not
 */
template<typename T1, typename T2>
bool LinkedList<T1, T2>::empty()
{
    return _begin == nullptr && _end == nullptr;
}

/**
 * @return Size of nodes in `Singly Linked List`
 */
template<typename T1, typename T2>
int LinkedList<T1, T2>::size()
{
    return _size;
}

/**
 * Clear all nodes.
 */
template<typename T1, typename T2>
void LinkedList<T1, T2>::clear()
{
    while (empty() == false)
    {
        pop();
    }
}