#include <iostream>
#include "../Node.cpp"

using namespace std;
using namespace SinglyLinkedList;

template <typename T>
class LinkedList {
private:
    Node<T>* _head; // Head of singly linked list

public:
    /**
     * Default singly linked list constructor
     */
    LinkedList() : _head{new Node<T>()} {}

    // Abstract data type, ADT
    void push_front(T);
    bool pop_front();
    bool insert(int, T);
    bool remove(int);
    int search(T);
    bool empty();
    int size();
    void clear();
};

/**
 * Push front data in linked list
 * @tparam T : Data type
 * @param data : Added data
 */
template <typename T>
void LinkedList<T>::push_front(T data) {
    // Create new node
    Node<T>* newNode = new Node<T>(data, nullptr);

    // Singly linked list is empty
    if (empty()) {
        _head->setNext(newNode);
    }
    else {
        newNode->setNext(_head->getNext());
        _head->setNext(newNode);
    }
}

/**
 * Pop front data in singly linked list
 * @tparam T : Data type
 * @return Check data is pop or not
 */
template <typename T>
bool LinkedList<T>::pop_front() {
    try {
        // Throw exception when accessing null pointer
        if (empty()) {
            throw out_of_range("Linked list is empty.");
        }

        Node<T>* node = _head->getNext();
        if (size() == 1) {
            _head->setNext(nullptr);
        }
        else {
            _head->setNext(node->getNext());
        }

        // Delete first node in singly linked list
        delete node;

        return true;
    }
    catch (out_of_range& exception) {
        cout << " - Exception" << endl;
        cout << exception.what() << endl;
    }

    return false;
}

/**
 * Insert data into the specified index in linked list
 * @tparam T : Data type
 * @param index : Number of linked list index
 * @param data : Added data
 * @return Check data is inserted in linked list or not
 */
template <typename T>
bool LinkedList<T>::insert(int index, T data) {
    try {
        // Throw exception when index is out of range in linked list
        if (size() < index) {
            throw out_of_range("Index is out of range");
        }

        if (index == 0) {
            push_front(data);
        }
        else {
            // Create new node
            Node<T>* newNode = new Node<T>(data, nullptr);

            // Insert new node at the index in linked list
            int i = 1;
            for (Node<T>* pNode = _head->getNext(); true; pNode = pNode->getNext(), i++) {
                if (i == index) {
                    newNode->setNext(pNode->getNext());
                    pNode->setNext(newNode);
                    break;
                }
            }
        }

        return true;
    }
    catch (out_of_range& exception) {
        cout << " - Exception" << endl;
        cout << exception.what() << endl;
    }

    return false;
}

/**
 * Remove data into the specified index in linked list
 * @tparam T : Data type
 * @param index : Number of linked list
 * @return Check data is removed in linked list or not
 */
template <typename T>
bool LinkedList<T>::remove(int index) {
    try {
        // Throw exception when index is out of range in linked list
        if (size() < index) {
            throw out_of_range("Index is out of range");
        }

        if (index == 0) {
            pop_front();
        }
        else {
            // Delete node at the index in linked list
            int i = 1;
            for (Node<T>* pNode = _head->getNext(); true; pNode = pNode->getNext(), i++) {
                if (i == index) {
                    Node<T>* searched = pNode->getNext();
                    pNode->setNext(pNode->getNext()->getNext());
                    delete searched;
                    break;
                }
            }
        }

        return true;
    }
    catch (out_of_range& exception) {
        cout << " - Exception" << endl;
        cout << exception.what() << endl;
    }

    return false;
}

/**
 * Searching data in singly linked list
 * @tparam T : Data type
 * @param data : Data to search
 * @return If data is found, it returns index of node, and if not, it returns -1
 */
template <typename T>
int LinkedList<T>::search(T data) {
    int index = 0;
    for (Node<T>* pNode = _head->getNext(); pNode != nullptr; pNode = pNode->getNext(), index++) {
        if (pNode->getData() == data) {
            return index;
        }
    }

    return -1;
}

/**
 * Calculate size of linked list
 * @tparam T Data type
 * @return Number of linked list size
 */
template <typename T>
int LinkedList<T>::size() {
    int size = 0;
    for (Node<T>* pNode = _head->getNext(); pNode != nullptr; pNode = pNode->getNext()) {
        size++;
    }

    return size;
}

/**
 * Check linked list is empty
 * @tparam T : Data type
 * @return Linked list is empty or not
 */
template <typename T>
bool LinkedList<T>::empty() {
    return _head->getNext() == nullptr;
}

/**
 * Clear entire nodes in singly linked list
 * @tparam T : Data type
 */
template <typename T>
void LinkedList<T>::clear() {
    while (_head->getNext() != nullptr) {
        pop_front();
    }
}

int main() {
    LinkedList<int> linkedList = LinkedList<int>();

    bool isLoop = true;
    while (isLoop) {
        cout << "Data structure - Linked List(ADT)" << endl;
        cout << "(1). push_front()" << endl;
        cout << "(2). pop_front()" << endl;
        cout << "(3). insert()" << endl;
        cout << "(4). remove()" << endl;
        cout << "(5). search()" << endl;
        cout << "(6). empty()" << endl;
        cout << "(7). size()" << endl;
        cout << "(8). clear()" << endl;
        cout << " - Input" << endl;

        int index;
        cin >> index;

        int data;
        switch (index) {
            case 1:
                cout << " - Input" << endl;
                cin >> data;
                linkedList.push_front(data);
                break;
            case 2:
                linkedList.pop_front();
                break;
            case 3:
                cout << " - Input" << endl;
                cin >> index;
                cout << " - Input" << endl;
                cin >> data;
                linkedList.insert(index, data);
                break;
            case 4:
                cout << " - Input" << endl;
                cin >> index;
                linkedList.remove(index);
                break;
            case 5:
                cout << " - Input" << endl;
                cin >> data;
                cout << linkedList.search(data) << endl;
                break;
            case 6:
                cout << " - Output" << endl;
                cout << (linkedList.empty() ? "True" : "False") << endl;
                break;
            case 7:
                cout << " - Output" << endl;
                cout << linkedList.size() << endl;
                break;
            case 8:
                linkedList.clear();
                break;
            default:
                isLoop = false;
                break;
        }

        cout << endl;
    }
}