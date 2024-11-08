#include <iostream>

#include "singly_linked_list.hpp"
#include "linked_list\singly_linked_list\singly_linked_list.cpp"

int main() {
    SinglyLinkedList<int> linkedList = SinglyLinkedList<int>();

    bool isLoop = true;
    while (isLoop) {
        std::cout << "Data structure - Singly Linked List(ADT)" << std::endl;
        std::cout << "(1). Push data" << std::endl;
        std::cout << "(2). Pop data" << std::endl;
        std::cout << "(3). Insert data" << std::endl;
        std::cout << "(4). Remove data" << std::endl;
        std::cout << "(5). Search data" << std::endl;
        std::cout << "(6). Check linked list is empty" << std::endl;
        std::cout << "(7). Size" << std::endl;
        std::cout << "(8). Clear" << std::endl;
        std::cout << " - Input" << std::endl;

        int index;
        std::cin >> index;

        int data;
        switch (index) {
            case 1:
                std::cout << " - Input" << std::endl;
                std::cin >> data;
                linkedList.Push(data);
                break;
            case 2:
                linkedList.Pop();
                break;
            case 3:
                std::cout << " - Input" << std::endl;
                std::cin >> index;
                std::cout << " - Input" << std::endl;
                std::cin >> data;
                linkedList.Insert(index, data);
                break;
            case 4:
                std::cout << " - Input" << std::endl;
                std::cin >> index;
                linkedList.Remove(index);
                break;
            case 5:
                std::cout << " - Input" << std::endl;
                std::cin >> data;
                std::cout << linkedList.Search(data) << std::endl;
                break;
            case 6:
                std::cout << " - Output" << std::endl;
                std::cout << (linkedList.IsEmpty() ? "True" : "False") << std::endl;
                break;
            case 7:
                std::cout << " - Output" << std::endl;
                std::cout << linkedList.Size() << std::endl;
                break;
            case 8:
                linkedList.Clear();
                break;
            default:
                isLoop = false;
                break;
        }

        std::cout << std::endl;
    }
}