#include <iostream>

using namespace std;

template <typename T>
class SinglyLinkedList {
private:
    /**
     * Element of singly linked list
     */
    class Node {
    private:
        T     _data; // Data of node
        Node* _next; // Next linked node pointer

    public:
        /**
         * Default node constructor
         */
        Node() : _data{0}, _next{nullptr} {}

        /**
         * Node constructor to initialize node's fields
         * @param data : Data of node
         * @param next : Next linked node pointer
         */
        explicit Node(T data, Node* next) : _data{data}, _next{next} {}

        T getData() { return _data; }

        Node* getNext() { return _next; }
        void setNext(Node* next) { _next = next; }
    };

    Node* _head; // Head of singly linked list

public:
    /**
     * Default singly linked list constructor
     */
    SinglyLinkedList() : _head{nullptr} {}

    // Abstract data type, ADT
    void push_back(T data);
    bool insert(int index, T data);
    bool pop_back();
    bool remove(int index);
    int search(T data);
    bool empty();
    int size();
    void clear();
};

/**
 * Push back data in linked list
 * @tparam T : Data type
 * @param data : Added data
 */
template <typename T>
void SinglyLinkedList<T>::push_back(T data) {
    // Create new node
    Node* newNode = new Node(data, nullptr);

    if (empty()) {
        // Singly linked list is empty
        _head = newNode;
    }
    else {
        // Add new node at last in linked list
        for (Node* pNode = _head; true; pNode = pNode->getNext()) {
            if (pNode->getNext() == nullptr) {
                pNode->setNext(newNode);
                break;
            }
        }
    }
}

/**
 * Insert data into the specified index in linked list
 * @tparam T : Data type
 * @param index : Number of linked list index
 * @param data : Added data
 * @return Check data is inserted in linked list or not
 */
template <typename T>
bool SinglyLinkedList<T>::insert(int index, T data) {
    try {
        // Throw exception when index is out of range in linked list
        if (size() < index) {
            throw out_of_range("Index is out of range");
        }

        // Create new node
        Node* newNode = new Node(data, nullptr);

        if (index == 0) {
            // Index of linked list is equaled head
            newNode->setNext(_head);
            _head = newNode;
        }
        else {
            // Insert new node at the index in linked list
            int i = 0;
            for (Node* pNode = _head; true; pNode = pNode->getNext(), i++) {
                if (i == index - 1) {
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
 * Pop back data in singly linked list
 * @tparam T : Data type
 * @return Check data is pop or not
 */
template <typename T>
bool SinglyLinkedList<T>::pop_back() {
    try {
        // Throw exception when accessing null pointer
        if (empty()) {
            throw out_of_range("Linked list is empty.");
        }

        if (size() == 1) {
            // Delete node in head
            delete _head;
            _head = nullptr;
        }
        else {
            // Delete node at last in linked list
            for (Node *pNode = _head; true; pNode = pNode->getNext()) {
                if (pNode->getNext()->getNext() == nullptr) {
                    delete pNode->getNext();
                    pNode->setNext(nullptr);
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
bool SinglyLinkedList<T>::remove(int index) {
    try {
        // Throw exception when index is out of range in linked list
        if (size() < index) {
            throw out_of_range("Index is out of range");
        }

        Node* pNode;
        if (index == 0) {
            // Delete node in head
            pNode = _head->getNext();
            delete _head;
            _head = pNode;
        }
        else {
            // Delete node at the index in linked list
            int i = 1;
            for (pNode = _head; true; pNode = pNode->getNext(), i++) {
                if (i == index) {
                    Node* searched = pNode->getNext();
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
int SinglyLinkedList<T>::search(T data) {
    int index = 0;
    for (Node* pNode = _head; pNode != nullptr; pNode = pNode->getNext(), index++) {
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
int SinglyLinkedList<T>::size() {
    int size = 0;
    for (Node* pNode = _head; pNode != nullptr; pNode = pNode->getNext()) {
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
bool SinglyLinkedList<T>::empty() {
    return _head == nullptr;
}

/**
 * Clear entire nodes in singly linked list
 * @tparam T : Data type
 */
template <typename T>
void SinglyLinkedList<T>::clear() {
    Node* pNode;
    while (_head != nullptr) {
        pNode = _head->getNext();
        delete _head;
        _head = pNode;
    }
}

int main() {
    SinglyLinkedList<int> linkedList = SinglyLinkedList<int>();

    bool isLoop = true;
    while (isLoop) {
        cout << "Data structure - Singly Linked List(ADT)" << endl;
        cout << "(1). push_back()" << endl;
        cout << "(2). insert()" << endl;
        cout << "(3). pop_back()" << endl;
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
                linkedList.push_back(data);
                break;
            case 2:
                cout << " - Input" << endl;
                cin >> index;
                cout << " - Input" << endl;
                cin >> data;
                linkedList.insert(index, data);
                break;
            case 3:
                linkedList.pop_back();
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