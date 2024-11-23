#include "binary_heap.cpp"

#include "minimum_binary_heap.hpp"

template<typename T>
void MinimumBinaryHeap<T>::heapify(int index)
{
    while (this->get_left_child_index(index) < this->_size - 1)
    {
        int left_child_index = this->get_left_child_index(index);
        int right_child_index = this->get_right_child_index(index);

        int updated_index = this->get_left_child_index(index);
        if (right_child_index < this->_size && this->_root[left_child_index] > this->_root[right_child_index])
        {
            updated_index = right_child_index;
        }

        if (this->_root[updated_index] > this->_root[index] || this->_root[updated_index] == this->_root[index])
        {
            break;
        }
        else
        {
            swap(this->_root[index], this->_root[updated_index]);

            index = updated_index;
        }
    }
}

template<typename T>
void MinimumBinaryHeap<T>::insert(T data)
{
    this->push_back(data);

    int index = this->_size - 1;
    while (index != 0 && this->_root[this->get_parent_index(index)] > this->_root[index])
    {
        swap(this->_root[index], this->_root[this->get_parent_index(index)]);
        
        index = this->get_parent_index(index);
    }
}