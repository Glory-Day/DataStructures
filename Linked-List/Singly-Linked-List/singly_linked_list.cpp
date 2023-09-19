#include <iostream>
#include "Node.cpp"

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* _head; // Head of linked list

public:
    /**
     * `Singly Linked List` default constructor
     */
    SinglyLinkedList() : _head{new Node<T>(-1, nullptr)} {}

    void Push(T);
    bool Pop();
    bool Insert(int, T);
    bool Remove(int);
    int  Search(T);
    bool IsEmpty();
    int  Size();
    void Clear();
};

/**
 * Push data in front of `Singly Linked List`
 * 
 * @param data Data to push in linked list
 */
template <typename T>
void SinglyLinkedList<T>::Push(T data) {
    // Create new node
    auto* newNode = new Node<T>(data, nullptr);

    if (IsEmpty()) {
        _head->SetNext(newNode);
    }
    else {
        newNode->SetNext(_head->GetNext());
        _head->SetNext(newNode);
    }
}

/**
 * Pop data in front of `Singly Linked List`
 * 
 * @return Check data is popped or not
 */
template <typename T>
bool SinglyLinkedList<T>::Pop() {
    try {
        // Throw exception when accessing null pointer
        if (IsEmpty()) {
            throw std::out_of_range("Singly linked list is empty");
        }

        Node<T>* node = _head->GetNext();
        if (Size() == 1) {
            _head->SetNext(nullptr);
        }
        else {
            _head->SetNext(node->GetNext());
        }

        // Delete next node of head
        delete node;

        return true;
    }
    catch (std::out_of_range& exception) {
        std::cout << " - Exception : " << exception.what() << std::endl;
    }

    return false;
}

/**
 * Insert data into the specified index of `Singly Linked List`
 * 
 * @param index Number of index
 * @param data Data to insert
 * @return Check data is inserted or not
 */
template <typename T>
bool SinglyLinkedList<T>::Insert(int index, T data) {
    try {
        // Throw exception when index is out of range in linked list
        if (Size() < index) {
            throw std::out_of_range("Index is out of range");
        }

        if (index == 0) {
            Push(data);
        }
        else {
            // Create new node
            auto* newNode = new Node<T>(data, nullptr);

            // Insert new node at the index in linked list
            int i = 1;
            for (Node<T>* node = _head->GetNext()->GetNext(); true; node = node->GetNext(), i++) {
                if (i == index - 1) {
                    newNode->SetNext(node->GetNext());
                    node->SetNext(newNode);
                    break;
                }
            }
        }

        return true;
    }
    catch (std::out_of_range& exception) {
        std::cout << " - Exception : " << exception.what() << std::endl;
    }

    return false;
}

/**
 * Remove data into the specified index in `Singly Linked List`
 * 
 * @param index Number of index
 * @return Check data is removed or not
 */
template <typename T>
bool SinglyLinkedList<T>::Remove(int index) {
    try {
        // Throw exception when index is out of range in singly linked list
        if (Size() < index) {
            throw std::out_of_range("Index is out of range");
        }

        if (index == 0) {
            Pop();
        }
        else {
            // Delete node at the index in singly linked list
            int i = 1;
            for (Node<T>* pNode = _head->GetNext(); true; pNode = pNode->GetNext(), i++) {
                if (i == index) {
                    Node<T>* searched = pNode->GetNext();
                    pNode->SetNext(pNode->GetNext()->GetNext());
                    delete searched;
                    break;
                }
            }
        }

        return true;
    }
    catch (std::out_of_range& exception) {
        std::cout << " - Exception : " << exception.what() << std::endl;
    }

    return false;
}

/**
 * Search data in `Singly Linked List`
 * 
 * @param data Data to search
 * @return If data is found, returns index of node, else returns `-1`
 */
template <typename T>
int SinglyLinkedList<T>::Search(T data) {
    int index = 0;
    for (Node<T>* pNode = _head->GetNext(); pNode != nullptr; pNode = pNode->GetNext(), index++) {
        if (pNode->GetData() == data) {
            return index;
        }
    }

    return -1;
}

/**
 * @return Check linked list is empty or not
 */
template <typename T>
bool SinglyLinkedList<T>::IsEmpty() {
    return _head->GetNext() == nullptr;
}

/**
 * @return Size of nodes in `Singly Linked List`
 */
template <typename T>
int SinglyLinkedList<T>::Size() {
    int size = 0;
    for (Node<T>* pNode = _head->GetNext(); pNode != nullptr; pNode = pNode->GetNext()) {
        size++;
    }

    return size;
}

/**
 * Clear all nodes in `Singly Linked List`
 */
template <typename T>
void SinglyLinkedList<T>::Clear() {
    while (_head->GetNext() != nullptr) {
        Pop();
    }
}